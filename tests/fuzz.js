const {Pet, battle, store} = require("./helpers");
const fs = require("fs");
const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('teams.db');

db.run('CREATE TABLE IF NOT EXISTS teams (team TEXT PRIMARY KEY, turn INT, wins INT, loses INT, ties INT)');

function newTeam() {
    return {
        turn: 1,
        pets: [false,false,false,false,false],
        wins: 0,
        lives: 10,
    };
}

async function getOpponents(turn) {

    const teams = await new Promise((resolve) => db.all(`select team from teams WHERE turn=? ORDER BY RANDOM() LIMIT 100`, [turn], (err, rows) => {
        if (rows === undefined) return resolve(false);
        resolve(rows);
    }));

    if (!teams) return false;

    return teams.map((row) => row.team.split(",").map((p) => {
        if (p === "false") {
            return Pet(0);
        } else {
            return Pet.from(parseInt(p));
        }
    }));
}

async function doRandomStuff(team) {
    let coins = 10;

    while (coins > 0) {
        const avail = await store(team.turn);
        // console.log(avail.map((pet) => pet && pet.build()));
        //
        // console.log(`coins ${coins}`)
        if (coins >= 3 && Math.random() < 0.2) {
            const idx = Math.floor(Math.random() * 5);
            const pet = team.pets[idx];
            if (pet) {
                // console.log(`- SELL ${pet.id()} for ${pet.experience()}`);
                team.pets[idx] = false;
                coins += 1;
            }
        }

        avail.forEach((pet, index) => {
            team.pets.forEach((tpet) => {
                if (!tpet) return;
                if (tpet.experience() < 5 && pet && tpet && tpet.id() === pet.id()) {
                    if (coins >= 3 && Math.random() > 0.25) {
                        // console.log(`- EXP ${pet.id()} ${coins}`);
                        tpet.withExperience(tpet.experience() + 1);
                        tpet.withDamage(tpet.damage() + 1);
                        tpet.withHealth(tpet.health() + 1);
                        coins -= 3;
                        avail[index] = false;
                    }
                }
            });
        })

        for (const pet of team.pets) {
            if (!pet) {
                for (let index in [0, 1, 2, 3, 4]) {
                    let spet = avail[index];
                    if (spet !== false && spet.id() > 0) {
                        if (coins >= 3 && Math.random() > 0.25) {
                            // console.log(`- BUY ${spet.id()} ${coins}`);
                            team.pets[team.pets.indexOf(pet)] = spet;
                            coins -= 3;

                            avail[index] = false;
                            if (Math.random() > 0.5) {
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }

        team.pets.forEach((pet) => {
            if (pet != false && pet.id() == 0) {
                throw "Zero pet";
            }
        });
        coins -= 1;
    }
    // throw "hi"
}

(async () => {
    // const toprint = [220020305,370000102,360030505,360020404,360010303];
    // toprint.forEach((num) => console.log( Pet.from(num).toString()));
    // return;

    const iter = parseInt(process.argv[2]);

    for (let i=0; i<iter;i++) {
        const team = newTeam();

        while (team.lives > 0 && team.wins < 10) {
            // console.log(`[[ TURN ${team.turn} ]]`);

            await doRandomStuff(team);
            // team.pets.forEach((pet) => console.log(pet.toString()));

            const oppos = await getOpponents(team.turn);

            let i = 0;
            // console.log(oppos.length);
            let turnWins = 0;
            let turnLoss = 0;

            const key = team.pets.map((pet) => pet && pet.build()).join(",");

            await new Promise((resolve, reject) => {
                db.run('INSERT OR IGNORE INTO teams (team, turn) VALUES (?, ?)', [key, team.turn], function (err) {
                    if (err) {
                        console.log(`SQLite returned err`);
                        reject(err)
                    }
                    resolve(this.lastID);
                });
            });

            for (const oppo of oppos) {
                // console.log(`Turn ${team.turn} round ${i++}`);
                let logs = [];

                if (oppo) {
                    logs = await battle(
                        team.pets,
                        oppo
                    );
                }

                if (!oppo || logs[logs.length - 1] === "[Loss]") {
                    // console.log("~~ LOSS ~~");
                    turnLoss ++;
                    if (oppo) {
                        await recordLoss(team.pets, team.turn);
                        await recordWin(oppo, team.turn);
                    }
                } else if (logs[logs.length - 1] === "[Win]") {
                    turnWins++;
                    // console.log("~~ WIN ~~");
                    await recordWin(team.pets, team.turn);
                    await recordLoss(oppo, team.turn);
                } else if (logs[logs.length - 1] === "[Tie]") {
                    await recordTie(team.pets, team.turn);
                    await recordTie(oppo, team.turn);
                } else {
                    // console.log(logs);
                    throw "Invalid result, crash?"
                }

                if (team.lives === 0) {
                    // console.log(`Team over w/ ${team.wins} wins`);
                }
                if (team.wins === 10) {
                    // console.log(`Team win w/ ${team.lives} hearts`);
                }
            }


            console.log(turnLoss, turnWins);
            if (!oppos.length || turnLoss > turnWins) {
                team.lives -= 1;
            } else if (turnWins > turnLoss) {
                team.wins += 1;
            }
            team.turn++;
        }
        console.log(i);
    }
    db.close();
})().catch((err) => {
    console.log(`Crash ${err}`)
});

async function recordLoss(pets, turn) {
    const key = pets.map((pet) => pet && pet.build()).join(",");

    // console.log("loss key", key);
    await new Promise((resolve, reject) => {
        db.run('UPDATE teams SET loses = COALESCE(loses, 0) + 1 WHERE team = ? and turn = ?', [key, turn], function (err) {
            if (err) {
                return reject(err);
            }
            // console.log(`Row has been updated.`);
            resolve();
        });
    });
}

async function recordWin(pets, turn) {
    const key = pets.map((pet) => pet && pet.build()).join(",");
    // console.log("win key", key);
    await new Promise((resolve, reject) => {
        db.run('UPDATE teams SET wins = COALESCE(wins, 0) + 1 WHERE team = ? and turn = ?', [key, turn], function (err) {
            if (err) {
                return reject(err);
            }
            // console.log(`Row has been updated.`);
            resolve();
        });
    });
}

async function recordTie(pets, turn) {
    const key = pets.map((pet) => pet && pet.build()).join(",");

    // console.log("tie key", key);
    await new Promise((resolve, reject) => {
        db.run('UPDATE teams SET ties = COALESCE(ties, 0) + 1 WHERE team = ? and turn = ?', [key, turn], function (err) {
            if (err) {
                return reject(err);
            }
            // console.log(`Row has been updated.`);
            resolve();
        });
    });
}
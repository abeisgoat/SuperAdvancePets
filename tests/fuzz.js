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

async function getOpponent(turn) {

    const team = await new Promise((resolve) => db.get(`select team from teams WHERE turn=? ORDER BY RANDOM() LIMIT 1`, [turn], (err, row) => {
        if (row === undefined) return resolve(false);
        resolve(row.team);
    }));

    if (!team) return false;

    return team.split(",").map((p) => {
        if (p === "false") {
            return Pet(0);
        } else {
            return Pet.from(parseInt(p));
        }
    });
}

async function doRandomStuff(team) {
    let coins = 10;

    while (coins > 0) {
        const avail = await store(team.turn);

        avail.forEach((pet, index) => {
            team.pets.forEach((tpet) => {
                if (!tpet) return;
               if (tpet.experience() < 5 && pet && tpet && tpet.id() === pet.id()) {
                   console.log(`- EXP ${pet.id()}`);
                   tpet.withExperience(tpet.experience() + 1);
                   tpet.withDamage(tpet.damage() + 1);
                   tpet.withHealth(tpet.health() + 1);
                   coins -= 3;
                   avail[index] = false;
               }
            });
        })

        for (const pet of team.pets) {
            if (!pet) {
                for (spet of avail) {
                    if (spet !== false) {
                        team.pets[team.pets.indexOf(pet)] = spet;
                        coins -= 3;
                        break;
                    }
                }
                break;
            }
        }

        if (Math.random() < 0.2 && coins > 3) {
            const idx = Math.floor(Math.random() * 5);
            const pet = team.pets[idx];
            team.pets[idx] = false;
            if (pet) {
                console.log(`- SELL ${pet.id()} for ${pet.experience()}`);
                coins += 1;
            }
        }

        coins -= 1;
    }
}

(async () => {
    // const toprint = [220020305,370000102,360030505,360020404,360010303];
    // toprint.forEach((num) => console.log( Pet.from(num).toString()));
    // return;
    const team = newTeam();

    while (team.lives > 0 && team.wins < 10) {
        console.log(`[[ TURN ${team.turn} ]]`);

        await doRandomStuff(team);
        team.pets.forEach((pet) => console.log(pet.toString()));

        const oppo = await getOpponent(team.turn);

        let logs = [];
        if (oppo) {
            logs = await battle(
                team.pets,
                oppo
            );
        }

        const key = team.pets.map((pet) => pet && pet.build()).join(",");

        await new Promise((resolve, reject) => {
            db.run('INSERT OR IGNORE INTO teams (team, turn) VALUES (?, ?)', [key, team.turn], function(err) {
                if (err) {
                    reject(err)
                }
                resolve(this.lastID);
            });
        });

        if (!oppo || logs[logs.length-1] === "[Loss]") {
            console.log("~~ LOSS ~~");
            team.lives -= 1;
            if (oppo) {
                await recordLoss(team.pets, team.turn);
                await recordWin(oppo, team.turn);
            }
        } else if (logs[logs.length-1] === "[Win]") {
            team.wins++;
            console.log("~~ WIN ~~");
            await recordWin(team.pets, team.turn);
            await recordLoss(oppo, team.turn);
        } else if (logs[logs.length-1] === "[Tie]") {
            await recordTie(team.pets, team.turn);
            await recordTie(oppo, team.turn);
        } else {
            console.log(logs);
            throw "Invalid result, crash?"
        }

        team.turn++;

        if (team.lives === 0) {
            console.log(`Team over w/ ${team.wins} wins`);
        }
        if (team.wins === 10) {
            console.log(`Team win w/ ${team.lives} hearts`);
        }
    }
    db.close();
})();

async function recordLoss(pets, turn) {
    const key = pets.map((pet) => pet && pet.build()).join(",");

    await new Promise((resolve, reject) => {
        db.run('UPDATE teams SET loses = COALESCE(loses, 0) + 1 WHERE team = ? and turn = ?', [key, turn], function (err) {
            if (err) {
                return reject(err);
            }
            console.log(`Row has been updated.`);
            resolve();
        });
    });
}

async function recordWin(pets, turn) {
    const key = pets.map((pet) => pet && pet.build()).join(",");

    await new Promise((resolve, reject) => {
        db.run('UPDATE teams SET wins = COALESCE(wins, 0) + 1 WHERE team = ? and turn = ?', [key, turn], function (err) {
            if (err) {
                return reject(err);
            }
            console.log(`Row has been updated.`);
            resolve();
        });
    });
}

async function recordTie(pets, turn) {
    const key = pets.map((pet) => pet && pet.build()).join(",");

    console.log(key);
    await new Promise((resolve, reject) => {
        db.run('UPDATE teams SET ties = COALESCE(ties, 0) + 1 WHERE team = ? and turn = ?', [key, turn], function (err) {
            if (err) {
                return reject(err);
            }
            console.log(`Row has been updated.`);
            resolve();
        });
    });
}
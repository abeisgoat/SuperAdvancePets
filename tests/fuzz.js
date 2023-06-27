const {Pet, battle, store} = require("./helpers");
const fs = require("fs");

function newTeam() {
    return {
        turn: 1,
        pets: [false,false,false,false,false],
        wins: 0,
        lives: 10,
    };
}

async function getOpponent(turn) {
    const filename = `db/turn_${turn}.txt`;
    if (!fs.existsSync(filename)) return false;

    const turnfile = fs.readFileSync(filename).toString().trim().split("\n");
    const line = Math.floor(Math.random() * turnfile.length);

    const team = turnfile[line].split(":")[0].split(",").map((p) => {
        console.log("p", p);
        if (p === "false") {
            return Pet(0);
        } else {
            return Pet.from(parseInt(p));
        }
    });

    return team;
}

async function doRandomStuff(team) {
    let coins = 10;

    while (coins > 0) {
        const avail = await store(team.turn);

        avail.forEach((pet) => {
            team.pets.forEach((tpet) => {
                if (!tpet) return;
               if (tpet.experience() < 5 && tpet.id() === pet.id()) {
                   console.log(`- EXP ${avail[0].info().id}`);
                   tpet.withExperience(tpet.experience() + 1);
                   tpet.withDamage(tpet.damage() + 1);
                   tpet.withHealth(tpet.health() + 1);
                   coins -= 3;
               }
            });
        })

        for (const pet of team.pets) {
            if (!pet) {
                console.log(`- BUY ${avail[0].info().id}`);
                team.pets[team.pets.indexOf(pet)] = avail[0];
                coins -= 3;
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
    const team = newTeam();

    while (team.lives > 0 && team.wins < 10) {
        console.log(`[[ TURN ${team.turn} ]]`);

        await doRandomStuff(team);
        team.pets.forEach((pet) => console.log(pet.toString()));
        team.turn++;

        const oppo = await getOpponent(team.turn);
        let logs = [];
        if (oppo) {
            logs = await battle(
                team.pets,
                oppo
            );
        }

        if (!oppo || logs[logs.length-1] === "[Loss]") {
            console.log("~~ LOSS ~~");
            team.lives -= 1;
        } else if (logs[logs.length-1] === "[Win]") {
            team.wins++;
            console.log("~~ WIN ~~");
        } else if (logs[logs.length-1] === "[Tie]") {
            console.log("~~ TIE ~~");
        } else {
            console.log(logs);
            throw "Invalid result, crash?"
        }

        if (team.turn > 1) {
            fs.appendFileSync(`db/turn_${team.turn-1}.txt`, team.pets.map((pet) => pet && pet.build()).join(",") + `:${team.wins}:${team.lives}\n`);
        }

        if (team.lives === 0) {
            console.log(`Team over w/ ${team.wins} wins`);
        }
        if (team.wins === 10) {
            console.log(`Team win w/ ${team.lives} hearts`);
        }
    }
})();
const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('teams.db');

const groups = {};
db.all("select team, turn from teams;", (err, rows) => {
    for (const row of rows) {
        const group = groups[row.turn] || [];
        group.push(row.team.split(",").map((f) => f == "false" ? 0 : parseInt(f)));
        groups[row.turn] = group;
    }

    console.log(`// Generated: Do not edit.
#include <stdlib.h>
#include <tonc_types.h>
#include "battle.h"`);
    for (const key of Object.keys(groups)) {
        const len = groups[key].length;
        console.log(`// ${key} -> ${len} teams`);
        console.log(`EWRAM_DATA const int opponentsTurn${key}Length = ${len};`);
        console.log(`EWRAM_DATA const int opponentsTurn${key}[${len}][5] = {`);

        groups[key].forEach((team) => {
           console.log(`    {${team.join(",")}},`);
        });

        console.log("};");
    }

    console.log("void loadOpponentTeam(int turn) {")
    console.log("switch (turn) {")
    let lastKey;
    for (const key of Object.keys(groups)) {
        console.log(`    case ${key}:
        prepareEnemyTeam(opponentsTurn${key}[rand() % opponentsTurn${key}Length]);
        break;
        `);
        lastKey = key;
    }

    console.log(`    default:
        prepareEnemyTeam(opponentsTurn${lastKey}[rand() % opponentsTurn${lastKey}Length]);
        break;
        `);
    console.log("}}");
});
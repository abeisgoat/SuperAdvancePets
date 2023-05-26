const { spawn } = require("child_process");
const { ls, cd, cat } = require("shelljs");

exports.battle = function battle(us, them) {
    const binaryPath = "../SuperAdvancePetsCLI";
    const arguments = [
        us.map((pet) => pet.build()).join(","),
        them.map((pet) => pet.build()).join(","),
    ];
    const stdout = [];
    const stderr = [];
    return new Promise((resolve, reject) => {
        const childProcess = spawn(binaryPath, arguments);

        childProcess.stdout.on("data", (data) => {
            stdout.push(data.toString());
        });

        childProcess.stderr.on("data", (data) => {
            stderr.push(data.toString());
        });

        childProcess.on("close", (code) => {
            if (code === 0) {
                resolve(stdout.join("").trim().split("\n"));
            } else {
                reject(stderr.join("").trim().split("\n"));
            }
        });
    });
}

function padInt(i) {
    if (i < 10) {
        return `0${i}`;
    } else {
        return `${i}`;
    }
}
exports.Pet = function Pet(name) {
    const animal = {
        id: 0,
        damage: 0,
        health: 0,
        experience: 0,
        heldItem: 0,
    };

    const match = ls("../engine/pet_impl/*.h").filter(
        (impl) => impl.indexOf(name.toLowerCase()) >= 0
    );
    if (!match.length) {
        throw `Can't find pet with name ${name}`;
    }
    const impl = cat(match[0]).stdout;
    const idLine = impl
        .split("\n")
        .filter((line) => line.trim().startsWith(".id"))[0]
        .trim();

    const id = parseInt(idLine.match(/([0-9]+)/)[0], 10);
    animal.id = id;

    const self = {
        withHealth(health) {
            animal.health = health;
            return self;
        },
        withDamage(damage) {
            animal.damage = damage;
            return self;
        },
        withItem(item) {
            animal.item = item;
            return self;
        },
        withExperience(exp) {
            animal.exp = exp;
            return self;
        },
        build() {
            const pet = [
                padInt(animal.id),
                padInt(animal.heldItem),
                animal.experience,
                padInt(animal.damage),
                padInt(animal.health),
            ].join("");
            return pet;
        },
    };

    return self;
}
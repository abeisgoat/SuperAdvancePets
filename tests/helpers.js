const { spawn } = require("child_process");
const { ls, cd, cat } = require("shelljs");

exports.battle = function battle(us, them) {
    const binaryPath = "../SuperAdvancePetsCLI";
    const arguments = [
        "battle",
        us.filter(p => p).map((pet) => pet.build()).join(","),
        them.filter(p => p).map((pet) => pet.build()).join(","),
    ];
    console.log(binaryPath, arguments);
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

exports.store = function store(turn) {
    const binaryPath = "../SuperAdvancePetsCLI";
    const arguments = [
        "store",
        turn,
        Math.floor(Math.random() * 1000000)
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
                resolve(stdout.join("").trim().split(",").filter(v => v).map((ident) => {
                    return exports.Pet.from(ident)
            }));
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

exports.getImpl = function getImpl(name) {

    if (name === 0) {
        return false;
    }

    const match = ls("../engine/pet_impl/*.h", "../engine/food_impl/*.h").filter(
        (impl) => {
            return typeof name == "string" ?
                impl.indexOf(name.toLowerCase()) >= 0 : impl.match(new RegExp(`/${name}_`))
        }
    );

    if (!match.length) {
        throw `Can't find pet with name ${name}`;
    }
    return  cat(match[0]).stdout;
}

exports.Pet = function Pet(identifier) {
    const animal = {
        id: 0,
        damage: 0,
        health: 0,
        experience: 0,
        heldItem: 0,
    };


    const impl = exports.getImpl(identifier);
    let id=0,name="Empty";

    if (impl) {
        const idLine = impl
            .split("\n")
            .filter((line) => line.trim().startsWith(".id"))[0]
            .trim();

        id = parseInt(idLine.match(/([0-9]+)/)[0], 10);

        const nameLine = impl
            .split("\n")
            .filter((line) => line.trim().startsWith(".name"))[0]
            .trim();
        name = nameLine.split("=")[1].trim().slice(1, -2);
    }


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
            animal.experience = exp;
            return self;
        },
        info() {
            return animal
        },
        id() {
            return animal.id
        },
        experience() {
            return animal.experience;
        },
        health() {
            return animal.health;
        },
        damage() {
            return animal.damage;
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
        toString() {

            if (id == 0) {
                return ("Empty");
            } else if (id < 100) {
                return (`${id} - ${name} @ ${animal.damage}/${animal.health} w/ ${animal.heldItem}`);
            } else {
                return (`${id} - ${name}`);
            }
        }
    };

    return self;
}

exports.Pet.from = function PetFrom(num) {
    const defence = num % 100;
    const defenseOffset = (defence * 1);
    const attack = ((num % 10000) - defenseOffset) / 100;
    const attackOffset = (attack * 100);
    const experience = ((num % 100000) - attackOffset - defenseOffset) / 10000;
    const experienceOffset = experience * 10000;
    const heldItem = ((num % 10000000) - attackOffset - defenseOffset - experienceOffset) / 100000;
    const heldItemOffset = heldItem * 100000;
    const id = (num - attackOffset -defenseOffset - experienceOffset - heldItemOffset) / 10000000;

    return exports.Pet(id).withItem(heldItem).withHealth(defence).withDamage(attack).withExperience(experience);
}
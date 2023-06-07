const chai = require("chai").assert;
const {Pet, battle} = require("./helpers");

console.log([
    Pet("Monkey")
        .withHealth(5)
        .withDamage(6)
        .withExperience(5),
    Pet("Bison")
        .withHealth(2)
        .withDamage(2)
        .withExperience(3),
    Pet("Giraffe")
        .withHealth(3)
        .withDamage(3)
        .withExperience(2),
    Pet("Peacock")
        .withHealth(8)
        .withDamage(10)
        .withExperience(5),
    Pet("Crocodile")
        .withHealth(6)
        .withDamage(5)
        .withExperience(5),

].map((a) => a.build()).map((v) => parseInt(v)))
describe("SuperAdvancePets Engine", () => {
    it("Equal ants tie", async () => {
        const log = await battle(
          [
              Pet("Ant")
                  .withHealth(10)
                  .withDamage(10)
          ],
          [
              Pet("Ant")
                  .withHealth(10)
                  .withDamage(10)
          ]
        );

        chai.equal(log[log.length - 1], "[Tie]");
    });
    it("Big ant wins versus lil ant", async () => {
        const log = await battle(
            [
              Pet("Ant")
                  .withHealth(11)
                  .withDamage(10)
            ],
            [
              Pet("Ant")
                  .withHealth(10)
                  .withDamage(10)
            ]
        );

        chai.equal(log[log.length - 1], "[Win]");
    });
    it("Three small ants beat one big ant", async () => {
        const log = await battle(
            [
                Pet("Ant")
                    .withHealth(1)
                    .withDamage(1),
                Pet("Ant")
                    .withHealth(5)
                    .withDamage(6),
                Pet("Ant")
                    .withHealth(5)
                    .withDamage(6),
            ],
            [
                Pet("Ant")
                    .withHealth(10)
                    .withDamage(10)
            ]
        );

        chai.equal(log[log.length - 1], "[Win]");
    });

    it("Cricket spawns zombie cricket", async () => {
        const log = await battle(
            [
                Pet("Cricket")
                    .withHealth(2)
                    .withDamage(2),
            ],
            [
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2),
            ]
        );
        chai.equal(log[log.length - 1], "[Win]");
    });

    it("Dog gains stats when friendly spawned", async () => {
        const log = await battle(
            [
                Pet("Dog")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Cricket")
                    .withHealth(2)
                    .withDamage(2),
            ],
            [
                Pet("Cricket")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Cricket")
                    .withHealth(2)
                    .withDamage(2),
            ]
        );
        const stats = log.filter((line) => line.indexOf('FIGHT! Dog [')+1)[0].match(/\[.+?\]/)[0];

        chai.equal(stats, "[+2/+3]");
        chai.equal(log[log.length - 1], "[Tie]");
    });

    it("Shark gains stats on friendly faints", async () => {
        const log = await battle(
            [
                Pet("Shark")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
            ],
            [
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
            ]
        );

        const stats = log.filter((line) => line.indexOf('FIGHT! Shark [')+1)[0].match(/\[.+?\]/)[0];

        chai.equal(stats, "[+6/+10]");
        chai.equal(log[log.length - 1], "[Win]");
    });

    it("Shark friend faint doesn't double trigger when triggers looped.", async () => {
        const log = await battle(
            [
                Pet("Shark")
                    .withHealth(6)
                    .withDamage(2),
                Pet("Snail")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Turtle")
                    .withHealth(4)
                    .withDamage(5),
            ],
            [
                Pet("Mosquito")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(1),
                Pet("Pig")
                    .withHealth(3)
                    .withDamage(1),
            ]
        );

        // console.log(log);
        const sharkTriggers = log.filter((line) => line.indexOf('Activated Shark trigger')+1).length

        chai.equal(sharkTriggers, 1);
        chai.equal(log[log.length - 1], "[Win]");
    });

    it("Turtle gives items behind", async () => {
        const log = await battle(
            [
                Pet("Shark")
                    .withHealth(16)
                    .withDamage(16),
            ],
            [
                Pet("Turtle")
                    .withHealth(4)
                    .withDamage(4)
                    .withExperience(3),
                Pet("Rabbit")
                    .withHealth(4)
                    .withDamage(4),
                Pet("Rabbit")
                    .withHealth(4)
                    .withDamage(4),
            ]
        );

        chai.equal(log[log.length - 1], "[Loss]");
    });


    it("Blowfish beats 3 ants in 2 rounds.", async () => {
        const log = await battle(
            [
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2),
            ],
            [
                Pet("Blowfish")
                    .withHealth(10)
                    .withDamage(1)
            ]
        );

        chai.equal(log.filter((line) => line.indexOf("Round over")+1).length, 2);
        chai.equal(log[log.length - 1], "[Loss]");
    });

    it("Dolphin beats 2 ants in 1 rounds.", async () => {
        const log = await battle(
            [
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2),
            ],
            [
                Pet("Dolphin")
                    .withHealth(10)
                    .withDamage(1)
            ]
        );

        chai.equal(log.filter((line) => line.indexOf("Round over")+1).length, 2);
        chai.equal(log[log.length - 1], "[Loss]");
    });

    it("Animals cleared after Peacock", async () => {
        const log = await battle(
            [
                Pet("Duck")
                    .withHealth(1)
                    .withDamage(3),
                Pet("Peacock")
                    .withHealth(2)
                    .withDamage(5),
                Pet("Flamingo")
                    .withHealth(3)
                    .withDamage(1),
                Pet("Otter")
                    .withHealth(2)
                    .withDamage(3),
            ],
            [
                Pet("Beaver")
                    .withHealth(2)
                    .withDamage(2),
                Pet("Ant")
                    .withHealth(2)
                    .withDamage(2)
            ]
        );
        chai.equal(log[log.length - 1], "[Win]");
    });
});

function deserialize (num) {

    console.log(num);
    const defence = num % 100;
    const defenseOffset = (defence * 1);
    const attack = ((num % 10000) - defenseOffset) / 100;
    const attackOffset = (attack * 100);
    const experience = ((num % 100000) - attackOffset - defenseOffset) / 10000;
    const experienceOffset = experience * 10000
    const heldItem = ((num % 10000000) - attackOffset, defenseOffset, experienceOffset) / 100000;
    const heldItemOffset = heldItem * 100000
    const id = (num - attackOffset -defenseOffset - experienceOffset - heldItemOffset) / 10000000;

    console.table({
        id, heldItem, experience, attack, defence
    })
}
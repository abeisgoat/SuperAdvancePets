const chai = require("chai").assert;
const {Pet, battle} = require("./helpers");

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

        deserialize(Pet("Cricket")
            .withHealth(2)
            .withDamage(2).build())
        console.log(log);
        chai.equal(log[log.length - 1], "[Win]");
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
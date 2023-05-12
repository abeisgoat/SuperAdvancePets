const api = require("./api.json")
const fs = require("fs");

const c_file = `
#include "../globals.h"
#include <stdio.h>

// TODO: Implement {{NAME}} {{TRIGGER}}
void {{LNAME}}Trigger{{TRIGGER}}(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated {{NAME}} trigger {{TRIGGER}}");
}
`

const h_file = `#include "../pets.h"

const struct PetText {{NAME}}Text = {
        .name = "{{NAME}}",
        .abilities = {
                "{{ABILITY_1}}",
                "{{ABILITY_2}}",
                "{{ABILITY_2}}"},
};

struct Pet {{NAME}} = {
        .id =  {{ID}},
        .attack =  {{ATTACK}},
        .defence =  {{DEFENSE}},
        .tier = {{TIER}}
};
void {{LNAME}}Trigger{{TRIGGER}}(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);`

const petNames = Object.keys(api.pets);
petNames.sort();
let ID = 0;
let headers = [];
petNames.forEach((petName) => {
  const pet = api.pets[petName];

  if (pet.packs[0] !== "StandardPack") return;
  const NAME = pet.name;
  const LNAME = pet.name.toLowerCase();

  const ABILITY_1 = pet.level1Ability?.description || "";
  const ABILITY_2 = pet.level2Ability?.description || "";
  const ABILITY_3 = pet.level3Ability?.description || "";

  const ATTACK = pet.baseAttack;
  const DEFENSE = pet.baseHealth;
  const TIER = pet.tier;
  const TRIGGER = pet.level1Ability?.trigger || "NoOp";
  ID++;

  const cfile = c_file
      .replace(/\{\{NAME}}/g, NAME)
      .replace(/\{\{LNAME}}/g, LNAME)
      .replace(/\{\{TRIGGER}}/g, TRIGGER);

  const hfile = h_file
      .replace(/\{\{NAME}}/g, NAME)
      .replace(/\{\{ID}}/g, ID)
      .replace(/\{\{LNAME}}/g, LNAME)
      .replace(/\{\{TRIGGER}}/g, TRIGGER)
      .replace(/\{\{ABILITY_1}}/g, ABILITY_1)
      .replace(/\{\{ABILITY_2}}/g, ABILITY_2)
      .replace(/\{\{ABILITY_3}}/g, ABILITY_3)
      .replace(/\{\{ATTACK}}/g, ATTACK)
      .replace(/\{\{DEFENSE}}/g, DEFENSE)
      .replace(/\{\{TIER}}/g, TIER)

  fs.writeFileSync(`pet_impl/${ID}_${LNAME}_impl.c`, cfile);
  fs.writeFileSync(`pet_impl/${ID}_${LNAME}_impl.h`, hfile);
  headers.push(`pet_impl/${ID}_${LNAME}_impl.h`);
});

const itemNames = Object.keys(api.foods);
itemNames.sort();
ID = 100;
itemNames.forEach((petName) => {
  const pet = api.foods[petName];
  console.log(pet)

  if (pet.packs[0] !== "StandardPack") return;
  const NAME = pet.name;
  const LNAME = pet.name.toLowerCase();

  const ABILITY_1 = pet.ability?.description || "";
  const ABILITY_2 = pet.level2Ability?.description || "";
  const ABILITY_3 = pet.level3Ability?.description || "";

  const ATTACK = 0;
  const DEFENSE = 0;
  const TIER = pet.tier;
  const TRIGGER = pet.ability.trigger || "NoOp";
  ID++;

  const cfile = c_file
      .replace(/\{\{NAME}}/g, NAME)
      .replace(/\{\{LNAME}}/g, LNAME)
      .replace(/\{\{TRIGGER}}/g, TRIGGER);

  const hfile = h_file
      .replace(/\{\{NAME}}/g, NAME)
      .replace(/\{\{ID}}/g, ID)
      .replace(/\{\{LNAME}}/g, LNAME)
      .replace(/\{\{TRIGGER}}/g, TRIGGER)
      .replace(/\{\{ABILITY_1}}/g, ABILITY_1)
      .replace(/\{\{ABILITY_2}}/g, ABILITY_2)
      .replace(/\{\{ABILITY_3}}/g, ABILITY_3)
      .replace(/\{\{ATTACK}}/g, ATTACK)
      .replace(/\{\{DEFENSE}}/g, DEFENSE)
      .replace(/\{\{TIER}}/g, TIER)
  console.log(cfile);
  console.log(hfile);
  fs.writeFileSync(`food_impl/${ID}_${LNAME}_impl.c`, cfile);
  fs.writeFileSync(`food_impl/${ID}_${LNAME}_impl.h`, hfile);
  headers.push(`food_impl/${ID}_${LNAME}_impl.h`);
});

const impl_h = `#ifndef SUPERADVANCEPETS_IMPL_H
#define SUPERADVANCEPETS_IMPL_H
${headers.map((header)=> {
  return `#include "${header}";`
}).join("\n")}
#endif`
fs.writeFileSync("impl.h", impl_h);
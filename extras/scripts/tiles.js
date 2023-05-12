const api = require("./api.json");

const petNames = Object.keys(api.pets);
petNames.sort();
let id=0;
petNames.forEach((petName) => {
  pet = api.pets[petName];
  if (pet.packs[0] !== "StandardPack") return;
  id++;
  console.log(`case ${id}:
            memcpy(&tile_mem[4][memPos], ${pet.name.toLowerCase().replace(" ", "")}Tiles, 160);
            break;`);
});

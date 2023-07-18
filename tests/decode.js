const {Pet} = require("./helpers");

process.argv[2].split(",").map((p) => p != "false" && Pet.from(parseInt(p))).forEach((pet) => {
  console.log(pet.toString());
});

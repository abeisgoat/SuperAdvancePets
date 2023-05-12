const api = require("./api.json");

const petNames = Object.keys(api.foods);
petNames.sort();
petNames.forEach((petName) => {
  petName = api.foods[petName].name;
  console.log(`registerFood(${petName}.id, &${petName}, &${petName}Text);`);
});

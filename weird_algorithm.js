const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function weird_algorithm(input, result) {
  result.push(input);

  if (input == 1) {
    return result;
  }

  if (input % 2 == 0) {
    return weird_algorithm(input / 2, result);
  }

  return weird_algorithm(3 * input + 1, result);
}

rl.question('', param => {
  console.log(weird_algorithm(parseInt(param), []).join(" "));
})

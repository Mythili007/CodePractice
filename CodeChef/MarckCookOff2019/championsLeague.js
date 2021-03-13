const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  })
  
  readline.question(t, (name) => {
    console.log(`Hi ${name}!`)
    readline.close()
  })
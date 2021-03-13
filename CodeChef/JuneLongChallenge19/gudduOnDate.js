process.stdin.resume();
process.stdin.setEncoding('utf8');

// declare global variables
var input_stdin = "";
var chunks = "";
var input_currentline = 0;

// standard input is stored into input_stdin
process.stdin.on('data', function (data) {
    input_stdin += data;
});

// standard input is done and stored into an array
process.stdin.on('end', function () {
    chunks = input_stdin.split('\n');
    start();
});

var _index = 0;

function nextInput(isNum = false) {
    return isNum ? parseInt(chunks[_index++]) : chunks[_index++];
}

function start() {
    var t = nextInput(true);
    for (var i = 0; i < t; i++) {
        _main();
    }
}

function sumOfDigits(num) {
    var rem = 0,
        sum = 0;
    while (num > 1) {
        rem = num % 10;
        sum += rem;
        num = num / 10;
    }
    return sum;
}

function _main() {
    var n = nextInput(true);
    console.log("TCL: function_main -> n", n)
    var num = 18446744073709551615, sum=0;
    var arr = [];
    for (var i = 1; i <= num; i++) {
        sum = sumOfDigits(i);
        if(sum%10===0){
            arr.push(i);
        }
    }
    console.log("**************** arr: ", arr);
}
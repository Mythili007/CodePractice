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

function _main() {
    var n = nextInput(true);
    var sum = 0,
        grade = [],
        res, fullMarksCount = 0, inp;
    for (var i = 0; i < n; i++) {
        inp = nextInput(true);
        grade.push(inp);
        sum += grade[i];
		console.log("TCL: function_main -> sum", sum)
    }

    if (parseFloat(sum / n) >= 4) {
        for (var i = 0; i < n; i++) {
            if (grade[i] < 3) {
                res = "No";
                return false;
            }

            if (grade[i] === 5) {
                fullMarksCount++;
            }
        }
    } else {
        res = "No";
    }

    if (fullMarksCount >= 1 && res !== "No") {
        console.log("Yes");
    } else {
        console.log("No");
    }
}
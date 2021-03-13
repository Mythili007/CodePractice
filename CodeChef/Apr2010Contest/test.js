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
	console.log("TCL: function_main -> n", n)
    var a = [],
        firstName = [],
        lastName = [];
    for (var i = 0; i < n; i++) {
        var _string = nextInput();
        a.push(0);

        firstName.push(_string.split(" ")[0]);
        lastName.push(_string.split(" ")[1]);
    }

    for (var j = 0; j < n; j++) {
        for (var k = 0; k < n; k++) {
            if (j != k) {
                if (firstName[j] == firstName[k]) {
                    a[j] = 1;
                }
            }
        }
        if (a[j] == 0) {
            console.log(firstName[j]);
        } else {
            console.log(firstName[j] + " " + lastName[j]);
        }
    }
}
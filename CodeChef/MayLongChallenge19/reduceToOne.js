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
    var l = [];
    for (var i = 1; i <= n; i++) {
        l.push(i);
    }

    var len;
    var arr = [];
    if (n % 2 === 0) {
        len = l.length();
    } else {
        len = l.length() - 1;
        arr.push(l[len+1]);
    }

    for (var i = 1; i <= len; i += 2) {
        var x = l[i];
        var y = l[i + 1];
        var res = l[i] + l[i + 1] + (l[i] * l[i + 1]);

        arr.push(res);
    }
    console.log("arr: ", arr);
}
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
    var numerator = [], denominator=[];
    for(var i=0;i<n;i++){
        var _string = nextInput();
        numerator.push(parseInt(_string.split("/")[0]));
        denominator.push(parseInt(_string.split("/")[1]));
    }
    for(var i=0;i<n;i++){
        var max = 0, sum_num=0, sum_denom=0, sum=0;
        for(var j=i;j<n;j++){
            sum_num+=numerator[j];
            sum_denom+=denominator[j];
            sum = sum_num/sum_denom;
            // sum+=numerator[j]/denominator[j];
            if(sum>max){
                max = sum;
            }
        }
        console.log("TCL: function_main -> sum_num", sum_num)
        console.log("TCL: function_main -> sum_denom", sum_denom)
        console.log("TCL: function_main -> max", max);
    }
    
}
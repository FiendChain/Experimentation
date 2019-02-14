// HTML focused functions //
function fibonacci() {
    var iter = document.getElementById('fibSlider').value;
    var x = 1;
    var y = 1;
    var temp = 0;
    var fibList = [1,1];
    for(var i = 2; i < iter; i ++) {
        temp = x;
        x = x + y;
        y = temp;
        fibList.push(x); 
    }
    console.log('[' + fibList + ']');
}

function customAlert() {
    var elementID = 'customMessage';
    var string = document.getElementById(elementID).value;
    console.log(string);
    if(string == '') {
        alert('Insert a valid string!');
    } else{
        alert(string);
    }
}

function updateSlider(newValue) {
    var elementID = 'fibValue';
    document.getElementById(elementID).innerHTML = 'Fibonacci Sequence: ' + newValue;
}
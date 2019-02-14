// Creating arrays using javascript
var array = ['Tortilla', 'Burrito', 'Salmon'];

// Accessing attributes for an array
var arrayLength = array.length;

/* Mutator methods
    - These methods will modify the array
    - Are readily public
*/
// Pushing items into an array
/* Modifies and returns original array
    - array.push(item) will modify original array
    - However it also returns the new original array
*/
var pushTail = array.push('Apples');    // Add to tail
var pushHead = array.unshift('Banana'); // Add to head
// Removing items from an array
// These methods are similar but don't accept arguments
array.pop();    // Remove from tail
array.shift();  // Remove from head
// Removing an item via index location
var startIndex = 0;
var totalItems = 1;
var removeItem = array.splice(startIndex, totalItems);

/* Iterator methods
    - These will iterate through the array to perform an action
    - Are readily public
*/
// Will access each item in the array
// This function takes a function as its parameter
array.forEach(function(item, index, array) {
    console.log('[' + index +']: ' + item);
});
// Can also just use one argument
array.forEach(function(item) {
    console.log(item);
});
// Can also call a function instead of creating it locally
function externalFunction(item, index) {
    var printString = '[' + index + ']: ' + item;
    console.log(printString);
}
array.forEach(externalFunction);

// Creating 2D array (2d array with default values)
var newArray = [];
var totalCol = 10;
var totalRow = 10;
for(var row = 0; row < totalRow; row ++) {
    newArray[row] = [];
    for(var col = 0; col < totalCol; col ++) {
        newArray[row][col] = 0;
    }
}
console.table(newArray);
// Alternatively use a constructor (empty 2d array)
/*  This is bad practise since it modifies the 
    length attribute without filling in the array.
    So when you want to check if an array is empty,
    you cannot use the length function */
var diffArray = new Array(totalRow);
for(var row = 0; row < diffArray.length; row ++) {
    diffArray[row] = new Array(totalCol);
}
// Populating an empty array made using constructor function
for(var row = 0; row < diffArray.length; row ++) {
    for(var col = 0; col < diffArray[row].length; col ++) {
        diffArray[row][col] = row + col;
    }
}
console.table(diffArray);
// More on the array constructor
var fullArray  = new Array('Apples', 'Banana', 'Cheerios');
var emptyArray = new Array(10);
/* 
    Array(size) is like:
    int *array = (int*)malloc(size*sizeof(int))
*/

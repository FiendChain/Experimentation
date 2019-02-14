/*  
    Different ways of creating objects in javascript:
        1. Object literal
        2. Object constructor
*/


/* 1. Object literal
    - This is called JSON
    - JavaScript Object Notation
*/
// Creating JSON object
var objectLiteral = {
    firstName : 'John',
    lastName : 'Lenon',
    age : 20,
    location : 'Earth'
}
// Can be accessed like a python dictionary
for(key in objectLiteral) {
    console.log(key + ' : ' + objectLiteral[key]);
    /* The following doesn't work:
        console.log(objectLiteral.key);
            - actual: objectLiteral.key
            - expected: objectLiteral.firstName, objectLiteral.lastName
    */
}

/* 2. Object constructor
    - This is created using a constructor function
    - The variables and functions in this constructor can be:
        - Public
        - Private
*/
// Creating constructor function
function objectConstructor(firstName, lastName, age, location) {
    // Creating public variables (accessable once instantiated)
    this.firstName = firstName;
    this.lastName = lastName;
    this.age = age;
    this.location = location;
    // Creating private variables (difficult to access once instantiated?)
    var longName = this.firstName + ' ' + this.lastName;

    // Creating a public method
    this.publicMethod = function() {
        console.log('This is a public method');
        console.log('Accessing private method through public method!');
        privateMethod(longName);
    }
    // Creating a private method (can be accessed inside constructor function)
    function privateMethod(string) {
        console.log('This is a private method');
        console.log('Private variable: ' + string);
    }
}
// Instantiating an object constructor using the 'new' operator
var newObject = new objectConstructor('John', 'Lenon', 20, 'Earth');
// Accesing public variables
var publicVar = newObject.firstName;
console.log('Public variable: ' + publicVar);
// Accessing public method
newObject.publicMethod();
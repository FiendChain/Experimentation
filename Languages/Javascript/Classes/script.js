// Private method able to access the new object
function ThatPerson() {
  var that = this;
  that.age = 0;

  setInterval(function growUp() {
    that.age++;
  }, 1000);
}

var thatPerson = new ThatPerson();

// Private method bound to global object
function ThisPerson() {
    // The Person() constructor defines `this` as an instance of itself.
    this.age = 0;
    setInterval(function growup() {
        // In non-strict mode, the growUp() function defines `this` 
        // as the global object, which is different from the `this`
        // defined by the Person() constructor.
        this.age ++;
    }, 1000);
}

var thisPerson = new ThisPerson();
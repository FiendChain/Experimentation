// Testing objects
var meson = new Particle(5, 5, 10, 10, 30);

// Entry point for this script
function objectsMain() {
    // Creating a class
    var particle = new Particle(0, 0, 2, 2, 20);
    console.log(particle);
}

// Creating a particle object
function Particle(posX, posY, velX, velY, mass) {
    // Variables
    this.pos = new Vector(posX, posY);
    this.vel = new Vector(velX, velY);
    this.mass = mass;

    // Method
    this.phys = new Physics(this);
}

// Vector object
function Vector(x, y) {
    // Instantiate vector object
    this.x = x;
    this.y = y;

    // Object methods
    this.mag = function(newMag) {
        // Get current magnitude
        var magSquared = Math.pow(this.x, 2) + Math.pow(this.y, 2);
        var oldMag = Math.sqrt(magSquared);
        // If no new mag is given
        if(newMag === undefined) {
            return oldMag;
        } else if(oldMag != 0) {
            var scale = newMag / oldMag;
            this.x *= scale;
            this.y *= scale;
        }
    }
    this.dir = function(newDir) {
        // If at origin, direction undefined
        if(this.x == 0 && this.y == 0) {
            return undefined;
        }
        // Otherwise, get direction
        var oldDir = Math.atan(this.y/this.x) * 180 / Math.PI;
        if(newDir === undefined) {
            return oldDir;
        } else {
            const radianConvert = Math.PI / 180;
            newDir *= radianConvert;
            oldDir *= radianConvert;
            this.x *= Math.cos(newDir)/Math.cos(oldDir);
            this.y *= Math.sin(newDir)/Math.sin(oldDir);
        } 
    }
}

// Physics object
function Physics(particle) {
    // Kinetic energy
    this.kineticEnergy = function() {
        return 1/2 * particle.mass * Math.pow(particle.vel.mag(), 2);
    }
    // Momentum
    this.momentum = function() {
        return particle.mass * particle.vel.mag();
    }
    // Resting energy
    let lightSpeed = 3 * Math.pow(10, 8);
    this.restEnergy = function() {
        return particle.mass * Math.pow(lightSpeed, 2);
    }
}
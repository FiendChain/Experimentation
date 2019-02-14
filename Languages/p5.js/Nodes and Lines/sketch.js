var config = {
  "canvasWidth": 1500,
  "canvasHeight": 700,
  "backgroundColour": 0,
  "lineColour": 255,
  "lineWeight": 1,
  "rectWidth": 1,
  "rectHeight": 1,
  "totalParticles": 15,
  "maxAccX": 50,
  "maxAccY": 50,
};

var particles = []

// Creates canvas and initialises array of particles
function setup() {
    var canvas = createCanvas(config.canvasWidth, config.canvasHeight);
    canvas.parent(document.getElementById("canvasContainer"));
    for(var i = 0; i < config.totalParticles; i++) {
        particles.push(randomParticleOnCanvas());
        applyRandomForce(particles[i]);
    }
  stroke(config.lineColour);
  strokeWeight(config.lineWeight);
}

// Called every frame - Generally used to update objects
function draw() {
    background(config.backgroundColour);
    for(var i = particles.length-1; i >= 0; i--) {
        //applyRandomForce(particles[i]);
        particles[i].update();
        particles[i].show();
        var posA = particles[i].pos;
        for(var j = i-1; j >= 0; j--) {
            var posB = particles[j].pos;
            line(posA.x, posA.y, posB.x, posB.y);
        }
    }
    updateCounter();
}

// Create particle
function Particle(initPos) {
    this.pos = initPos;  // position vectors
    this.vel = createVector(0, 0);
    this.acc = createVector(0, 0);

    this.applyForce = function(force) {
        this.acc.add(force);
    }

    this.update = function() {
        this.vel.add(this.acc);
        this.bounce();
        this.pos.add(this.vel);
        this.acc.mult(0);       // reset after frame
        //this.wrap();
    }

    this.wrap = function() {
        if(this.pos.x < 0 - config.rectWidth) {
            this.pos.x = config.canvasWidth + config.rectWidth;
        }
        if(this.pos.x > config.canvasWidth + config.rectWidth) {
            this.pos.x = 0 - config.rectWidth;
        }
        if(this.pos.y < 0 - config.rectHeight) {
            this.pos.y = config.canvasHeight + config.rectHeight;
        }
        if(this.pos.y > config.canvasHeight + config.rectHeight) {
            this.pos.y = 0 - config.rectHeight;
        }
    }

    this.bounce = function() {
        if(this.pos.x < 0 && this.vel.x < 0) {
            this.vel.x *= -1;
        }
        if(this.pos.x > config.canvasWidth - config.rectWidth && this.vel.x > 0) {
            this.vel.x *= -1;
        }
        if(this.pos.y < 0 && this.vel.y < 0) {
            this.vel.y *= -1;
        }
        if(this.pos.y > config.canvasHeight - config.rectHeight && this.vel.y > 0) {
            this.vel.y *= -1;
        }
  }

    this.show = function() {
        rect(this.pos.x, this.pos.y, config.rectWidth, config.rectHeight);
    }
}

// Creates a random particle
function randomParticleOnCanvas() {
    var x = randomRange(0, config.canvasWidth - config.rectWidth);
    var y = randomRange(0, config.canvasHeight - config.rectHeight);
    return new Particle(createVector(x, y));
}

// Exerts a random force on the object
function applyRandomForce(particle) {
    var x = randomRange(-config.maxAccX, config.maxAccX);
    var y = randomRange(-config.maxAccY, config.maxAccY);
    particle.applyForce(createVector(x, y));
}

// Used by webpage elements 
function addNode() {
    particles.push(randomParticleOnCanvas());
    x = randomRange(-config.maxAccX, config.maxAccX);
    applyRandomForce(particles[particles.length-1]);
}

function removeNode() {
    particles.pop();
}

function updateCounter() {
    var counter = document.getElementById("nodeCounter");
    counter.innerHTML = particles.length;
}

// Random number
function randomRange(min, max) {
    return Math.random() * (max-min) + min;
}

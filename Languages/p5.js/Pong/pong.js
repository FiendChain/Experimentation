var config = {
    "canvasWidth": 1500,
    "canvasHeight": 800,
    "backgroundColour": 0,
    "strokeColour": 255,
    "strokeWeight": 2,
    "paddleWidth": 33,
    "paddleHeight": 150,
    "paddleSpeed": 10,
    "ballSize": 30,
    "ballSpeed": {"min": 10, "max": 20},
    "botSkill": 10,
    "leftBot": true,
    "rightBot": false,
    "randomAcc": {"min": 0, "max": 0},
    "fps": 144,
    "tickspeed": 120,
};

var leftPaddle, rightPaddle, ball, botLeft, botRight, scoreBoard;

// Creates canvas and initialises array of particles
function setup() {
    var dt = config.tickspeed / config.fps;
    // Draw settings
    createCanvasByID("canvasContainer");
    createBotControls("botControls");
    frameRate(config.fps);
    stroke(config.strokeColour);
    strokeWeight(config.strokeWeight);
    // Create objects
    scoreBoard = new ScoreBoard("scoreboard");
    scoreBoard.initialise();
    ball = new Ball(0, 0, config.ballSize, config.ballSpeed, dt, scoreBoard);
    leftPaddle = new Paddle(-config.canvasWidth/2, -config.paddleHeight/2, 
                             config.paddleWidth, config.paddleHeight, 
                             config.paddleSpeed, dt);
    rightPaddle = new Paddle(config.canvasWidth/2 - config.paddleWidth, -config.paddleHeight/2, 
                             config.paddleWidth, config.paddleHeight, 
                             config.paddleSpeed, dt);
    botLeft = new PaddleBot(leftPaddle, ball, config.botSkill);
    botRight = new PaddleBot(rightPaddle, ball, config.botSkill);
}

function createCanvasByID(canvasID) {
    var canvas = createCanvas(config.canvasWidth, config.canvasHeight);
    canvas.parent(document.getElementById(canvasID));
}

// Called every frame - Generally used to update objects
function draw() {
    background(config.backgroundColour);
    translate(config.canvasWidth/2, config.canvasHeight/2);     // Centre at 0,0
    line(0, -config.canvasHeight/2, 0, config.canvasHeight/2);
    ball.vel.add(createVector(randomRange(config.randomAcc.min, config.randomAcc.max), 
                              randomRange(config.randomAcc.min, config.randomAcc.max)))
    ball.update();
    ball.show();
    leftPaddle.show();
    leftPaddle.bounce(ball);
    leftPaddle.update();
    leftPaddle.control();
    rightPaddle.show();
    rightPaddle.bounce(ball);
    rightPaddle.update();
    if(config.leftBot == true)  botLeft.movePaddle();
    if(config.rightBot == true) botRight.movePaddle();
}

// Paddle object
function Paddle(x, y, width, height, speed, dt) {
    this.pos = createVector(x, y);
    this.vel = createVector(0, 0);
    this.dt = dt;
    
    this.width = width;
    this.height = height;
    this.speed = speed;
    
    this.up = UP_ARROW;
    this.down = DOWN_ARROW;
    

    this.update = function() {
        this.pos.add(p5.Vector.mult(this.vel, this.dt));
        this.checkBounds();
    }

    this.bounce = function(ball) {
        // Check if height is within range
        if((ball.pos.y + ball.radius < this.pos.y + this.height &&
             ball.pos.y + ball.radius > this.pos.y) || 
             (ball.pos.y - ball.radius < this.pos.y + this.height &&
                ball.pos.y - ball.radius > this.pos.y)) {
            // Right side collision
            if(ball.pos.x - ball.radius >= this.pos.x && ball.pos.x - ball.radius <= this.pos.x + this.width) {
                if(ball.vel.x < 0) ball.vel.x *= -1;
                ball.vel.add(this.vel);
            }
            // Left side collision
            if(ball.pos.x + ball.radius <= this.pos.x + this.width && ball.pos.x + ball.radius >= this.pos.x) {
                if(ball.vel.x > 0) ball.vel.x *= -1;
                ball.vel.add(this.vel);
            }
            
        }
    }

    this.setControl = function(up, down) {
        this.up = up;
        this.down = down;
    }

    this.control = function() {
        if(isKeyPressed) {
            if(keyCode == this.up) {
                this.vel.y = -this.speed;
            }
            if(keyCode == this.down) {
                this.vel.y = this.speed;
            }
        } else {
            this.vel.y = 0;
        }
    }

    this.checkBounds = function() {
        if(this.pos.y < -config.canvasHeight/2) {
            this.pos.y = -config.canvasHeight/2;
        }
        if(this.pos.y + this.height > config.canvasHeight/2) {
            this.pos.y = config.canvasHeight/2 - this.height;
        }
    }

    this.show = function() {
        fill(255);
        rect(this.pos.x, this.pos.y, this.width, this.height);
    }
}

// Ball object
function Ball(x, y, radius, velRange, dt, scoreboard) {
    this.pos = createVector(x, y);
    this.vel = createVector(randomRange(velRange.min, velRange.max), 
                            randomRange(velRange.min, velRange.max));
    this.dt = dt;
    
    this.radius = radius;
    this.velRange = velRange;
    this.scoreboard = scoreboard;   // ball will interact with scoreboard

    this.update = function() {
        this.pos.add(p5.Vector.mult(this.vel, this.dt));
        this.checkBounds();
    }

    this.checkBounds = function() {
        // Left paddle loses
        if(this.pos.x <= -config.canvasWidth/2) {
            this.pos.x = this.pos.y = 0;
            this.vel = createVector(randomRange(this.velRange.min, this.velRange.max), 
                                    randomRange(this.velRange.min, this.velRange.max));
            this.scoreboard.setWinner("right");
        // Right paddle loses
        } else if(this.pos.x >= config.canvasWidth/2) { 
            this.pos.x = this.pos.y = 0;
            this.vel = createVector(randomRange(-this.velRange.min, -this.velRange.max), 
                                    randomRange(this.velRange.min, this.velRange.max));
            this.scoreboard.setWinner("left");
        }
        // If bottom edge is hit, bounce
        if(this.pos.y <= -config.canvasHeight/2) {
            if(this.vel.y < 0) this.vel.y *= -1;
        }
        if(this.pos.y >= config.canvasHeight/2) {
            if(this.vel.y > 0) this.vel.y *= -1;
        }
    }    

    this.show = function() {
        fill(255);
        ellipse(this.pos.x, this.pos.y, this.radius, this.radius);
        //rect(this.pos.x-this.radius, this.pos.y-this.radius, this.radius, this.radius);
    }
}

function randomRange(min, max) {
    range = max - min;
    return Math.random()*range + min;
}


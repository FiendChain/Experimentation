// Bot object
function PaddleBot(paddle, ball, skill) {
    this.paddle = paddle;
    this.ball = ball;
    this.skill = skill;
    this.inPosition = false;
    
    this.checkDirection = function() {          // True if ball heading to paddle
        var posDiff = this.paddle.pos.x - this.ball.pos.x;
        if(posDiff * this.ball.vel.x < 0) {
            return false;
        } else {
            return true;
        }
    }

    this.predictCollision = function() {
        // Get basic prediction
        var m = this.ball.vel.y / float(this.ball.vel.x);
        var b = this.ball.pos.y - m * this.ball.pos.x;
        var x = this.paddle.pos.x;
        var width = this.paddle.width;
        var radius = this.ball.radius;
        var maxHeight = config.canvasHeight/2.0;
        var dir;
        if(this.ball.vel.x < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        var y = 0;
        for(var i = 0; i < this.skill; i++) {
            if(dir < 0) {             
                y = m*(x+width) + b;
            } else {
                y = m*(x) + b;
            }
            // Check if within bounds
            if(y < maxHeight && y > 0) {    
                break;
            }
            // Shift the prediction line
            if(m*dir >= 0) {
                b = 2*(maxHeight - radius) - b;
            } else {
                b = 2*(-maxHeight + radius) - b;
            }
            m *= -1;
        }
        if(y > maxHeight || y < 0) {
            y = this.ball.pos.y;
        }
        
        return y;
    }

    this.movePaddle = function() {
        if(this.checkDirection() == true) {
            var prediction = this.predictCollision();
            if(this.inPosition == false) {
                if(prediction > this.paddle.pos.y + this.paddle.height*0.66) {
                    this.paddle.vel.y = this.paddle.speed;
                } else if(prediction < this.paddle.pos.y + this.paddle.height*0.33) {
                    this.paddle.vel.y = -this.paddle.speed;
                } else {
                    this.paddle.vel.y = 0;
                    this.inPosition = true;
                }
            } else {
                if(prediction > this.paddle.pos.y + this.paddle.height) {
                    this.inPosition = false;
                } else if(prediction < this.paddle.pos.y) {
                    this.inPosition = false;
                }
            }
        }
    }
}

function createBotControls(controlsID) {
    var controls = document.getElementById(controlsID);
    var buttonLeft = document.createElement("button");
    buttonLeft.onclick = function() {
        config.leftBot = !config.leftBot;
        if(config.leftBot == true) {
            buttonLeft.innerHTML = "Left Bot: On";
        } else {
            buttonLeft.innerHTML = "Left Bot: Off";
        }
    }
    var buttonRight = document.createElement("button");
    buttonRight.onclick = function() {
        config.rightBot = !config.rightBot;
        if(config.rightBot == true) {
            buttonRight.innerHTML = "Right Bot: On";
        } else {
            buttonRight.innerHTML = "Right Bot: Off";
        }
    }
    buttonLeft.onclick();
    buttonRight.onclick();
    controls.appendChild(buttonLeft);
    controls.appendChild(buttonRight);
}

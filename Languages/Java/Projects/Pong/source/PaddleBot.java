    
class PaddleBot {
    private Ball ball;
    private Paddle paddle;
    private int skill = 2;
    private boolean inPosition = false;

    public PaddleBot(Ball ball, Paddle paddle) {
        this.ball = ball;
        this.paddle = paddle;
    }

    public PaddleBot(Ball ball, Paddle paddle, int skill) {
        this.ball = ball;
        this.paddle = paddle;
        this.skill = skill;
    }

    public void movePaddle() {
        if(this.checkDirection()) {
            float y = this.predictCollision();
            // If not in middle position, get to middle segment
            if(!inPosition) {
                if(y > this.paddle.getPos().y + this.paddle.getSize().y/3.0f) {
                    paddle.move(MOVE.DOWN);
                } else if(y < this.paddle.getPos().y - this.paddle.getSize().y/3.0f) {
                    paddle.move(MOVE.UP);
                } else {
                    paddle.move(MOVE.STOP);
                    inPosition = true;
                }
            } else {
                if(y > paddle.getPos().y + paddle.getSize().y/2.0f) {
                    inPosition = false;
                } else if(y < paddle.getPos().y - paddle.getSize().y/2.0f) {
                    inPosition = false;
                }
            }
        }
    }

    private float predictCollision() {
        // Equation variables  
        float m = ball.getVel().y / ball.getVel().x;
        float b = ball.getPos().y - m * ball.getPos().x;
        float x = paddle.getPos().x;
        // Paddle and ball dimensions
        float width = paddle.getSize().x / 2.0f;
        float radius = ball.getRadius();
        // Box height
        float maxHeight = ball.getRes().y;
        int dir;
        // Left side
        if(ball.getVel().x < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        float y = maxHeight/2.0f;
        for(int i = 0; i < skill; i++) {
            // Get prediction
            if(dir < 0) {             
                y = m*(x+width) + b;
            } else {
                y = m*(x-width) + b;
            }
            // Check if within bounds
            if(y < maxHeight && y > 0) {    
                break;
            }
            // Shift the prediction line
            if(m*dir >= 0) {
                b = 2*(maxHeight - radius) - b;
            } else {
                b = 2*(0+radius) - b;
            }
            m *= -1;
        }
        // If prediction out of bounds, track ball
        if(y > maxHeight || y < 0) {
            y = ball.getPos().y;
        }

        return y;
    }

    private boolean checkDirection() {
        float xDiff = paddle.getPos().x - ball.getPos().x;
        if(xDiff * ball.getVel().x < 0) {
            return false;
        }
        return true;
    }
}
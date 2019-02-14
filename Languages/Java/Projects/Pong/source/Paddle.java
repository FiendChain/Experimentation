import java.util.Scanner;
import java.awt.Graphics;
import java.awt.Color;

// global enum used by game
enum MOVE {
    UP, DOWN, LEFT, RIGHT, STOP;
}

public class Paddle {
    // physics
    private Vector2f pos = new Vector2f();
    private Vector2f vel = new Vector2f();
    private float dt = 1;
    private Vector2f size = new Vector2f(); // x = width, y = height
    private float speed = 0;
    // environment
    private Vector2f res = new Vector2f();
    private Ball ball = null;

    // constructors
    public Paddle() {

    }

    public Paddle(float posX, float posY, float width, float height, float speed) {
        this.pos.set(posX, posY);
        this.size.set(width, height);
        this.speed = speed;
    }

    // setters
    public void setBall(Ball ball) {
        this.ball = ball;
    }

    public void setRes(float x, float y) {
        this.res.set(x, y);
    }

    public void setDt(float dt) {
        this.dt = dt;
    }

    // getters
    public Vector2f getSize() {
        return this.size.clone();
    }

    public Vector2f getPos() {
        return this.pos.clone();
    }

    // update physics, check if within screen, and check if ball if going to bounce off it
    public void update() {
        this.pos.add(this.vel.getMult(this.dt));
        this.bound();
        this.bounce();
    }

    // move it up and down
    public void move(MOVE dir) {
        switch(dir) {
            case UP:
                this.vel.y = -this.speed;
                break;
            case DOWN:
                this.vel.y = +this.speed;
                break;
            case LEFT:
                this.vel.x = -this.speed;
                break;
            case RIGHT:
                this.vel.x = +this.speed;
                break;
            case STOP:
                this.vel.y = 0;
                break;
            default:
                this.vel.y = 0;
        }
    }

    // render paddle to a graphic object
    public void show(Graphics g) {
        g.setColor(Color.white);
        g.fillRect((int)(this.pos.x-this.size.x/2.0f), (int)(this.pos.y-this.size.y/2.0f), (int)this.size.x, (int)this.size.y);
    }

    // keep within screen
    private void bound() {
        // y bound
        if(this.pos.y - this.size.y/2.0f < 0) {
            this.pos.y = this.size.y/2.0f;
            this.vel.y = 0;
        } else if(this.pos.y + this.size.y/2.0f > this.res.y) {
            this.pos.y = this.res.y - this.size.y/2.0f;
            this.vel.y = 0;
        }
        // x bound
        if(this.pos.x - this.size.x/2.0f < 0) {
            this.pos.x = this.size.x/2.0f;
            this.vel.x = 0;
        } else if(this.pos.x + this.size.x/2.0f > this.res.x) {
            this.pos.x = this.res.x - this.size.x/2.0f;
            this.vel.x = 0;
        }
    }

    // check if ball will bounce off it
    private void bounce() {
        if(this.ball == null) {
            return;
        }
        Vector2f ballPos = this.ball.getPos();
        Vector2f ballVel = this.ball.getVel();
        float ballRadius = this.ball.getRadius();
        // within paddle range
        if(this.yInside(ballPos.y+ballRadius) || this.yInside(ballPos.y+ballRadius)) {
            // left edge
            if(this.xInside(ballPos.x-ballRadius) && ballVel.x < 0) {
                this.ball.bouncePaddle(new Vector2f(this.vel.x, this.vel.y));  
            // Right edge
            } else if(this.xInside(ballPos.x+ballRadius) && ballVel.x > 0) {
                this.ball.bouncePaddle(new Vector2f(this.vel.x, this.vel.y));
            }
        }
    }

    // check if xcoord is within paddle
    private boolean xInside(float x) {
        return (x < this.pos.x + this.size.x/2.0f &&
                x > this.pos.x - this.size.x/2.0f);
    }

    // check if ycoord is within paddle
    private boolean yInside(float y) {
        return (y < this.pos.y + this.size.y/2.0f &&
                y > this.pos.y - this.size.y/2.0f);
    }


}
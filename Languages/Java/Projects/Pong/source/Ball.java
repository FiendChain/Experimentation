// graphics
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

public class Ball {
    // physics
    private Vector2f pos = new Vector2f();
    private Vector2f vel = new Vector2f();
    private float dt = 1;
    private float radius = 0;
    private float speed = 0;
    // environment
    private Vector2f res = new Vector2f();
    private int leftScore = 0;
    private int rightScore = 0;
    // enum used to determine which side wins
    private enum DIR {
        LEFT, RIGHT;
    }

    // constructors
    public Ball() {

    }

    public Ball(float posX, float posY, float radius, float speed) {
        this.pos.set(posX, posY);
        this.radius = radius;
        this.speed = speed;
    }

    // setters
    public void setRes(float x, float y) {
        this.res.set(x, y);
        this.reset(DIR.LEFT);
    }

    public void setDt(float dt) {
        this.dt = dt;
    }

    // getters
    public Vector2f getPos() {
        return this.pos.clone();
    }

    public Vector2f getVel() {
        return this.vel.clone();
    }

    public Vector2f getRes() {
        return this.res.clone();
    }

    public float getRadius() {
        return this.radius;
    }

    // update physics and check if within screen
    public void update() {
        this.pos.add(this.vel.getMult(this.dt));
        this.bound();
    }

    // called by paddle, which passes a clone of its velocity
    public void bouncePaddle(Vector2f vel) {
        this.vel.x *= -1;
        this.vel.add(vel);
    }

    // render ball to a graphic object
    public void show(Graphics g) {
        g.setColor(Color.white);
        g.fillRect((int)(this.pos.x-this.radius), (int)(this.pos.y-this.radius), (int)(2*this.radius), (int)(2*this.radius));
        int fontSize = 40;
        g.setFont(new Font("Arial", Font.CENTER_BASELINE, fontSize));
        g.drawString(String.valueOf(this.leftScore), (int)(this.res.x/4.0f), (int)(this.res.y/4.0f));
		g.drawString(String.valueOf(this.rightScore), (int)(3*this.res.x/4.0f)-fontSize, (int)(this.res.y/4.0f));
    }

    public void resetScore() {
        this.reset(DIR.LEFT);
        this.leftScore = this.rightScore = 0;
    }

    // private
    private void bound() {
        // bounce top and bottom edges
        if(this.pos.y - this.radius < 0 && this.vel.y < 0) {
            this.pos.y = this.radius;
            this.vel.y *= -1;
        } else if(this.pos.y + this.radius > this.res.y && this.vel.y > 0) {
            this.pos.y = this.res.y - this.radius;
            this.vel.y *= -1;
        }
        // reset and add score for left and right edges
        if(this.pos.x < 0) {
            this.rightScore += 1;
            this.reset(DIR.LEFT);
            this.vel.set(-this.speed, this.speed);
        } else if(this.pos.x > this.res.x) {
            this.leftScore += 1;
            this.reset(DIR.RIGHT);
            this.vel.set(this.speed, -this.speed);
        }
    }

    private void reset(DIR dir) {
        this.pos.set(this.res.x/2.0f, this.res.y/2.0f);
        switch(dir) {
            case LEFT:
                this.vel.set(-this.speed, this.speed);
                break;
            case RIGHT:
                this.vel.set(this.speed, -this.speed);
                break;
            default:
                this.vel.set(this.speed, this.speed);
        }
    }
}
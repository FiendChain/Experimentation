// rendering
import java.applet.Applet;
import java.lang.Runnable;
// graphics
import java.awt.Graphics;
import java.awt.Color;
import java.awt.Image;
// keyboard
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Pong extends Applet implements Runnable, KeyListener {
    // game settings
    private final float fps = 144;
    private final float tickrate = 50;
    private final float dt = this.tickrate/this.fps;
    private final int millis = (int)(1000/fps);
    private final float speed = 10;   // speed of ball/paddle
    private final float size = 10;    // size of ball/paddle
    private final Vector2f res = new Vector2f(1300, 700);
    // game objects
    private Ball ball = null;
    private Paddle leftPaddle = null;
    private Paddle rightPaddle = null;
    private PaddleBot leftPaddleBot = null;
    private PaddleBot rightPaddleBot = null;
    // rendering buffers
    private Graphics graphicsBuffer;    // buffer1 used in double graphics buffer (stops flickering)
    private Image graphicsImage;        // rendered onto buffer0 (g)

    // init the Pong game
    public void init() {
        resize((int)this.res.x, (int)this.res.y);
        setBackground(Color.white);
        // Instantiate objects
        this.initObjects();
        this.setObjectPhysics();
        // create graphics buffer
        graphicsImage = createImage((int)this.res.x, (int)this.res.y);
        graphicsBuffer = graphicsImage.getGraphics();
        // initiate thread
        Thread thread = new Thread(this);
        thread.start();
        // listen to keys
        addKeyListener(this);
    }

    // double graphics buffer
    // g = buffer0
    // graphicsBuffer = buffer1
    public void update(Graphics g) {
        this.graphicsBuffer.setColor(Color.black);
        this.graphicsBuffer.fillRect(0, 0, (int)this.res.x, (int)this.res.y);
        paint(graphicsBuffer);  
        g.drawImage(graphicsImage, 0, 0, this);
    }

    // double graphics buffer
    // buffer1 is drawn, then applied to graphic g (buffer0)
    // then on repaint, the graphic g (buffer0) is also updated with game objects
    // game needs to be drawn on buffer 0 and1 because java is shit and flickers if you dont do this
    public void paint(Graphics g) {
        this.drawSeparator(g);
        this.ball.show(g);
        this.leftPaddle.show(g);
        this.rightPaddle.show(g);
    }

    // exec method
    public void run() {
        while(true) {
            this.ball.update();
            this.leftPaddle.update();
            this.rightPaddle.update();
            //this.leftPaddleBot.movePaddle();
            this.rightPaddleBot.movePaddle();
            repaint();
            try {
                Thread.sleep((long)millis);
            } catch(InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    // ???
    public void keyTyped(KeyEvent e) {

	}

    // activate if key is released
	public void keyReleased(KeyEvent e) {
        int input = e.getKeyCode();
        // left paddle
        if(input == KeyEvent.VK_UP) {
            this.leftPaddle.move(MOVE.STOP);
        } else if(input == KeyEvent.VK_DOWN) {
            this.leftPaddle.move(MOVE.STOP);
        }
        // right paddle
        if(input == KeyEvent.VK_W) {
            this.rightPaddle.move(MOVE.STOP);
        } else if(input == KeyEvent.VK_S) {
            this.rightPaddle.move(MOVE.STOP);
        }
	}

    // activate if key is pressed
	public void keyPressed(KeyEvent e) {
        int input = e.getKeyCode();
        // left paddle
        if(input == KeyEvent.VK_UP) {
            this.leftPaddle.move(MOVE.UP);
        } else if(input == KeyEvent.VK_DOWN) {
            this.leftPaddle.move(MOVE.DOWN);
        }
        // right paddle
        if(input == KeyEvent.VK_W) {
            this.rightPaddle.move(MOVE.UP);
        } else if(input == KeyEvent.VK_S) {
            this.rightPaddle.move(MOVE.DOWN);
        }
        // reset
        if(input == KeyEvent.VK_R) {
            this.ball.resetScore();
        }
	}

    // instantiate game objects
    private void initObjects() {
        this.ball = new Ball(this.res.x/2.0f, this.res.y/2.0f, this.size, this.speed);
        this.leftPaddle = new Paddle(3*this.size, this.res.y/2.0f, 2*this.size, 10*this.size, 2*this.speed);
        this.rightPaddle = new Paddle(this.res.x-3*this.size, this.res.y/2.0f, 2*this.size, 10*this.size, 2*this.speed);
        this.leftPaddleBot = new PaddleBot(this.ball, this.leftPaddle);
        this.rightPaddleBot = new PaddleBot(this.ball, this.rightPaddle);
        this.setObjectPhysics();
        this.linkBalltoPaddles();
    }

    // update objects with new physics timescale (dt)
    private void setObjectPhysics() {
        this.ball.setDt(this.dt);
        this.ball.setRes(this.res.x, this.res.y);
        this.leftPaddle.setDt(this.dt);
        this.leftPaddle.setRes(this.res.x, this.res.y);
        this.rightPaddle.setDt(this.dt);
        this.rightPaddle.setRes(this.res.x, this.res.y);
    }

    // give the ball to each paddle
    private void linkBalltoPaddles() {
        this.leftPaddle.setBall(this.ball);
        this.rightPaddle.setBall(this.ball);
    }

    // separator for aesthetics
    private void drawSeparator(Graphics g) {
        g.setColor(Color.white);
        g.fillRect((int)((this.res.x-this.size)/2.0f), 0, (int)this.size, (int)this.res.y); 
    }
}
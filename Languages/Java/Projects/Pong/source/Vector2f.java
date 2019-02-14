import java.lang.Cloneable;

public class Vector2f implements Cloneable {
    public float x;
    public float y;

    public Vector2f() {
        this.x = this.y = 0;
    }

    public Vector2f(float x, float y) {
        this.x = x;
        this.y = y;
    }

    // cloner
    public Vector2f clone() {
        return new Vector2f(this.x, this.y);
    }
    
    // setter
    public void set(float x, float y) {
        this.x = x;
        this.y = y;
    }

    // Methods
    public void add(Vector2f v) {
        this.x += v.x;
        this.y += v.y;
    }

    public void sub(Vector2f v) {
        this.x -= v.x;
        this.y -= v.y;
    }

    public void mult(float scalar) {
        this.x *= scalar;
        this.y *= scalar;
    }

    public Vector2f getMult(float scalar) {
        Vector2f v = new Vector2f(this.x*scalar, this.y*scalar);
        return v;
    }
}
package net.shape;
import net.shape.Shape;
import java.lang.Math;
import net.exception.ValueError;

public class Circle extends Shape {
    private double radius;

    public Circle() throws ValueError {
        this(0);
    }

    public Circle(double radius) throws ValueError {
        super();
        setRadius(radius);
    }

    public void setRadius(double radius) throws ValueError {
        if (radius < 0) {
            throw new ValueError("Radius cannot be negative");
        }
        this.radius = radius;
        super.setArea(Math.PI * Math.pow(radius, 2));
    }

    public double getRadius() {
        return this.radius;
    }

    public double getArea() {
        return super.getArea();
    }
}

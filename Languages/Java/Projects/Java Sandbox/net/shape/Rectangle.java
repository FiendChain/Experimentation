package net.shape;
import net.shape.Shape;
import net.exception.ValueError;

public class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) throws ValueError {
        super();
        this.width = 0;
        this.height = 0;
        setWidth(width);
        setHeight(height);
    }

    public void setHeight(double height) throws ValueError {
        if (height < 0)
            throw new ValueError("Rectangle height cannot be negative");
        this.height = height;
        super.setArea(this.height * this.width);
    }

    public void setWidth(double width) throws ValueError {
        if (width < 0)
            throw new ValueError("Rectangle width cannot be negative");
        this.width = width;
        super.setArea(this.height * this.width);
    }    

    public double getHeight() {
        return this.height;
    }

    public double getWidth() {
        return this.width;
    }

    public double getArea() {
        return super.getArea();
    }
}       

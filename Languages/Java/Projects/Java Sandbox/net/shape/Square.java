package net.shape;
import net.shape.Shape;
import net.exception.ValueError;

public class Square extends Shape {
    private double size;

    public Square(double size) throws ValueError {
        super();
        setSize(size);
    }        

    public void setSize(double size) throws ValueError {
        if (size < 0)
            throw new ValueError("Square size cannot be negative");
        this.size = size;
        super.setArea(size*size);
    }    

    public double getSize() {
        return this.size;  
    }

    public double getArea() {
        return super.getArea();
    }    
}    




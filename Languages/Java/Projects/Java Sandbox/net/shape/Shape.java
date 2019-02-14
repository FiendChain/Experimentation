package net.shape;
import net.exception.ValueError;
import java.text.MessageFormat;

public class Shape {
    private double area;

    public Shape() {
        this.area = 0;
    }        

    public void setArea(double area) throws ValueError {
        if (area < 0) {
            throw new ValueError(MessageFormat.format("Area of shape cannot be negative: {0}", this.area));
        }
        this.area = area;
    }

    public double getArea() {
        return this.area;
    }    


}    


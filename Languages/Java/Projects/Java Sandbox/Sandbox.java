import net.shape.Circle;
import net.shape.Square;
import net.shape.Rectangle;
import java.text.MessageFormat;

public class Sandbox {

    public static void main(String[] args) throws Exception {
        Circle c = new Circle(10);
        Rectangle r = new Rectangle(20, 50);
        Square s = new Square(100);
        System.out.println(MessageFormat.format("circle: {0}", c.getArea()));
        System.out.println(MessageFormat.format("rectange: {0}", r.getArea()));
        System.out.println(MessageFormat.format("square: {0}", s.getArea()));
    }   
}




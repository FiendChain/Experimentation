// Comment
class Vector2f
{
    private double x, y;

    public Vector2f()
    {
        X = Y = 0;
    }

    public Vector2f(double x, double y)
    {
        X = x;
        Y = y;
    }
    
    // setters and getters
    public double X
    {
        get { return x; }
        set { x = value; }
    }
    
    public double Y 
    {
        get { return y; }
        set { y = value; }
    }
    
    // operator overloading
    // must be defined as public static
    public static Vector2f operator+ (Vector2f a, Vector2f b)
    {
        return new Vector2f(a.X+b.X, a.Y+b.Y);
    }
    
    public static Vector2f operator- (Vector2f a, Vector2f b)
    {
        return new Vector2f(a.X-b.X, a.Y-b.Y);
    }

    public static Vector2f operator* (Vector2f v, float m)
    {
        return new Vector2f(v.X*m, v.Y*m);
    }

    public static Vector2f operator/ (Vector2f v, float m)
    {
        return new Vector2f(v.X/m, v.Y/m);
    }

    public static bool operator== (Vector2f a, Vector2f b)
    {
        return a.X == b.X &&
               a.Y == b.Y;
    }

    public static bool operator!= (Vector2f a, Vector2f b)
    {
        return a.X != b.X ||
               a.Y != b.Y;
    }

    public override bool Equals(object obj)
    {
        if (obj.GetType() is Vector2f)
        {
            return this == (Vector2f)obj;
        }
        return false;
    }

    public override string ToString()
    {
        return string.Format("Vector2f({0},{1})", x, y);
    }
}
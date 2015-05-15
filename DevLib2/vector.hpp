#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T> class Vector
{
private:
    //Width, or the X part
    T _width;
    //Height, or the Y part
    T _height;
public:
    //Default constructor. Zeroes _width and _height
    Vector() :
        _width(0),
        _height(0)
    {}

    //Second constructor. Sets _width and _height from parameters
    Vector(T width, T height) :
        _width(width),
        _height(height)
    {}

    //Constructs the Vector from another Vector
    template<typename Type> Vector(Vector<Type>& vector) :
        _width(vector._width),
        _height(vector._height)
    {}

    //Adds this Vector to another to create a new Vector
    template<typename Type> Vector<T> operator+(Vector<Type> vec);
    //Substracts another Vector from this Vector to create a new Vector
    template<typename Type> Vector<T> operator-(Vector<Type> vec);
    //Adds another Vector to this Vector
    template<typename Type> Vector<T>& operator+=(Vector<Type> vec);
    //Substracts another Vector to this Vector
    template<typename Type> Vector<T>& operator-=(Vector<Type> vec);
    //Calculates the dot product
    template<typename Type> T operator*(Vector<Type> vec);
    //Scales this vector by scalar
    template<typename Type> Vector<T> operator*(Type scalar);
    //Scales the vector
    template<typename Type> Vector<T>& operator*=(Type scalar);

    //Calculates magnitude
    T magnitude();
    //Calculates direction
    T direction();

    //Checks for equality
    template<typename Type> bool operator==(Vector<Type> vec);
    //Checks for inequality
    template<typename Type> bool operator!=(Vector<Type> vec);

    //Assignment operator
    template<typename Type> Vector<T>& operator=(Vector<Type> vec);

    //Miscellaneous private member access functions
    T& x()
    {
        return _width;
    }

    T& y()
    {
        return _height;
    }

    T& width()
    {
        return _width;
    }

    T& height()
    {
        return _height;
    }

    T getX()
    {
        return _width;
    }

    T getY()
    {
        return _height;
    }

    T getWidth()
    {
        return _width;
    }

    T getHeight()
    {
        return _height;
    }

    T& setX(T x)
    {
        _width = x;
        return x;
    }

    T& setY(T y)
    {
        _height = y;
        return y;
    }

    T& setWidth(T width)
    {
        _width = width;
        return width;
    }

    T& setHeight(T height)
    {
        _height = height;
        return height;
    }
};

#endif // VECTOR_HPP

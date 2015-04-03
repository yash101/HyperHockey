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
    Vector();
    //Second constructor. Sets _width and _height from parameters
    Vector(T width, T height);
    //Constructs the Vector from another Vector
    template<typename Type> Vector(Vector<Type>& vector);

    //Adds this Vector to another to create a new Vector
    template<typename Type> Vector<T> operator+(Vector<Type> vec);
    //Substracts another Vector from this Vector to create a new Vector
    template<typename Type> Vector<T> operator-(Vector<Type> vec);
    //Adds another Vector to this Vector
    template<typename Type> Vector<T>& operator+=(Vector<Type> vec);
    //Substracts another Vector to this Vector
    template<typename Type> Vector<T>& operator-=(Vector<Type> vec);
    //Calculates the dot product
    template<typename Type> Vector<T> operator*(Vector<Type> vec);
    //Scales this vector by scalar
    template<typename Type> T operator*(Type scalar);
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
    T& x();
    T& y();
    T& width();
    T& height();

    T getX();
    T getY();
    T getWidth();
    T getHeight();

    T& setX(T x);
    T& setY(T y);
    T& setWidth(T width);
    T& setHeight(T height);
};

#endif // VECTOR_HPP

#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T> class Vector
{
private:
    T _width;
    T _height;
public:
    Vector();
    Vector(T width, T height);

    template<typename Type> Vector<T> operator+(Vector<Type> vec);
    template<typename Type> Vector<T> operator-(Vector<Type> vec);
    template<typename Type> Vector<T>& operator+=(Vector<Type> vec);
    template<typename Type> Vector<T>& operator-=(Vector<Type> vec);
    template<typename Type> Vector<T> operator*(Vector<Type> vec);
    template<typename Type> T operator*(Type scalar);
    template<typename Type> Vector<T>& operator*=(Type scalar);

    template<typename Type> bool operator==(Vector<Type> vec);
    template<typename Type> bool operator!=(Vector<Type> vec);

    template<typename Type> Vector<T>& operator=(Vector<Type> vec);

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

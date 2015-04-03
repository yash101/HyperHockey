#include "vector.hpp"

template<typename T> Vector<T>::Vector() : _width(0), _height(0)
{
}

template<typename T> Vector<T>::Vector(T width, T height) : _width(width), _height(height)
{
}

template<typename T> template<typename Type> Vector<T> Vector<T>::operator+(Vector<Type> x)
{
    return Vector<T>(_width + x._width, _height + x._height);
}

template<typename T> template<typename Type> Vector<T> Vector<T>::operator-(Vector<Type> x)
{
    return Vector<T>(_width - x._width, _height - x._height);
}

template<typename T> template<typename Type> Vector<T>& Vector<T>::operator+=(Vector<Type> x)
{
    _width += x._width;
    _height += x._height;
    return *this;
}

template<typename T> template<typename Type> Vector<T>& Vector<T>::operator-=(Vector<Type> x)
{
    _width -= x._width;
    _height -= x._height;
    return *this;
}

template<typename T> template<typename Type> T Vector<T>::operator*(Vector<Type> x)
{
    return (_width * x._width) + (_height * x._height);
}

template<typename T> template<typename Type> Vector<T> Vector<T>::operator*(Type scalar)
{
    return Vector<T>(_width * scalar, _height * scalar);
}

template<typename T> template<typename Type> Vector<T>& Vector<T>::operator*=(Type scalar)
{
    _width *= scalar;
    _height *= scalar;
    return *this;
}

template<typename T> template<typename Type> bool Vector<T>::operator==(Vector<Type> vec)
{
    return vec._width == _width && vec._height == _height;
}

template<typename T> template<typename Type> bool Vector<T>::operator!=(Vector<Type> vec)
{
    return vec._width != _width || vec._height != _height;
}

template<typename T> template<typename Type> Vector<T> Vector<T>::operator=(Vector<Type> vec)
{
    _width = vec._width;
    _height = vec._height;
    return *this;
}

template<typename T> Vector<T>::x()
{
    return _width;
}

template<typename T> Vector<T>::y()
{
    return _height;
}

template<typename T> Vector<T>::width()
{
    return _width;
}

template<typename T> Vector<T>::height()
{
    return _height;
}

template<typename T> Vector<T>::getX()
{
    return _width;
}

template<typename T> Vector<T>::getY()
{
    return _height;
}

template<typename T> Vector<T>::setX(T x)
{
    _width = x;
    return x;
}

template<typename T> Vector<T>::setY(T y)
{
    _height = y;
    return y;
}

template<typename T> Vector<T>::setWidth(T width)
{
    _width = width;
    return width;
}

template<typename T> Vector<T>::setHeight(T height)
{
    _height = height;
    return height;
}

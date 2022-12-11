#ifndef header_h
#define header_h

////
///
///
///
///
/////
#include <iostream>
#include <complex>


template <class T>
class
{
private:
    T* data;
    size_t size;
    size_t capacity;
    size_t grow_size;
    void ExCapacity(const size_t n, const size_t index = 0, const bool end_insertion = true);
public:
    Vector() : data(NULL), size(0), capacity(0), grow_size(10) {}
    Vector(const size_t size)
    {
        grow_size = 10;
        this->size = size;
        capacity = size + grow_size;
        data = new T[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = 0;
        }
    }
    ~Vector() { delete[] data; }
    Vector(const Vector& rhs);
    void Clear();
    size_t GetSize() const;
    const T* GetData() const;
    void Print() const;
    void Pif() const;
    void PushBack(const T& value);
    void Insert(const T& value, const size_t index);
    void Erase(const size_t index);
    Vector <T> & operator=(const Vector <T> & rhs);
    T& operator[] (const size_t index);
    T operator[](const size_t index) const;
    Vector <T> & operator+= (const Vector <T> & rhs);
    Vector operator+(const Vector <T> & rhs) const;
    Vector <T> & operator-= (const Vector <T> & rhs);
    Vector operator-(const Vector <T> & rhs) const;
    
    Vector <T>& operator*=(const T& value);
    Vector operator*(const T& value) const;
    Vector <T>& operator/=(const float& value);
    Vector operator/(const T& value) const;
    bool operator==(const Vector <T>& rhs) const;
    bool operator!=(const Vector <T>& rhs) const;
    
    
    T DotProduct(const Vector <T> & rhs) const
    {
        if (size != rhs.size) throw "Bad dimensions,change that";
        float scalar = 0;
        for (size_t i = 0; i < size; i++)
        {
            //scalar += data[i] * rhs.data[i];
            scalar = scalar + data[i] * rhs.data[i];
        }
        return scalar;
    }
    
    float duct(const Vector& rhs) const
    {
        if (size != rhs.size) throw "Bad dimensions,change that";
        float scalar = 0;
       // float s = 0;
        for (size_t i = 0; i < size; i++)
        {
            scalar += data[i] * rhs.data[i];
            
        }
        return scalar;
    }
    
    
    
    //
    

};
template<class T>
    Vector & operator*=(const T& value, Vector<T>& rhs);
template<class T>
    Vector operator*(const T& value, const Vector<T>& rhs);
template<class T>
    std::ostream& operator<< (std::ostream& out, const Vector<T>& vector);




//template<class T>
template<>
std::complex<float> Vector<std::complex<float>>::DotProduct(const Vector<std::complex<float>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions,change that";
    std::complex<float> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<float>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
/*
template<class T>
std::complex<T> Vector<std::complex<T>>::DotProduct(const Vector<std::complex<T>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    std::complex<T> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<T>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
*/
//template<class T>
template<>
std::complex<double> Vector<std::complex<double>>::DotProduct(const Vector<std::complex<double>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions,change that";
    std::complex<double> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<double>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
/*
 template<class T>
 std::complex<T> Vector<std::complex<T>>::DotProduct(const Vector<std::complex<T>>& rhs) const
 {
     if (size != rhs.size) throw "Bad dimensions";
     std::complex<T> scalar = 0;
     for (size_t i = 0; i < size; i++)
     {
         scalar = scalar + std::complex<double>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
     }
     return scalar;
 }
 */
template<>
std::complex<float> Vector<std::complex<float>>::duct(const Vector<std::complex<float>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions,change that";
    std::complex<float> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<float>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
/*
template<class T>
std::complex<T> Vector<std::complex<T>>::DotProduct(const Vector<std::complex<T>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    std::complex<T> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<T>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
*/
//template<class T>
template<>
std::complex<double> Vector<std::complex<double>>::duct(const Vector<std::complex<double>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions,change that";
    std::complex<double> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<double>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
/*
template<class T>
std::complex<T> Vector<std::complex<T>>::DotProduct(const Vector<std::complex<T>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    std::complex<T> scalar = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar = scalar + std::complex<T>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
    }
    return scalar;
}
*/





template <class T>
void Vector <T>:: ExCapacity(const size_t n, const size_t ind, const bool end_insert)
{
    size_t new_capacity = capacity + n;
    T* new_data = new T[new_capacity];
    if (end_insert)
    {
        for (size_t i = 0; i < new_capacity; i++)
        {
            if (i == size) break;
            new_data[i] = data[i];
        }
    }
    else
    {
        for (size_t i = 0; i < new_capacity; i++)
        {
            if (i == ind) break;
            new_data[i] = data[i];
        }
        data[ind] = 0;
        for (size_t i = ind + 1; i < new_capacity; i++)
        {
            if (i == size) break;
            new_data[i] = data[i - 1];
        }
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}


template <class T>
void Vector<T>::Insert(const T& value, const size_t index)
{
    if (index > size) throw std::out_of_range("Index is out of range,change that");
    if (size == 0 && capacity == 0 && data == NULL)
    {
        data = new T[grow_size];
        data[size] = value;
        size++;
    }
    else
    {
        if (size + 1 >= capacity)  ExCapacity(grow_size);
        for (size_t i = size + 1; i > index; --i)
        {
            std::swap(data[i], data[i - 1]);
        }
        data[index] = value;
        size++;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T>& rhs) :size(rhs.size), capacity(rhs.capacity)
{
    if (size)
    {
        data = new T[capacity];
        for (size_t i = 0; i < capacity; ++i)
        {
            if (i == size) break;
            data[i] = rhs.data[i];
        }
        grow_size = rhs.grow_size;
    }
    else
    {
        data = 0;
        grow_size = 10;
    }
}

template <class T>
void Vector <T>::Clear()
{
    delete[] data;
    data = NULL;
    size = 0;
    capacity = 0;
}

template <class T>
size_t Vector <T>::GetSize() const
{
    return size;
}
template <class T>
const T* Vector<T>::GetData() const
{
    return data;
}

template <class T>
void Vector<T>::Print() const
{
    if (!size)
    {
        std::cout << "Empty vector" << std::endl;
        return;
    }
    std::cout << "[";
    for (size_t i = 0; i < size - 1; i++)
    {
        std::cout << data[i] << " , ";
    }
    std::cout << data[size - 1] << "] , dimension of the vector:" << size << std::endl;
}

template <class T>
void Vector<T>::PushBack(const T& value)
{
    if (size == 0 && capacity == 0 && data == NULL)
    {
        data = new T[capacity + grow_size];
        data[size] = value;
        size++;
        capacity += grow_size;
    }
    else
    {
        if (size + 1 >= capacity)  ExCapacity(grow_size);
        data[size] = value;
        size++;
    }
}

template <class T>
Vector <T> & Vector <T> ::operator=(const Vector<T>& rhs)
{
    if (this == &rhs) return *this;
    if (size != rhs.size)
    {
        delete[] data;
        data = new T[rhs.size];
        for (size_t i = 0; i < rhs.size; i++)
        {
            data[i] = rhs.data[i];
        }
        size = rhs.size;
    }
    else
    {
        for (size_t i = 0; i < rhs.size; i++)
        {
            data[i] = rhs.data[i];
        }
    }
    grow_size = rhs.grow_size;
    capacity = rhs.capacity;
    return *this;
}

template <class T>
void Vector<T>::Erase(const size_t index)
{
    if (size == 0) return;
    if (index >= size) throw std::out_of_range("The index is not in the array");
    for (size_t i = index; i < size - 1; ++i)
    {
        std::swap(data[i], data[i + 1]);
    }
    size--;
}

template <class T>
T& Vector<T>::operator[] (const size_t index)
{
    if (index >= size) throw std::out_of_range("The index is not in the array");
    return data[index];
}

template <class T>
T Vector<T>::operator[](const size_t index) const
{
    if (index >= size) throw std::out_of_range("The index is not in the array");
    return data[index];
}

template <class T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& rhs)
{
    if (size != rhs.size) throw "Check the dimensions";
    for (size_t i = 0; i < size; i++)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}

template <class T>
Vector <T> Vector<T>::operator+(const Vector<T>& rhs) const
{
    if (size != rhs.size) throw "Check the dimensions";
    Vector res(*this);
    res += rhs;
    return res;
}

template <class T>
Vector<T>& Vector<T>::operator-= (const Vector<T>& rhs)
{
    if (size != rhs.size) throw "Check the dimensions";
    for (size_t i = 0; i < size; i++)
    {
        data[i] -= rhs.data[i];
    }
    return *this;
}

template <class T>
Vector <T> Vector<T>::operator-(const Vector<T>& rhs) const
{
    if (size != rhs.size) throw "Check the dimensions";
    Vector result(*this);
    result -= rhs;
    return result;
}

template <class T>
Vector<T>& Vector<T>::operator*=(const T& value)
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] *= value;
    }
    return *this;
}

template <class T>
Vector <T> Vector <T>::operator*(const T& value) const
{
    Vector result(*this);
    result *= value;
    return result;
}

template <class T>
Vector <T>& Vector<T>::operator/=(const T& value)
{
    if (value == 0) throw "!!!!!Division by zero is prohibited!!!!!";
    for (size_t i = 0; i < size; i++)
    {
        data[i] /= value;
    }
    return *this;
}

template <class T>
Vector <T> Vector <T>::operator/(const T& value) const
{
    Vector result(*this);
    result /= value;
    return result;
}

template <class T>
bool Vector <T>::operator==(const Vector<T>& rhs ) const
    if (size != rhs.size) return false;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(data[i] - rhs.data[i]) > 0 ) return false;
    }
    return true;
}


template <class T>
bool Vector<T>::operator!=(const Vector<T>& rhs) const
{
    return !(*this == rhs);
}
template <class T>
Vector<T>& operator*=(const T& value, Vector<T>& rhs)
{
    rhs *= value;
    return rhs;
}

template <class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs)
{
    Vector result(rhs);
    result *= value;
    return result;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const Vector <T>& vector)
{
    size_t size = vector.GetSize();
    if (!size)
    {
        out << "Empty vector" << std::endl;
        return out;
    }
    out << "[";
    for (size_t i = 0; i < size - 1; i++)
    {
        out << vector[i] << " , ";
    }
    out << vector[size - 1] << "] , dimension of the vector:" << size << std::endl;
    return out;

}
#endif 



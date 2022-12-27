



#ifndef Header_h
#define Header_h






#include <iostream>
#include <complex>
template <class T>
class Vector
{
private:
    T* data;
    size_t size;
    size_t capacity;
    size_t grow_size;
    void ExpandCapacityByN(const size_t n, const size_t index = 0, const bool end_insertion = true);
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
    Vector(const Vector<T>& rhs);
    //Обьявление методов
    void Clear();
    size_t GetSize() const;
    const T* GetData() const;
    void Print() const;
    void PushBack(const T& value);
    void Insert(const T& value, const size_t index);
    void Erase(const size_t index);
    //Обьявление Операторов
    Vector<T>& operator=(const Vector<T>& rhs);
    T& operator[] (const size_t index);
    T operator[](const size_t index) const;
    Vector<T>& operator+= (const Vector<T>& rhs); //
    Vector operator+(const Vector<T>& rhs) const;
    Vector<T>& operator-= (const Vector<T>& rhs);
    Vector operator-(const Vector<T>& rhs) const;
    Vector<T>& operator*=(const T& value);
    Vector operator*(const T& value) const;
    Vector<T>& operator/=(const T& value);
    Vector operator/(const T& value) const;
    bool operator==(const Vector<T>& rhs) const;
    bool operator!=(const Vector<T>& rhs) const;
  
    
    T DotProduct(const Vector<T>& rhs) const
    {
        if (size != rhs.size) throw "Bad dimensions";
        float scalar_product = 0;
        for (size_t i = 0; i < size; i++)
        {
            scalar_product += data[i] * rhs.data[i];
        }
        return scalar_product;
    }
};
template<class T>
Vector<T> & operator*=(const T& value, Vector<T>& rhs);
template<class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs);
template<class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs);
template<class T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& vector);






template<>
std::complex<float> Vector<std::complex<float>>::DotProduct(const Vector<std::complex<float>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    std::complex<float> scalar_product = 0;
    for (size_t i = 0; i < size; i++)
    {
        scalar_product += std::complex<double>(data[i].real() * rhs.data[i].real() - data[i].imag() * rhs.data[i].imag(), data[i].real() * rhs.data[i].imag() + data[i].imag() * rhs.data[i].real());
    }
    return scalar_product;
}




template<>
std::complex<double> Vector<std::complex<double>>::DotProduct(const Vector<std::complex<double>>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    std::complex<double> scalar_product (0,0);
    for (size_t i = 0; i < size; i++)
    {
        //scalar_product += std::complex<double>(data[i].real() * rhs.data[i].real(), (-1) * data[i].imag() * rhs.data[i].imag());
        scalar_product += std::complex<double>(data[i].real() * rhs.data[i].real() - data[i].imag() * rhs.data[i].imag(), data[i].real() * rhs.data[i].imag() + data[i].imag() * rhs.data[i].real());
    }
    //return scalar_product.real();
    return scalar_product;
}

template<class T>
double DotShape(const Vector<std::complex<T>>& v1, const Vector<std::complex<T>>& v2)
{
   // if (v1.GetSize() != v2.GetSize()) throw std::exception("Size doesn't match");
    std::complex<double> result(0, 0);
    for (int i = 0; i < v1.GetSize(); i++) {
        result += std::complex<T>(v1[i].real() * v2[i].real() - v1[i].imag() * v2[i].imag(), v1[i].real() * v2[i].imag() + v1[i].imag() * v2[i].real());
    }
    return result.real();
}


template<class T>
void Vector<T>::ExpandCapacityByN(const size_t n, const size_t index, const bool end_insertion)
{
    size_t new_capacity = capacity + n;
    T* new_data = new T[new_capacity];
    if (end_insertion)
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
            if (i == index) break;
            new_data[i] = data[i];
        }
        data[index] = 0;
        for (size_t i = index + 1; i < new_capacity; i++)
        {
            if (i == size) break;
            new_data[i] = data[i - 1];
        }
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}






template<class T>
void Vector<T>::Insert(const T& value, const size_t index)
{
    if (index > size) throw std::out_of_range("Index is out of range");
    if (size == 0 && capacity == 0 && data == NULL)
    {
        data = new T[grow_size];
        data[size] = value;
        size++;
    }
    else
    {
        if (size + 1 >= capacity) ExpandCapacityByN(grow_size);
        for (size_t i = size + 1; i > index; --i)
        {
            std::swap(data[i], data[i - 1]);
        }
        data[index] = value;
        size++;
    }
}




template<class T>
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
        data = nullptr;
        grow_size = 10;
    }
}





template<class T>
void Vector<T>::Clear()
{
    delete[] data;
    data = NULL;
    size = 0;
    capacity = 0;
}






template<class T>
size_t Vector<T>::GetSize() const
{
    return size;
}



template <class T>
const T* Vector<T>::GetData() const
{
    return data;
}




template<class T>
void Vector<T>::Print() const
{
    if (!size)
    {
        std::cout << "Vector is empty" << std::endl;
        return;
    }
    std::cout << "[";
    for (size_t i = 0; i < size - 1; i++)
    {
        std::cout << data[i] << " , ";
    }
    std::cout << data[size - 1] << "] , the size of vector:" << size << std::endl;
}







template<class T>
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
        if (size + 1 >= capacity) ExpandCapacityByN(grow_size);
        data[size] = value;
        size++;
    }
}



template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
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




template<class T>
void Vector<T>::Erase(const size_t index)
{
    if (size == 0) return;
    if (index >= size) throw std::out_of_range("Index is out of range");
    for (size_t i = index; i < size - 1; ++i)
    {
        std::swap(data[i], data[i + 1]);
    }
    size--;
}



template<class T>
T& Vector<T>::operator[] (const size_t index) 
{
    if (index >= size) throw std::out_of_range("Index is out of range");
    return data[index];
}



template<class T>
T Vector<T>::operator[](const size_t index) const
{
    if (index >= size) throw std::out_of_range("Index is out of range");
    return data[index];
}


template<class T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& rhs)
{
    if (size != rhs.size) throw "Bad dimensions";
    for (size_t i = 0; i < size; i++)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}



template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    Vector result(*this);
    result += rhs;
    return result;
}


template<class T>
Vector<T>& Vector<T>::operator-= (const Vector<T>& rhs)
{
    if (size != rhs.size) throw "Bad dimensions";
    for (size_t i = 0; i < size; i++)
    {
        data[i] -= rhs.data[i];
    }
    return *this;
}



template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& rhs) const
{
    if (size != rhs.size) throw "Bad dimensions";
    Vector result(*this);
    result -= rhs;
    return result;
}



template<class T>
Vector<T>& Vector<T>::operator*=(const T& value)
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] *= value;
    }
    return *this;
}


template<class T>
Vector<T> Vector<T>::operator*(const T& value) const
{
    Vector result(*this);
    result *= value;
    return result;
}



template<class T>
Vector<T>& Vector<T>::operator/=(const T& value)
{
    if (value == (T)0) throw "Dividing by zero is prohibited";
    for (size_t i = 0; i < size; i++)
    {
        data[i] /= value;
    }
    return *this;
}



template<class T>
Vector<T> Vector<T>::operator/(const T& value) const
{
    Vector result(*this);
    result /= value;
    return result;
}


template<class T>
bool Vector<T>::operator==(const Vector<T>& rhs) const
{
    if (size != rhs.size) return false;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(data[i] - rhs.data[i]) > 0) return false;
    }
    return true;
    }
    template<>
    bool Vector<double>::operator==(const Vector<double>& rhs) const
    {
        double epsilon = 0.01;
        if (size != rhs.size) return false;
        for (size_t i = 0; i < size; i++)
        {
            if (abs(data[i] - rhs.data[i]) > epsilon) return false;
        }
        return true;
    }


template<class T>
bool Vector<T>::operator!=(const Vector<T>& rhs) const
{
    return !(*this == rhs);
}


template<class T>
Vector<T>& operator*=(const T& value, Vector<T>& rhs)
{
    rhs *= value;
    return rhs;
}


template<class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs)
{
    Vector result(rhs);
    result *= value;
    return result;
}



template<class T>
 std::ostream& operator<< (std::ostream& out, const Vector<T>& vector)
{
    size_t size = vector.GetSize();
    if (!size)
    {
        out << "Vector is empty" << std::endl;
        return out;
    }
    out << "[";
    for (size_t i = 0; i < size - 1; i++)
    {
        out << vector[i] << " , ";
    }
    out << vector[size - 1] << "] , the size of vector:" << size << std::endl;
    return out;

}


template<class T>
double operator*(const Vector<T>& v1, const Vector<T>& v2) //перегузка для комплексных чисел
{
    double result = 0.0;
    for (int i = 0; i < v1.GetSize(); i++) {
        result += (double)v1[i] * (double)v2[i];
    }
    return result;
}

template<class T>
std::complex<T> operator*(const Vector<std::complex<T>>& v1, const Vector<std::complex<T>>& v2)
{
    std::complex<T> result(0, 0);
    for (int i = 0; i < v1.GetSize(); i++) {
        result += std::complex<T>(v1[i].real() * v2[i].real() - v1[i].imag() * v2[i].imag(), v1[i].real() * v2[i].imag() + v1[i].imag() * v2[i].real());
    }
    return result;
}

template<class T>
double mylen(const Vector<T>& v) {
    double len = 0.0;
    for (int i = 0; i < v.GetSize(); i++) {
        len += std::pow(v[i], 2);
    }
    return sqrt(len);
}

template<class T>
T mylen(const Vector<std::complex<T>>& v) {
    T len = 0;
    for (int i = 0; i < v.GetSize(); i++) {
        len += std::abs(v[i]);
    }
    return len;
}

template<class T>
T square(const Vector<std::complex<T>>& v1, const Vector<std::complex<T>>& v2) {

    double cos_alfa = DotShape (v1,v2) / (mylen(v1) * mylen(v2));
    double sin_alfa = std::sqrt(1 - std::pow(cos_alfa, 2));
    double square = mylen(v1) * mylen(v2) * sin_alfa / 2;
    return square;
}

template<class T>
double square(const Vector<T>& v1, const Vector<T>& v2) {
    double cos_alfa = (v1)*(v2)/ (double)(mylen(v1) * mylen(v2));
    double sin_alfa = std::sqrt(1 - std::pow(cos_alfa, 2));
    double square = mylen(v1) * mylen(v2) * sin_alfa / 2;
    return square;
}




#endif /* Header_h */

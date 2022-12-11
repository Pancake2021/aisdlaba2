#ifndef header_h
#define header_h

////
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
        if (size != rhs.size) throw "Bad dimensions";
        float scalar = 0;
       // float s = 0;
        for (size_t i = 0; i < size; i++)
        {
            scalar += data[i] * rhs.data[i];
            
        }
        return scalar;
    }
    
    
    
    Vector& operator*=(const float& value);
    Vector operator*(const float& value) const;
    Vector& operator/=(const float& value);
    Vector operator/(const float& value) const;
    bool operator==(const Vector& rhs) const;
    bool operator!=(const Vector& rhs) const;
    

};

Vector & operator*=(const float& value, Vector& rhs);
Vector operator*(const float& value, const Vector& rhs);
std::ostream& operator<< (std::ostream& out, const Vector& vector);

void Vector:: ExCapacity(const size_t n, const size_t index, const bool end_insertion)
{
    size_t new_capacity = capacity + n;
    float* new_data = new float[new_capacity];
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

void Vector::Insert(const float& value, const size_t index)
{
    if (index > size) throw std::out_of_range("Index is out of range");
    if (size == 0 && capacity == 0 && data == NULL)
    {
        data = new float[grow_size];
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

Vector::Vector(const Vector& rhs) :size(rhs.size), capacity(rhs.capacity)
{
    if (size)
    {
        data = new float[capacity];
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

void Vector::Clear()
{
    delete[] data;
    data = NULL;
    size = 0;
    capacity = 0;
}

size_t Vector::GetSize() const
{
    return size;
}

const float* Vector::GetData() const
{
    return data;
}

void Vector::Print() const
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

void Vector::PushBack(const float& value)
{
    if (size == 0 && capacity == 0 && data == NULL)
    {
        data = new float[capacity + grow_size];
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

Vector& Vector::operator=(const Vector& rhs)
{
    if (this == &rhs) return *this;
    if (size != rhs.size)
    {
        delete[] data;
        data = new float[rhs.size];
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

void Vector::Erase(const size_t index)
{
    if (size == 0) return;
    if (index >= size) throw std::out_of_range("The index is not in the array");
    for (size_t i = index; i < size - 1; ++i)
    {
        std::swap(data[i], data[i + 1]);
    }
    size--;
}

float& Vector::operator[] (const size_t index)
{
    if (index >= size) throw std::out_of_range("The index is not in the array");
    return data[index];
}

float Vector::operator[](const size_t index) const
{
    if (index >= size) throw std::out_of_range("The index is not in the array");
    return data[index];
}

Vector& Vector::operator+= (const Vector& rhs)
{
    if (size != rhs.size) throw "Check the dimensions";
    for (size_t i = 0; i < size; i++)
    {
        data[i] += rhs.data[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    if (size != rhs.size) throw "Check the dimensions";
    Vector result(*this);
    result += rhs;
    return result;
}

Vector& Vector::operator-= (const Vector& rhs)
{
    if (size != rhs.size) throw "Check the dimensions";
    for (size_t i = 0; i < size; i++)
    {
        data[i] -= rhs.data[i];
    }
    return *this;
}

Vector Vector::operator-(const Vector& rhs) const
{
    if (size != rhs.size) throw "Check the dimensions";
    Vector result(*this);
    result -= rhs;
    return result;
}

Vector& Vector::operator*=(const float& value)
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] *= value;
    }
    return *this;
}

Vector Vector::operator*(const float& value) const
{
    Vector result(*this);
    result *= value;
    return result;
}

Vector& Vector::operator/=(const float& value)
{
    if (value == 0) throw "Division by zero is prohibited";
    for (size_t i = 0; i < size; i++)
    {
        data[i] /= value;
    }
    return *this;
}

Vector Vector::operator/(const float& value) const
{
    Vector result(*this);
    result /= value;
    return result;
}

bool Vector::operator==(const Vector& rhs ) const //, const float& value
{
    if (size != rhs.size) return false;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(data[i] - rhs.data[i]) > 0 ) return false; //&& abs(data[i] - rhs.data[i]) > value
    }
    return true;
}



bool Vector::operator!=(const Vector& rhs) const
{
    return !(*this == rhs);
}

Vector& operator*=(const float& value, Vector& rhs)
{
    rhs *= value;
    return rhs;
}

Vector operator*(const float& value, const Vector& rhs)
{
    Vector result(rhs);
    result *= value;
    return result;
}

std::ostream& operator<< (std::ostream& out, const Vector& vector)
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



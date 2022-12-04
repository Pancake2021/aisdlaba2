#include <iostream>

#include <cmath>

void GetValue(int& value)
{
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail() || std::cin.bad())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The input is incorrect, please try again" << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }
}

void GetFloatValue(float& value)
{
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail() || std::cin.bad())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The input is incorrect, please try again" << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }
}


bool IsValueInRange(const int& value, const float& left_border, const float& right_border)
{
    return (value >= left_border && value <= right_border);
}



void GetValueFromUserInRange(int& value, const float& left_border, const float& right_border, const char* condition = "")
{
    std::cout << condition;
    while (true)
    {
        GetValue(value);
        if (IsValueInRange(value, left_border, right_border))
        {
            return;
        }
        else
        {
            std::cout << "The value is not in the range, try again" << std::endl;
        }
    }
}
void MenuWorkingWithVector(Vector& vector)
{
    bool working_with_vector = true;
    while (working_with_vector)
    {
        
        std::cout << vector << std::endl;
        std::cout << "Now you are editing a vector, enter:" << std::endl;
        std::cout << "0 - Changing an element by index\n1 - Adding elements to the vector" << std::endl;
        std::cout << "2 - Division of a vector by a number\n3 - Vector multiplication by a number " << std::endl;
        std::cout << "4 - Deleting an element by index" << std::endl;
        std::cout << "5 - Inserting an element by index" << std::endl;
        std::cout << "6 - Output of an element by index \n7 - Finish working with the vector" << std::endl;
        int key = 0;
        GetValueFromUserInRange(key, (int)0, (int)9, "Enter a number from 0 to 9");
        switch (key)
        {
            case (0):
            {
                if (vector.GetSize())
                {
                    try {
                        std::cout << "Enter the index of the item to edit"<< std::endl;
                        int index = 0;
                        GetValueFromUserInRange(index,0,vector.GetSize());
                    
                        std::cout << "Enter a new value for the element" << std::endl;
                        float value = 0;
                        GetFloatValue(value);
                        vector[index] = value;
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                break;
            }
            case (1):
            {
            
                float number;
                 std::cout<<"Enter the element:" << std::endl;
                 GetFloatValue(number);
                 vector.PushBack(number);
                 break;
                
                
                
                
                
            }
            case (2):
            {
                std::cout << "Enter a scalar" << std::endl;
                int scalar = 0;
                GetValue(scalar);
                try
                {
                    vector /= scalar;
                }
                catch (const char* ex)
                {
                    std::cout << ex << " Try again" << std::endl;
                    
                }
                break;
            }
            case (3):
            {
                std::cout << "nter a scalar" << std::endl;
                int scalar = 0;
                GetValue(scalar);
                vector *= scalar;
            
                break;
            }
            case (4):
            {
                if (vector.GetSize())
                {
                    
                    std::cout << "Enter the index of the item to delete" << std::endl;
                    int index = 0;
                    GetValue(index);
                    try
                    {
                        vector.Erase(index);
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << "Try again" << std::endl;
                        
                    }
                }
                else
                {
                    std::cout << "There are no items to delete here" << std::endl;
                }
                    
                break;
            }
            
            
            case (5):
            {
                try {
                    std::cout<<"Enter the element: ";
                    float InsertNumber;
                    GetFloatValue(InsertNumber);
                    std::cout<<"Enter the index: ";
                    int InsertIndex;
                    GetValueFromUserInRange(InsertIndex,0,vector.GetSize());
                    vector.Insert(InsertNumber, InsertIndex);
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
                
                
            }
            case (6):
            {
                try {
                    std::cout<<"Enter the index: ";
                    int index;
                    GetValueFromUserInRange(index,0,vector.GetSize());
                    std::cout<<vector.operator[](index)<<std::endl;
                    
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
            }
            case (7)://finish working
            {
                working_with_vector = false;
                break;
            }
                
        }
    }
}


void Menu(float)
{
    bool function_is_working = true;
    Vector first_vector;
    Vector second_vector;
    Vector th_vector;
    while (function_is_working)
    {
        std::cout << "The first vector:" << first_vector << std::endl;
        std::cout << "\nThe second vector:" << second_vector << std::endl;
        std::cout << "Enter:\n0 - for working and editing with a single vector" << std::endl;
        std::cout << "1 - to sum two vectors \n2 - to subtract the second vector from the first" << std::endl;
        std::cout << "3 - to calculate the scalar product of two vectors \n4 - clear two vectors" << std::endl;
        std::cout << "5 - Print whether two vectors are equal or not\n6 - make the first vector equal to the second\n" << std::endl;
        std::cout << "7 - area of vectors \n8 - finish working with vectors" << std::endl;
        int key = 0;
        GetValueFromUserInRange(key, (long int)0, (long int)8, "\nEnter a number from 0 to 8");
        switch (key)
        {
        case (0):
        {
            int order_number = 0;
            GetValueFromUserInRange(order_number, (long int)1, (long int)2, "Enter the number of the vector you would like to edit");
            
            if (order_number == 1)
            {
                MenuWorkingWithVector(first_vector);
            }
            else
            {
                MenuWorkingWithVector(second_vector);
            }
            break;
        }
        case (1):
        {
            try
            {
                Vector sum = first_vector + second_vector;
                std::cout << sum;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (2):
        {
            try
            {
                Vector subtraction = first_vector - second_vector;
                std::cout << subtraction;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (3):
        {
            try
            {
                float scalar_product = first_vector.DotProduct(second_vector);
                std::cout << scalar_product << std::endl;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (4):
        {
            first_vector.Clear();
            second_vector.Clear();
            break;
        }
        case (5):
        {
            first_vector == second_vector ? std::cout << "The vectors are equal" << std::endl :
                std::cout << "Vectors are different" << std::endl;
            
            break;
        }
        case (6):
            {
                first_vector = second_vector;
                break;
            }
        case (7):
            {
                float scalar_product = first_vector.DotProduct(second_vector);
                
            
                std::cout << "scalar" << " " <<scalar_product << std::endl;
                
                float kvad1 = first_vector.duct(first_vector);
                
                std::cout << "the first squares" <<  " " <<kvad1 << std::endl;
                float kvad2 = second_vector.duct(second_vector);
                
                std::cout << "second squares" << " " << kvad2 << std::endl;
                float krvad = (scalar_product)/((sqrt(kvad1) * sqrt(kvad2)));
                std::cout << "cosine" <<  " " <<krvad << std::endl;
                float sin = sqrt (1 - (krvad*krvad));
                
                std::cout << "sin"  << " " << sin << std::endl;
                float s = 0.5 * sin * sqrt(kvad1) * sqrt(kvad2);
                std::cout << "Square" << s << std::endl;
                break;
                    }
            case (8):
                {
            function_is_working = false;
            break;
                }

            }
        }
    }
    int main()
{
        bool working_with_vectors = true;

        Menu((float)0.0);
        return 0;
    }





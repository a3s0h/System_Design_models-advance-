#include <iostream>
#include <memory>
#include "concrete_products.cpp"

class Factory
{
public:
    static std::unique_ptr<Vehicle> set_product(int type)
    {
        std::unique_ptr<Vehicle> prod = nullptr; // Initialize to nullptr  
        // if u had used traidional pointer like Vehicle* with new then its the duty of the programmer to delete the 
        // allocated memeory using "delete(object_name)" but using these smart pointers they automatically 
        // dellocates the memory once the object work is done . thereofre these  are called smart pointers 
        // also it automatically passes on the ownership form one object to other like if u had 
        //used the tradiional pointer then u have to delete manually that object 
        // but let say u forgot to delete the object then this object will have the ownership of and will not pass 
        // it to the object created in client amnd then that object would'nt be able to able to call the functions 
        // of child class

        // another advantage is thta if u forgot to delete the object in tradional pointer then the class 
        // in general the object created will not be deleted and destructor will not be called and ultimately
        // memory leak will happen therefore we use smart pointers nowadays

        // this line is the definition of smart pointer 

        switch (type)
        {
        case 1:
            prod = std::make_unique<Bike>(); // this line is the initialization of smart pointer
            break;
        case 2:
            prod = std::make_unique<Car>();
            break;
        default:
            std::cout << "Invalid Selection" << std::endl;
            break;
        }

        if (prod) // Check if prod is not nullptr
        {
            prod->create_parts();
            prod->assemble_parts();
            prod->coulouring();
        }

        return prod; // Return the created product
    }
};

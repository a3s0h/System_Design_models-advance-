#include<iostream>
#include "./products_abstract.cpp"

class Bike : public Vehicle
{
    public :
        void create_parts()
        {
            std::cout<<"Bike parts created"<<std::endl;
        }
        void assemble_parts()
        {
            std::cout<<"Bike parts assembled"<<std::endl;
        }
        void coulouring()
        {
            std::cout<<"Bike is coloured"<<std::endl;
        }
};
class Car : public Vehicle
{
    public :
        void create_parts()
        {
            std::cout<<"Bike parts created"<<std::endl;
        }
        void assemble_parts()
        {
            std::cout<<"Bike parts assembled"<<std::endl;
        }
        void coulouring()
        {
            std::cout<<"Bike parts created"<<std::endl;
        }
};
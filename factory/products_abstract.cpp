#include<iostream>


class Vehicle
{
    public : 
        virtual void create_parts() = 0;
        virtual void assemble_parts() = 0;
        virtual void coulouring() = 0;
};

// #endif
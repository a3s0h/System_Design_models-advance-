#include<iostream>
#include "factory.cpp"

int main()
{
    std::cout<<"**********Welcome to our shop************"<<std::endl;
    std::cout<<"Press 1> Bike purchase\n2> Car purchase"<<std::endl;

    int n ;
    std::cin>>n;
    std::unique_ptr<Vehicle> myVehicle = Factory::set_product(n);

}
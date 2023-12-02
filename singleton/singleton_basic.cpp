// use cases :
/*
    where you only want to make only one instance for a client object 
    eg., we'll make a logger class
*/


/*
Key takeaways : 

    In singleton we make dont want user to access the construictor so we make every constructor private and make 
    an instance variable which will be created only once by every object 

*/
#include<iostream>
#include<memory>

class Logger 
{
    static int ctr;
    static std::unique_ptr<Logger> loggerInstance;

    Logger()
    {
        ctr++;
        std::cout << "New instance created: no of instances: " << ctr << std::endl;
    }

public:
    // Now we cannot create objects as the constructor is private, therefore we will make a static function which will 
    // be creating the instance 
    static Logger* getLogger()
    {
        if (loggerInstance == nullptr)  // if the instance is not created then create one 
        {
            loggerInstance = std::unique_ptr<Logger>(new Logger());
        }
        return loggerInstance.get();  // returning a raw pointer
    }

    void logs(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }
};

int Logger::ctr = 0;           //  (type belongs to::variable_name = value)
std::unique_ptr<Logger> Logger::loggerInstance = nullptr;

int main()
{
    auto user1 = std::unique_ptr<Logger>(Logger::getLogger());
    user1->logs("this is user1 instance");

    auto user2 = std::unique_ptr<Logger>(Logger::getLogger());
    user2->logs("this is user2 instance");
}

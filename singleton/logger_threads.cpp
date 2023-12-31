
#include<iostream>
#include<memory>
#include<thread>
#include<mutex>

class Logger 
{
    static int ctr;
    static std::unique_ptr<Logger> loggerInstance;
    static std::mutex mtx;
    Logger()
    {
        ctr++;
        std::cout << "New instance created: no of instances: " << ctr << std::endl;
    }
    Logger(const Logger&);     // we are restricting copy constructor and ..
    Logger operator=(const Logger &);     //    ..= operator overloading from user therefore we made them private

public:
    // Now we cannot create objects as the constructor is private, therefore we will make a static function which will 
    // be creating the instance 
    static Logger* getLogger()
    {
        if(loggerInstance == nullptr)       // we are doing double check because locks are expensive
        {
            mtx.lock();
            if (loggerInstance == nullptr)  // if the instance is not created then create one 
            {
                loggerInstance = std::unique_ptr<Logger>(new Logger());
            }
            mtx.unlock();
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
std::mutex Logger::mtx ;


void user1Log()
{
    auto user1 = std::unique_ptr<Logger>(Logger::getLogger());
    user1->logs("this is user1 instance");
}

void user2Log()
{
    auto user2 = std::unique_ptr<Logger>(Logger::getLogger());
    user2->logs("this is user2 instance");
}


int main()
{
    std::thread t1(user1Log);
    std::thread t2(user2Log);

    t1.join();
    t2.join();
    return 0;
    
}

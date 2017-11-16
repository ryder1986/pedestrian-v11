#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
class Tools
{
public:

    Tools() {}
    inline static void prt(char *buf,const int line_no,const char *func_name,const char *file_name,char *label)
    {
        cout<<buf<<endl;
        cout<<line_no<<endl;
        cout<<func_name<<endl;
        cout<<file_name<<endl;
        cout<<label<<endl;
    }
};
#define prt(label,...) {char buf[1000];sprintf(buf,__VA_ARGS__);\
    Tools::prt(buf,__LINE__,__FUNCTION__,__FILE__,#label);}

class Test
{
public:
    Test() {}
    void fun()
    {
     //   http://blog.csdn.net/qq_31175231/article/details/77923212
        chrono::milliseconds ms{3};
        using namespace std::chrono;
        typedef duration<int,std::ratio<60*60*24*356>> days_type;
        time_point<system_clock,days_type> today = time_point_cast<days_type>(system_clock::now());
        std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;




        this_thread::sleep_for(std::chrono::seconds(3)); //休眠三秒
        prt(info,"the name is %d %s",11,"FDASFASDF" );
    }
};
#endif

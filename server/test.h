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
    inline static void prt(char *buf,const int line_no,const char *func_name,const char *file_name,char *label, char *date)
    {
        int i;
        for(i=0;date[i]!='\n';i++){}
        date[i]='\0';
        cout<<label<<':'<<buf<<'['<<date<<']'<<'['<<file_name<<':'<<line_no<<']'<<'['<<func_name<<']'<<endl;
    }
    static inline char *get_time()
    {
        chrono::time_point<chrono::system_clock,chrono::system_clock::duration>  today=chrono::system_clock::now();
        time_t t=chrono::system_clock::to_time_t(today);
        return ctime(&t);
    }

private:
    static char buffer[1000];
};
#define prt(label,...) {char buf[1000];sprintf(buf,__VA_ARGS__);\
    Tools::prt(buf,__LINE__,__FUNCTION__,__FILE__,#label,Tools::get_time());}

class Test
{
public:
    Test() {}
    void fun()
    {

        prt(info,"123");
        // cout<<Tools::get_time()<<endl;
        //   http://blog.csdn.net/qq_31175231/article/details/77923212
        //        chrono::milliseconds ms{3};
        //        using namespace std::chrono;
        //        typedef duration<int,std::ratio<60*60*24*356>> days_type;
        //        time_point<system_clock,days_type> today = time_point_cast<days_type>(system_clock::now());
        //        std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;


        //        std::chrono::seconds(epoch);

        //        this_thread::sleep_for(std::chrono::seconds(3)); //休眠三秒
        //        prt(info,"the name is %d %s",11,"FDASFASDF" );
    }
};
#endif

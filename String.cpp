#include <iostream>
#include <cstring>
using namespace std;

class String{
public:
    String();
    String(const String& other);
    String( const char* other = nullptr);       //非 const 转const时允许的，但是发过来却不行
    String& operator=(const String& other);
    String(String&& other) noexcept;
    String& operator=(String && other) noexcept;
    ~String();

private:
    char* str;
};

String:: String(){
    str = new char();
}
String:: String(const String& other){
    int size = strlen(other.str);
    str = new char[size+1];
    strcpy(str,other.str);
}
String::String(const char* other = nullptr){
    if(other == nullptr){           //当字符串为空时，需要开辟一个空间给到成员 char 中
        str = new char[1];
        *str = '\0';
    }
    else{
        int length = strlen(other);
        str == new char[length + 1];
        strcpy(str,other);
    }
}
String& String::operator=(const String &other){
    if(this != &other){
        if(!str) delete[] str;
        int length = strlen(other.str);
        str = new char[length+1];
        strcpy(str, other.str);
    }
    return *this;
}
String::String(String&& other) noexcept : str(other.str){   //使用初始化列，避免了拷贝
    other.str = nullptr;                                    //将原来的对象中的信息指向一个空，或者是将原来的对象满足一个正常析构的条件
}
String& String::operator =(String&& other) noexcept{
    if(this != &other){
        delete[] str;
        str = other.str;                                    //直接指向同一块内存，直接获得原来的资源
        other.str = nullptr;                                //被指向后再原始的指向一个空
    }
}
String:: ~String(){
    delete[] str;
    str = nullptr;
}
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
using namespace std;

/*
    全局只有一个实例：static特性，同时禁止用户自己声明并定义实例（吧构造函数设为 private）
    线程安全
    禁止赋值和拷贝
    用户通过接口获取实例：使用static类成员函数
*/


//              懒汉式， 有缺陷，非线程安全
class Singleton{
private:
    Singleton(){
        cout << " constructor called "<< endl;
    }
    Singleton(Singleton&) = delete;
    Singleton& operator= (const Singleton& other) = delete;
    static Singleton* m_instance_ptr;
public:
    ~Singleton(){
        cout << "destructor called !" << endl;
    }
    static Singleton* get_instance(){
        if(m_instance_ptr == nullptr){
             m_instance_ptr = new Singleton;
        }
       return m_instance_ptr;
    }
};
Singleton* Singleton::m_instance_ptr = nullptr;



//          线程安全的懒汉式,双重检查锁
//  锁的代价太高，因此在加锁之前就进行一次检查，这样就可以避免每次执行过程都要进行一次锁的过程
/*
    Singleton* Singleton::get_instance(){
        Lock lock;
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
        return m_instance;
    }
*/
// 由于内存读写reorder不安全

class Singleton{ 
public: 
    typedef shared_ptr<Singleton> Ptr;
    ~Singleton(){
        cout << "destructor called !"<< endl;
    }
    Singleton(Singleton&) = delete;
    Singleton& operator =(const Singleton&) = delete;
    static Ptr Get_instance(){
        if(m_instance_ptr = nullptr){       //第一次检查
            lock_guard<mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr){  //第二次检查
                m_instance_ptr = shared_ptr<Singleton> (new Singleton);
                /*
                    第一步：malloc()，得到一个指针;
                    第二步：构造器，进行初始化构造；
                    第三步：将指针指向构造好的类地址
                */
            }
        }
        return m_instance_ptr;
    }

private:
    Singleton(){

    }
    static Ptr m_instance_ptr;
    static mutex m_mutex;
};
Singleton :: Ptr Singleton::m_instance_ptr = nullptr;
mutex Singleton:: m_mutex;

//为了避免上述的reorder问题的出现，使用volatile，

atomatic<Singleton*> Singleton::m_instance;
mutex Singleton::m_mutex;
Singleton* Singleton::Get_instance(){
    Singleton* tmp = m_instance.load(memory_order_relaxed);
    atomic_thread_fence(memory_order_acquire);
    if(tmp == nullptr){
        lock_guard<mutex> lock(m_mutex);
        tmp = m_instance.load(memory_order_relaxed);
        if(tmp == nullptr){
            tmp = new Singleton;
            atomic_thread_fence(memory_order_release);
            m_instance.load(tmp, memory_order_relaxed);
        }
    }
    return tmp;
}



//  局部静态变量的懒汉式单例
class Singleton{
private:
    Singleton(){
        cout << "constructor called !" << endl;
    }
public:
    ~Singleton(){
        cout << "destructor called !" << endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton& Get_instance(){
        static Singleton instance;
        return instance;
    }
};




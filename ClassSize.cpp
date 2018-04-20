/// \brief 类的大小
///
/// 同结构体几乎差不多，不过介入了虚函数
///
/// \author HSDB
/// \date 2018-04-20

#include <iostream>
using namespace std;

// 静态数据成员放在类外
class A{
public:
    static double dd;
    char   c; 
    double d; 
    static A a;
    int i; 
};

/// 会为虚函数分配一个 4 字节的空间
class B{
public:
    virtual ~B();
    char   c;
    double d;
    int i;
};

// g++ vs 结果不一样
// g++:普通继承时，派生类和基类的内存空间没有间隔。
// vs2013：普通继承时，派生类和基类的内存空间需要独立，即先补齐基类，再分配派生类。
class C :  public A
{
    char c;
};

class D :  public C
{
    char c;
};

int main(){
    cout<<"A:"<<sizeof(A)<<"\nB:"<<sizeof(B)<<"\nC:"<<sizeof(C)<<"\nD:"<<sizeof(D); /// 24,24,32,32
    return 0;
}
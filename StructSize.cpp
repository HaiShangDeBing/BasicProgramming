/// \brief 结构体大小
///
/// 结构体默认的字节对齐
/// 1. 结构体变量的首地址能够被其最宽基本类型成员的大小所整除。
/// 2. 结构体每个成员相对于结构体首地址的偏移量（offset）都是成员自身大小的整数倍，如有需要，编译器会在成员之间加上填充字节（Internal Adding）。
/// 3. 结构体的总大小为结构体最宽基本类型成员大小的整数倍
///
/// \author HSDB
/// \date 2018-04-20

/// #pragma pack(1) 可以改变对齐方式
#include <iostream>
using namespace std;

struct A{
    char a;
    short b;
    int c;
};

struct B{
    int c;    
    short b;
    char a;
};

struct C{
    char a;
    int c;
    short b;
};

struct D{
};

int main(){
    cout<<"A:"<<sizeof(A)<<"\nB:"<<sizeof(B)<<"\nC:"<<sizeof(C)<<"\nD:"<<sizeof(D); /// 8,8,12,1
    return 0;
}
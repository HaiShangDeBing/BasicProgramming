/// \brief 函数指针
///
/// 函数指针指向的是函数而非对象。每一个函数都有一个入口地址，那么指向这个函数的函数指针便是指向这个地址。
/// 函数指针主要有两个作用：用作调用函数和做函数的参数。
///
/// \author HSDB
/// \date 2018-04-20


#include <iostream>
using namespace std;

int (*func)(int a,int b);


int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return a-b;
}

void func1(int a,int b,int (*func)(int a,int b)){
    cout<<func(a,b)<<endl;
}

// typedef int (*pf)(int a,int b);
typedef decltype(add) *pf;      // 与上等价
void func2(int a,int b,pf ptr){
    cout<<ptr(a,b)<<endl;
}

int main(){
    func = add;
    cout<<func(1,2)<<endl;
    func2(1,2,func);
    func = sub;
    cout<<func(1,2)<<endl;
    func1(1,2,func);
    return 0;
}
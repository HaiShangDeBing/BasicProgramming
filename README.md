# C++ 基础编程
## 面试问题总结
### 基类为什么需要虚析构函数？

这样做是为了当用一个基类的指针删除一个派生类的对象时，派生类的析构函数会被调用。不然会造成内存泄漏。

### 函数多个参数计算的顺序是未定义的，随不同的编译器而异

```c++
int main()
{
    
    int i = 1;
    printf("%d,%d\n", ++i, ++i);    //3,3
    printf("%d,%d\n", ++i, i++);    //5,3
    printf("%d,%d\n", i++, i++);    //6,5
    printf("%d,%d\n", i++, ++i);    //8,9
    return 0;
}
```

### 如何初始化 const 和 static 数据成员？

通常在类外初始化 static 数据成员，但是 static const 的整型 (bool，char，int，long) 可以再类声明中初始化，static const 的其他类型也必须在类外初始化(包括整型的数组)。

### 如何确保对象在抛出异常时也能被删除？

1. 放进局部对象的析构函数；

2. 使用智能指针。

### 什么是 RAII？

RAII 是 Resource Acquisition Is Initialization 的缩写，是 C++ 语言的一种管理资源、避免泄漏的惯用法。C++ 标准保证任何情况下，已构造的对象最终会销毁，即它的析构函数最终会被调用。简单的说，RAII 的做法是使用一个对象，在其构造时获取资源，在对象生命期控制对资源的访问使之始终保持有效，最后在对象析构的时候释放资源。

### new 和 malloc 的区别？

malloc 分配指定字节数的未经初始化的内存空间，返回的是 void 指针；new 操作符为一个指定类型的对象分配空能，并调用其构造函数初始化，返回的是该对象的指针。

malloc 必须要做初始化，以及将void指针转换成合适类型的指针。同时要考虑到分配的内存大小正好是你所需要的大小。当 new 操作符使用"(value)" notation，即可得到值为value的初始化。如果考虑上初始化的开销，malloc 和 new 没有性能上的差别。

### 指针和引用的区别？

指针是一个变量，存储内容是一个地址，指向内存的一个存储单元。而引用是原变量的一个别名，实质上和原变量是一个东西，是某块内存的别名。

### 函数指针和返回指针的函数

函数指针指向的是函数而非对象。每一个函数都有一个入口地址，那么指向这个函数的函数指针便是指向这个地址。

函数指针主要有两个作用：用作调用函数和做函数的参数。函数和指针的类型都需要匹配。

```c++
int (*func)(int a,int b);

int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return a-b;
}

void func1(int a,int b,int (*func)(int a,int b)){
    cout<<func(a,b);
}

int main(){
    func = add;
    cout<<func(1,2)<<endl;
    func = sub;
    cout<<func(1,2)<<endl;
    func1(1,2,func);
    return 0;
}
```

### C++ 内存对齐

在 C 中，空的 struct/class 不占有内存；在 C++ 中，空的 struct/class 通常占有 1 字节的空间，原因是编译器强行在里面放入了一个 char，这样可以使得这个 class 的不同实例化在内存中分配到独一无二的地址。

### 深拷贝和浅拷贝

浅拷贝只拷贝指向对象的指针，而不复制引用对象本身。目标对象指针和源对象指向同一片内存空间。

深拷贝拷贝引用对象本身，会另外开辟资源。拷贝结束之后，两个对象虽然存的值是相同的，但是内存地址不一样，两个对象也互不影响，互不干涉。


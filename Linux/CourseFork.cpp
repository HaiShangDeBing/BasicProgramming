/// \brief 进程线程
///
/// 进程线程
/// 
///
/// \author HSDB
/// \date 2018-04-20
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int i;
    for(i=0;i<2;i++){
        //fork();//linux
        printf("-");//输出8次
        //printf("-\n");//输出6次
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    vector<int> gifts{1,2,3,2,2};
    int n=5;
    map<int,int> count;
    for(int v:gifts){
        ++count[v];
    }
    for(auto pair:count){
        if(pair.second>n/2){
            cout<<pair.first;
            //return pair.first;
        }
    }
    cin.get();
    return 0;
}
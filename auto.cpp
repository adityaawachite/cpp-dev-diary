
#include<iostream>
using namespace std;


class student{
    public:
    mutable int qa = 0;
};
int main(){
    auto name = "ramesh";
    const student s1;
    s1.qa++;
    cout<<name<<" asked "<<s1.qa<<" quary"<<endl;
    return 0;
}
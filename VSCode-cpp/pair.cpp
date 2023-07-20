#include <iostream>
#include <string>
using namespace std;
pair<int, double> p1;
pair<int, string> newone;
int main(void)
{
    int a=8;
    string m="James";
    p1=make_pair(1,1.2);
    cout<<p1.first<<p1.second<<endl;
    newone=make_pair(a,m);
    cout<<newone.first<<newone.second<<endl;
    return 0;
}
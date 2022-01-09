#include<bits/stdc++.h>
using namespace std;
int MST1(int num)
{
    if(num==1)
        return 0;
    int x=INT_MAX, y=INT_MAX, z=INT_MAX, w=INT_MAX;
    x = MST1(num-1)+1;
    if(num%2==0)
        y = MST1(num/2)+1;
    if(num%3==0)
        z = MST1(num/3)+1;
    if (num%5==0)
        w = MST1(num/5)+1;
    return min(min(min(x,y),z),w);
}
int main()
{
    cout<<"Enter Integer Value:";
    int num;
    cin>>num;
    cout<<"Minimum Steps to 1: "<<MST1(num)<<endl;
    return 0;
}

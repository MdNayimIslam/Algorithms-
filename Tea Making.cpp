#include <bits/stdc++.h>
using namespace std;
int main()
{
    string intput;
    int Plain_Tea = 1;
    while (Plain_Tea == 1){
        cout<<"Menu: Milk/ Lemon/ Garlic "<<endl;
        cout<<"Enter Tea Type: ";
        cin >> intput;
        if( intput == "Milk"){
            cout<<"Milk Tea"<<endl;
            Plain_Tea=0;
        }
        else if( intput == "Lemon" ){
            cout<<"lemon Tea"<<endl;
            Plain_Tea=0;
        }
        else  if( intput == "Garlic" ){
            cout<<"Garlic Tea"<<endl;
            Plain_Tea=0;
        }
        else  if( Plain_Tea == 1 ){
            cout<<"Plain Tea"<<endl;
            break;
        }
    }
    return 0;
}

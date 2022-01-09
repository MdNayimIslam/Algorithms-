#include <bits/stdc++.h>
using namespace std;




//PDF-1 No-1
//Insert Sort
void Insert_Sort()

{
    int A[5]= {5,6,77,88,99};
    int ln=sizeof(A)/4;
    for(int i=1; i < ln ; i++)
    {
        int key = A[i];
        int j = i-1;

        while(j >= 0 && A[j] > key )
        {
            A[j+1] = A[j];
            j=j-1;
        }

        A[j+1] = key;
    }
    for(int i=0; i<ln; i++)
    {
        cout<<A[i];
    }
}





//PDF-3 No-1&2
// Greatest Common Divisor
int GCD(int a, int b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}




//PDF-3 No-3
//Sieve of Eratosthenes
void SOE(int n)
{
    int j,i;
    int prime[n+1]= {1};
    for( i=2; (i*i) < n; i++)
    {
        if(prime[i]==true)
        {
            j=i*i;
            while(j<=n)
            {
                prime[j]=false;
                j=j+i;
            }
        }
    }
    prime[0]=false;
    prime[1]=false;
}





//PDF-3 No-4
//Number of Divisor
int NOD(int n)
{
    int cont =0;
    for(int i=1; i<sqrt(n); i++)
    {
        if(n%i ==0)
            if(n/i==i)
            {
                cont = cont+1;
            }
            else
            {
                cont= cont+2;
            }
    }
    return cont;
}




//PDF-3 No-5
//Prime Factorization
void PRM(int n)
{
    while (n%2 ==0)
    {
        cout<<2;
        n=n/2;
    }
    for(int i=3; i<sqrt(n); i++)
    {
        while(n%i ==0)
        {
            cout<<i;
            n=n/i;

        }
    }
    if(n>2)
    {
        cout<<n;
    }
}



//PDF-4 No-1
//Euler Totient Function
int ETF(int n)
{
    int result = n;
    int s=sqrt(n);
    for(int p=2; p<s; p++)
    {
        if(n%p == 0)
        {
            while(n%p ==0)
            {
                n=n/p;
            }
            result = result - (result/p);
        }
    }
    if(n>1)
    {
        result = result - (result/n);
    }
    return result;
}



//PDF-4 No-2
//Big Mod
int BGMD( int base,int power, int mod)
{
    if(power == 0)
    {
        return 1;
    }
    else if (power%2 == 0)
    {
        return (BGMD(base,power/2,mod)*BGMD(base,power/2,mod)%mod);
    }
    else if (power%2 == 1)
    {
        return ((BGMD(base,power-1,mod)* (base%mod))%mod);
    }
}



//PDF-5 No-1
// Binary Sort
void Binary_Search()
{
    int Array[]= {1,2,3,4,5,6,7,8,9,10};
    int i,First=0,Last= sizeof(Array)/4,Middle,Search=6;
    Middle=(First+Last)/2;
    while(First<=Last)
    {
        if(Array[Middle]==Search)
        {
            cout<<Search<<" is Present at Index "<<Middle;
            break;
        }
        else if ( Array[ Middle ] < Search )
        {
            First = Middle + 1 ;
        }
        else
        {
            Last = Middle - 1;
            Middle = ( First + Last )/2 ;
        }
    }
    if(First>Last)
    {
        cout<<Search<<" is not Found!!"<<endl;
    }
}




//main function
int main()
{
    cout<<"Insert Sort:";
    Insert_Sort();

    cout<<endl<<"GCD:"<<GCD(10,16)<<endl;
    cout<<"LCM:"<<(10*16) / GCD(10,16)<<endl;
    cout<<"Insert Sort:";SOE(10);
    cout<<endl<<"Number of Divisor:"<<NOD(17)<<endl;
    cout<<"Prime Factorization:";PRM(108);

    cout<<endl<<"Euler Totien Function:"<<ETF(10)<<endl;
    cout<<"Big Mod:"<<BGMD(2,5,3)<<endl;
    Binary_Search();


    return 0;
}

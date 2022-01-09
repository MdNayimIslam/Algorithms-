#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S1,S2;
    cout<<"Enter Sequence 1:";
    cin>>S1;
    cout<<"Enter Sequence 2:";
    cin>>S2;
    int N1,N2;
    N1=S1.size();
    N2=S2.size();
    int Array[N1+1][N2+1];
    memset(Array,0,sizeof(Array));
    for(int i=1; i<=N1; i++)
    {
        for(int j=1; j<=N2; j++)
        {
            if(S1[i-1]==S2[j-1])
                Array[i][j]=1+Array[i-1][j-1];
            else
                Array[i][j]=max(Array[i-1][j],Array[i][j-1]);
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<Array[N1][N2]<<endl;
    int  i=N1;
    int j=N2;
    string LCS="";
    while(Array[i][j] != 0)
    {
        if(Array[i][j] == Array[i][j-1])
            j--;
        else if(Array[i][j] == Array[i-1][j])
            i--;
        else
        {
            LCS.push_back(S1[i-1]);
            i--;
            j--;
        }
    }
    reverse(LCS.begin(),LCS.end());
    cout<<LCS<<endl;
    return 0;
}

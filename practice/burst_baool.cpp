#include<iostream>
using namespace std;
int main(){

    int N;
    cin>>N;
    int a[N+2],dp[N+4][N+4];
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    a[0]=1;
    a[N+1]=1;
    for(int i=0;i<=N+2;i++){
        for(int j=0;j<=N+2;j++)
            dp[i][j]=0;
    }


    for(int len=1;len<=N;len++){

        for(int left=1;left<N-len+2;left++)
        {
           int  right = left+len-1;

           for(int last=left;last<=right;last++){

               dp[left][right] = max(dp[left][right],dp[left][last-1]+(a[left-1]*a[right+1])+
               dp[last+1][right]);
           }
        }

    }



    cout<<dp[1][N];


    
}
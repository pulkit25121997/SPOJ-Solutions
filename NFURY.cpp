/*
ID: pulkit_chawla
LANG: C++
TASK: NFURY
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1001];
void preCompute(){
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<1001;i++){
        int k=sqrt(i);
        dp[i]=i;
        for(int j=0;j<=k;j++){
            dp[i]=min(dp[i], 1+dp[i-j*j]);
        }
    }
}
int main()
{
    preCompute();
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }

}
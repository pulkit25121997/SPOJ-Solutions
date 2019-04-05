/*
Code Written by : Pulkit Chawla
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int test;
    fin>>test;
    while(test--)
    {
        int n;
        fin>>n;
        int arr[n];
        int dp[n+10]={0};
        for(int i=0;i<n;i++){
            fin>>arr[i];
        }
        for(int i=n-1;i>=0;--i)   
        {
         dp[i]=arr[i]+dp[i+2];
         if(i+1<n)
            dp[i]=max(dp[i],arr[i]+arr[i+1]+dp[i+4]);
         if(i+2<n)   
            dp[i]=max(dp[i],arr[i]+arr[i+1]+arr[i+2]+dp[i+6]);
      }
      fout<<dp[0]<<endl;
    }
    return 0;
}
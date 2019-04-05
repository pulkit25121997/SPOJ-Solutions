/*
Code Written by : Pulkit Chawla 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    while(str!="0"){
        int n=str.size();
        int dp[n];
        dp[0]=1;
        int t=(str[0]-'0')*10+(str[1]-'0');
        if(t<27 && t>9){
            dp[1]=dp[0]+1;
        }
        else{
            dp[1]=dp[0];
        }
        for(int i=2;i<n;i++){
            if(str[i]!='0'){
                dp[i]=dp[i-1];
            }
            t=(str[i-1]-'0')*10+(str[i]-'0');
            if(t>9 && t<27){
                dp[i]=dp[i]+dp[i-2];
            }
        }
        cout<<dp[n-1]<<endl;
        cin>>str;
    }
    return 0;
}
/*
Code Written by : Pulkit Chawla
*/
#include<bits/stdc++.h>
using namespace std;
int recursiveSolve(int arr[], int ind, int low, int high, int day)
{
    if(low>high+1){
        return 0;
    }
    int ans=arr[ind]*day;
    int c1 = recursiveSolve(arr, low, low+1, high, day+1);
    int c2 = recursiveSolve(arr, high, low, high-1, day+1);
    return ans+max(c1,c2);
}
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int n;
    fin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        fin>>arr[i];
    }
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        dp[i][i] = arr[i-1]*n;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int k = i,j = n;k>=1  && j>=1 ; j--,k--)
        {
            int y = n - (j-k+1) + 1;
            dp[k][j] = max( dp[k+1][j] + arr[k-1]*y , dp[k][j-1] + arr[j-1]*y );
        }
    }
    fout<<dp[1][n]<<endl;
    //fout<<max(recursiveSolve(arr, n-1, 0, n-2, 1), recursiveSolve(arr, 0, 1, n-1, 1))<<endl;
    return  0;
}
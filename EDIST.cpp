#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z){
    return min(min(x,y), z);
}
int EditDistance(string str1, string str2){
    int m=str1.size();
    int n=str2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int test;
    fin>>test;
    while(test--){
        string str1, str2;
        fin>>str1>>str2;
        fout<<EditDistance(str1, str2)<<endl;
    }
    return 0;
}
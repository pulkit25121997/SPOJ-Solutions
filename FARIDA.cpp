/*
Code written by: Pulkit Chawla
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll arr[], int n)
{   
    ll b[n]={0};
    b[0]=arr[0];
    b[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        b[i]=max(b[i-2]+arr[i],b[i-1]);
    }
    return b[n-1];
}
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int test;
    fin>>test;
    for(int i=0;i<test;i++){
        int n;
        fin>>n;
        ll arr[n];
        for(int j=0;j<n;j++){
            fin>>arr[j];
        }
        fout<<"Case "<<i+1<<": "<<solve(arr,n)<<endl;
    }
    return 0;
}
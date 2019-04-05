/*
Code Written by : Pulkit Chawla
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int n,k;
    fin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    for(int i=0;i<n;i++){
        fin>>b[i];
    }
    int i;
    for(i=0;i<n;i++){
        int temp=a[i];
        a[i]=min( (a[i-1]+a[i]) , (b[i-1]+b[i]+a[i]));
        b[i]=min((b[i-1]+b[i]) , (a[i-1]+temp+b[i]));
        if(min(a[i],b[i])>k){
            break;
        }
    }
    if(i==n){
        fout<<n<<" "<<min(a[n-1],b[n-1]);
    }
    else{
        fout<<i<<" "<<min(a[i-1],b[i-1]);
    }
    return 0;
}
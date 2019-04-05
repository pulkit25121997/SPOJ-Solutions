/*
ID: pulkit_chawla
LANG: C++
TASK: NY10E
*/
#include<bits/stdc++.h>
using namespace std;
long long int countNonDecreasing(int n) 
{ 
    int N = 10; 
    // Compute value of N*(N+1)/2*(N+2)/3* ....*(N+n-1)/n 
    long long count = 1; 
    for (int i=1; i<=n; i++) 
    { 
        count *= (N+i-1); 
        count /= i; 
    } 
  
    return count; 
} 
int main()
{
    int test;
    cin>>test;
    while(test--){
        int t,n;
        cin>>t>>n;
        cout<<t<<" "<<countNonDecreasing(n)<<endl;
    }
    return 0;
}
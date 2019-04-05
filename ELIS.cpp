#include<bits/stdc++.h>
using namespace std;
int LIS(int arr[], int n){
    int LIS[n];
    LIS[0]=1;
    for(int i=1;i<n;i++){
        LIS[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && (LIS[i]<LIS[j]+1)){
                LIS[i]=LIS[j]+1;
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(LIS[i]>maxi){
            maxi=LIS[i];
        }
    }
    return maxi;
}
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<LIS(arr,n)<<endl;
    return 0;
}
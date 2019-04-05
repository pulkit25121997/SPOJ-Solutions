/*
Code written by : Pulkit Chawla
*/
#include<bits/stdc++.h>
using namespace std;
int knapSack(int k, vector<int> &weight, vector<int> &value, int m){ 
   int K[m+1][k+1];
   for(int i = 0; i <= m; i++) 
   { 
       for(int w = 0; w <= k; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (weight[i-1] <= w) 
                 K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[m][k];
}
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int test;
    fin>>test;
    while(test--){
        int k, m;
        fin>>k>>m;
        vector<int> weight(m);
        vector<int> value(m);
        for(int i=0;i<m;i++){
            int a,b;
            fin>>a>>b;
            weight[i]=a;
            value[i]=b;
        }
        fout<<"Hey stupid robber, you can get "<<knapSack(k, weight, value, m)<<"."<<endl;
    }
    return 0;  
}
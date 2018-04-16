#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int A[200001];
ll dp[200001][3];
int n;
ll solve( int idx,int prev,int k){
    if(k==0){ return 1; }
    if(idx == n){ return 0; }
    if(dp[idx][k]!=-1){ return dp[idx][k]; }
    if(A[idx]>prev)
        ll a = A[idx]*solve(idx+1,A[idx],k-1);
}

int main()
{
   int n;
   cin>>n;
   for (int i = 0; i < n; ++i)
       {
          cin>>A[i];
       }    
     memset(dp,-1,sizeof(dp));
       cout<<solve(0,3)<<endl;
}
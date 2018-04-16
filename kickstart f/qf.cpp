#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   int n,m,k;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
        cin>>arr[i];
   }
   cin>>m;
   ll sum=0;
   int maxi=0;
   for(int j=0;j<m;j++)
   {
       cin>>k;
       maxi=max(maxi,k);
   }
   // cout<<maxi<<endl;
   for(int i=0;i<n;i++)
   {
       if(arr[i]<=maxi)
       {
           sum+=maxi-arr[i]+1;
       }
   }
   cout<<sum<<endl;
   
    return 0;
}

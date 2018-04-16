#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    double n,m,x;
    cin>>n>>m;
    double sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        sum=sum+((x+m)*(x+m-1))/2-(x*(x-1))/2;
    }
    
    
    printf("%.6lf\n",sum);
    
}
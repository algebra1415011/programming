#include "bits/stdc++.h"
#define ll long long int
using namespace std;
 
ll arr[1000001];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr.tie(0);
    ll i,val,x,n,l,r,d;
    ll vis[10];
    for(i=1;i<=1000000;i++){
        arr[i] += arr[i-1];
        memset(vis,0,sizeof(vis));
        val = i;
        d = 0;
        while(val>0){
            d++;
            val /= 10;
        }
        val = i;
        while(val){
            vis[val%10]++;
            if(!(val%10) or vis[val%10] > 1 or val%10 > d)
                break;
            val /= 10;
        }
        if(val == 0)
            arr[i] += 1;
    }
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&l);
        scanf("%lld",&r);
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
 
int tot[500005];
int toti[500005];
void prec()
{
    int i,j;
    for(i=1;i<=500000;i++)
    {
        tot[i] = i;
    }
    for(i=2;i<=500000;i++)
    {
        if(tot[i] == i)
        {
            for(j=i;j<=500000;j+=i)
            {
                tot[j] -= tot[j]/i;
            }
        }
    }
    for(i=1;i<=500000;i++)
    {
        for(j=i;j<=500000;j+=i)
        {
            toti[j] += i*tot[j/i];
        }
    }
}
ll a[1000006];
ll b[1000006];
void upd(int x,ll val)
{
    val %= MOD;
    if(val < 0)
        val += MOD;
    while(x <= 1000000)
    {
        b[x] += val;
        b[x] %= MOD;
        x += (x&-x);
    }
}
ll get(int x)
{
    ll sum = 0;
    while(x > 0)
    {
        sum += b[x];
        sum %= MOD;
        x -= (x&-x);
    }
    return sum;
}
int main()
{
    prec();
    int n,i;
    scanf("%d",&n);
    //assert(1 <= n && n <= (int)1e6);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
      //  assert(1 <= a[i] && a[i] <= 500000);
        upd(i,toti[a[i]]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c == 'U')
        {
           // assert(1 <= x && x <= n);
            //assert(1 <= y && y <= 500000);
            upd(x,-toti[a[x]]);
            a[x] = y;
            upd(x,toti[y]);
        }
        else
        {
           // assert(1 <= x && x <= n);
            //assert(x <= y && y <= n);
            ll ans = (get(y) - get(x-1) + MOD)%MOD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
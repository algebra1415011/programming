#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
 
#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
 
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 
typedef long long int slong;
typedef pair<int, int> pii;
typedef pair<slong, slong> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
#ifdef VSP4 
    #include "debug.h"    
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif
 
const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
 
const int MAXN = 3e4;
const int SQRTN = 550;
const int LOGN = 60;
const int INT_INFINITY = 1001001001;
const int LIMIT = 100;
 
const slong LONG_INFINITY = 1001001001001001001ll;
const slong LONG_LIMIT = 200100100100101ll;
 
int n, q, k;
int arr[MAXN+5];
int prefixXor[MAXN+5];
 
int addCount[MAXN+5];
 
vector<pii> queries[MAXN+5];
slong answer[MAXN+5];
 
int main()
{
	#ifdef VSP4
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	cin.tie(0);
	
	int t, i, j, l, r;
	
	cint3(n, q, k);
	
	for (i = 1; i <= n; i++)
	{
		cint(arr[i]);
		prefixXor[i] = arr[i]^prefixXor[i-1];
	}
	
	for (i = 1; i <= q; i++)
	{
		cint2(l, r);
		queries[l].eb(r, i);
	}
	
	for (i = n; i >= 1; i--)
	{
		{
			for (j = i; j <= n; j++)
			{
				if ((prefixXor[j]^prefixXor[i-1]) < k)
				{
					addCount[j]++;
				}
			}
		}
		
		slong curr = 0;
		int lastindex = i-1;
		
		sort(ALL(queries[i]));
		
		for (auto &p: queries[i])
		{
			for (j = lastindex+1; j <= p.fi; j++)
			{
				curr += addCount[j];
			}
			lastindex = p.fi;
			answer[p.se] = curr;
		}
	}
	
	for (i = 1; i <= q; i++)
	{
		printf("%lld\n", answer[i]);
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
#define SIZE 1000010
const ll mod = 1000000007L;
ll dp[2][SIZE];
bool vis[2][SIZE];
vector<ll> vec[2][SIZE];
int ar[SIZE];
int n;
void dfs(int t, int v)
{
	if (vis[t][v] || v > n)
		return;
	dp[t][v] = 1;
	vis[t][v] = 1;
	for (int i : vec[t][v])
	{
		//cout << t << " " << v << " " << i << endl;
		if (!vis[t][i])
		{
			dfs(t, i);
			dp[t][v] += dp[t][i];
		}
		else
			dp[t][v] += dp[t][i];
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> ar[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (ar[i] == 1)
			vec[1][i].pb(i + 1), vec[0][i + 1].pb(i);
		else
			vec[1][i + 1].pb(i), vec[0][i].pb(i + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[1][i])
			dfs(1, i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[0][i])
			dfs(0, i);
	}
	//dfs(0, 1);
	// for (int i = 0; i < 2; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;
	int x = 1;
	int q;
	cin >> q;
	while (q--)
	{
		char ch;
		int v;
		cin >> ch;
		if (ch == 'U')
			x = 1 - x;
		else
		{
			cin >> v;
			cout << dp[x][v] << endl;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int A[100005], parent[100005];
int maxDiff[100005], minDiff[100005];
vector<int> X[100005], Y;

void dfs(int i, int par)
{
    parent[i] = par;
    int maxx = 0, minn = 0;
    
    for(int j=0; j<X[i].size(); j++)
    {
        if(X[i][j] == par)
            continue;
        
        dfs(X[i][j], i);
        maxx += max(0, maxDiff[ X[i][j] ]);
        minn += max(0, -minDiff[ X[i][j] ]);
    }
    
    maxx = maxx + (A[i] == 1 ? 1 : -1);
    minn = -minn + (A[i] == 1 ? 1 : -1);
    
    maxDiff[i] = maxx, minDiff[i] = minn;
}

void func(int i, int flag)
{
    Y.push_back(i);
    
    for(int j=0; j<X[i].size(); j++)
    {
        if(X[i][j] == parent[i])
            continue;
        
        if(flag == 1)
        {
            if(maxDiff[ X[i][j] ] > 0)
                func(X[i][j], flag);
        }
        else
        {
            if(minDiff[ X[i][j] ] < 0)
                func(X[i][j], flag);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++)
        cin >> A[i];
    
    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        
        X[u].push_back(v);
        X[v].push_back(u);
    }
    
    dfs(1, 0);
    
    int ans = 0;
    
    for(int i=1; i<=n; i++)
        ans = max(ans, max(maxDiff[i], -minDiff[i]));
    
    cout << ans << endl;
    
    for(int i=1; i<=n; i++)
        if(maxDiff[i] == ans || -minDiff[i] == ans)
        {
            func(i, (maxDiff[i] == ans));
            
            cout << Y.size() << endl;
            
            for(int i=0; i<Y.size(); i++)
                cout << Y[i] << " ";
            cout << endl;
            
            return 0;
        }
    
    return 0;
}
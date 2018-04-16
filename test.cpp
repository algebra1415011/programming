#include <bits/stdc++.h>
using namespace std;
#define lln long long int 
vector <lln> adj[10005];
lln vis[100000];
stack <lln> ans;

void topo(lln x){
	vis[x] = 1;
	for(lln i=0;i<adj[x].size();i++){
		if(!vis[adj[x][i]])
			topo(adj[x][i]);
	}
	ans.push(x);
}

int main(){
	lln n,m;
	cin >> n >> m;
	multimap <lln,lln> mp;
	multimap <lln,lln> :: iterator it;
	memset(vis,0,sizeof vis);
	for(lln i=0;i<m;i++){
		lln x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		it = mp.find(y);
		if(it->second==x){
			cout << "Sandro fails." << endl;
			return 0;
		}
		mp.insert(make_pair(x,y));
	}
	for(lln i=1;i<=n;i++){
		if(!vis[i])
			topo(i);
	}
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
	return 0;
}
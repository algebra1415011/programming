#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll> > v[1000001];
bool visited[1000001];
ll cost[1000001];

ll value;
map<ll,pair<ll,ll> > papa;
ll level[1000001];
vector<ll> eulertoor;
vector<ll> leveleulertoor;
ll firstoccurance[1000010];
ll Tree[1000010];


void bfs(ll s)
{
	queue<ll> q;
	q.push(s);
	visited[s]=1;
	level[s]=0;
	while(!(q.empty()))
	{
		ll current=q.front();
		//cout<<current<<" ";
		q.pop();
		for(ll i=0;i<v[current].size();i++)
		{
			if(!visited[v[current][i].first])
			{
				level[v[current][i].first]=level[current]+1;
			
				visited[v[current][i].first]=1;
				papa[v[current][i].first].first=current;
                papa[v[current][i].first].second=v[current][i].second;
				q.push(v[current][i].first);
			}
		}
	}
}
 
 
void dfs(ll s)
{
    
 	//eulertoor.push_back(s);
	
	visited[s]=true;
	  // cout<<s<<" "<<mon<<" "<<freeticket<< endl;
	for(ll i=0;i<v[s].size();i++)
		if(!visited[v[s][i].first] )
        {
           leveleulertoor.push_back(level[s]);
            eulertoor.push_back(s);
            dfs(v[s][i].first);
               
        }
    leveleulertoor.push_back(level[s]);
        eulertoor.push_back(s);
    
	
						
}
 
 


void build(ll pos,ll start,ll end)
{
	//cout<<pos<<" "<<start<<" "<<end<<endl;
	if(start==end)
		{
			Tree[pos]=leveleulertoor[end];
			
		}	
	else
	{
		ll mid=(start+end)/2;
		build(2*pos+1,start,mid);
		build(2*pos+2,mid+1,end);
		Tree[pos]=min(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}

void update (ll pos,ll start,ll end,ll idx,ll val)
{
	if(start==end)
	{
		leveleulertoor[start]=val;
		Tree[pos]=leveleulertoor[start];	
	}
	else
	{
		ll mid=(start+end)/2;
		if(start<=idx and idx<=mid)
			update(2*pos+1,start,mid,idx,val);
		else
			update(2*pos+2,mid+1,end,idx,val);
		Tree[pos]=min(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}

ll query(ll pos,ll start,ll end,ll l,ll r)
{
	//cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
	if(r<start or end<l)
		return LLONG_MAX;
	if(l<=start and end<=r)
		return Tree[pos];
	ll mid=(start+end)/2;
	ll x=query(2*pos+1,start,mid,l,r);
	ll y=query(2*pos+2,mid+1,end,l,r);
	//cout<<"xxyy"<<x<<" "<<y<<endl;
	return min(x,y);

}

 
 
int main()
{
	ll n,m,k,a,b,w,s,d;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&cost[i]);
	for(ll i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&w);
		v[a].push_back(make_pair(b,w));
		v[b].push_back(make_pair(a,w));
	}
 
 
		bfs(1);
		for(ll i=0;i<=n;i++)
			visited[i]=false;
		
    dfs(1);
    ll len=eulertoor.size()-1;
    for(ll i=0;i<eulertoor.size();i++)
        {
        	//cout<<eulertoor[i]<<" ";

        	if(!firstoccurance[eulertoor[i]])
        		firstoccurance[eulertoor[i]]=i+1;
        }	
    //cout<<endl;
 //    for(ll i=0;i<eulertoor.size();i++)
 //        cout<<leveleulertoor[i]<<" ";
 //    cout<<endl;
	// for(ll i=1;i<=n;i++)
	// 	cout<<firstoccurance[i]<<" ";
	// cout<<endl;
	build(0,0,len);
	for(ll i=1;i<=m;i++)
	{
        // cout<<"kella"<<endl;
		scanf("%lld%lld",&s,&d);
        
        ll ancestor=eulertoor[query(0,0,len,firstoccurance[min(s,d)]-1,firstoccurance[max(s,d)]-1)];
        // cout<<"ancestor bhaiya "<<ancestor<<endl;
        ll freetickets=0;
        ll money=cost[s];
        
        map<ll,ll> mp;
        ll flag=0;
       
        //cout<<"khata"<<endl;
         while(s!=ancestor)
         {
             
             freetickets+=papa[s].second;        
             s=papa[s].first;
             mp[s]=1;
             if(freetickets>=cost[s])
                 freetickets=freetickets-cost[s];
             else
             {
                 money+=cost[s]-freetickets;
                 freetickets=0;
             }
               
         }
        //cout<<endl;
        vector<ll > vtemp;
        ll node=d;
        
        while(node!=ancestor)
        {
            // if(mp[node])
            // {
            //     flag=1;
            //     cout<<"repear"<<endl;
            //     break;
            // }
            vtemp.push_back(node);
            //cout<<node<<" ";
            node=papa[node].first;
        }
        if(flag==0)
        {
            for(ll i=vtemp.size()-1;i>=0;i--)
            {
                //cout<<"kl"<<money<<" ";
                freetickets+=papa[vtemp[i]].second;        
                if(freetickets>=cost[vtemp[i]])
                     freetickets=freetickets-cost[vtemp[i]];
                 else
                 {
                     money+=cost[vtemp[i]]-freetickets;
                     freetickets=0;
                 }
            }
        }  
        
       
		printf("%lld\n",money);
 
	}
 
 
}

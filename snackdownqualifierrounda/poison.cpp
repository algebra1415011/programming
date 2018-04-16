
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll visit[1000010];

bool comp(pair<pair<pair<ll,ll> ,ll>,ll> a, pair<pair<pair<ll,ll> ,ll > ,ll> b)
{
	return a.first.first.first<b.first.first.first;
}

int main()
{

	ll t,n;
	cin>>t;
	ll x1,x2,y1,y2,maxy2,miniy1,k,m,maxx2,minix1;
	vector<pair<pair<pair<ll,ll>,ll>,ll> > vr,vc;
	while(t--)
	{
		cin>>n>>k>>m;

		ll xtl=(n-k)/2+1;
		ll ytl=(n-k)/2+1;
		ll xtr=xtl;
		ll ytr=ytl+k-1;
		ll ybl=ytl;
		ll xbl=xtl+k-1;
		ll xbr=xtl+k-1;
		ll ybr=ytl+k-1;

		for(ll i=0;i<=m;i++)
		{
			visit[i]=0;
		}
		vr.clear();
		vc.clear();
		for(ll i=0;i<m;i++)
		{

			cin>>x1>>y1>>x2>>y2;
			if(x1==x2 && y1==y2)
			{
				//cout<<"fir"<<endl;
				if(y1>=ytl && y1<=ytr)
				{
					// cout<<"y"<<endl;
					vr.push_back(make_pair(make_pair(make_pair(y1,y1),y1-y1+1),i));
				}
				if(x1>=xtl && x1<=xbl)
				{
					// cout<<"la"<<endl;
					vc.push_back(make_pair(make_pair(make_pair(x1,x1),x1-x1+1),i));
				}
			}
			else if(x1==x2)
			{
				// cout<<"column change"<<endl;
				if(y1>=y2)
					{
						miniy1=min(y1,ytr);
						maxy2=max(y2,ytl);

						if(maxy2<=ytr && miniy1>=ytl)
							vr.push_back(make_pair(make_pair(make_pair(miniy1,maxy2),miniy1-maxy2+1),i));

					}	
				else
					{
						miniy1=min(y2,ytr);
						maxy2=max(y1,ytl);
						if(maxy2<=ytr && miniy1>=ytl)
							vr.push_back(make_pair(make_pair(make_pair(miniy1,maxy2),miniy1-maxy2+1),i));

					}	
					if(maxy2<=ytr && miniy1>=ytl)
					// cout<<maxy2<<" "<<miniy1<<endl;
					if(x1>=xtl && x1<=xbl)
					{
						// cout<<"how"<<endl;
						vc.push_back(make_pair(make_pair(make_pair(x1,x1),x1-x1+1),i));
					}

			}
			else if(y1==y2)
			{
				// cout<<"row changed"<<endl;
					if(x1>=x2)
					{
						minix1=min(x1,xbl);
						maxx2=max(x2,xtl);
						if(minix1>=xtl && maxx2<=xbl)
						vc.push_back(make_pair(make_pair(make_pair(minix1,maxx2),minix1-maxx2+1),i));

					}	
				else
					{
						minix1=min(x2,xbl);
						maxx2=max(x1,xtl);
						if(minix1>=xtl && maxx2<=xbl)
							vc.push_back(make_pair(make_pair(make_pair(minix1,maxx2),minix1-maxx2+1),i));

					}
					if(minix1>=xtl && maxx2<=xbl)
					// cout<<maxx2<<" "<<minix1<<endl;
					if(y1>=ytl && y1<=ytr)
					{
						// cout<<"kella"<<endl;
						vr.push_back(make_pair(make_pair(make_pair(y1,y1),y1-y1+1),i));
					}
			}

		}
		sort(vr.begin(),vr.end(),comp);
		sort(vc.begin(),vc.end(),comp);
		// cout<<vc.size()<<endl;
		// for(ll i=0;i<vr.size();i++)
		// 	cout<<vr[i].first.first.second<<" "<<vr[i].first.first.first<<endl;

		ll start=0;
		ll initial,ind,final;
		ll maximum_index=0;
		ll ans=0;
		ll it,ft;
		while(start<vr.size())
		{	
			
			final=vr[maximum_index].first.first.first;
			
			//cout<<start<<" "<<vr[maximum_index].first.first.second<<" "<<final<<" "<<maximum_index<<endl;
			ans++;
			visit[vr[maximum_index].second]=1;
			while(vr[start].first.first.second<=final && start<vr.size())
			{
				//cout<<"s"<<start<<" "<<vr[start].first.first.first<<" "<<vr[maximum_index].first.first.first<<endl;
				if(vr[start].first.first.first>=vr[maximum_index].first.first.first)
				{
					maximum_index=start;
					
				}
				start++;
				

			}
			
			//cout<<"nb"<<maximum_index<<endl;
			

		}
		//cout<<"hecy"<<vr[maximum_index].first.first.first<<" "<<xtr<<endl;
		if(vr[maximum_index].first.first.first<ytr)
		{
			cout<<-1<<endl;
			continue;
		}
		// for(ll i=0;i<vc.size();i++)
		// 	cout<<vc[i].first.first.second<<" "<<vc[i].first.first.first<<endl;
		start=0;
		maximum_index=0;
		while(start<vc.size())
		{	
			
			final=vc[maximum_index].first.first.first;
			
			//cout<<start<<" "<<vc[maximum_index].first.first.second<<" "<<final<<" "<<maximum_index<<endl;
			if(visit[vc[maximum_index].second]==0)
				ans++;
			visit[vc[maximum_index].second]=1;
			while(vc[start].first.first.second<=final && start<vc.size())
			{
				//cout<<"s"<<start<<" "<<vc[start].first.first.first<<" "<<vc[maximum_index].first.first.first<<endl;
				if(vc[start].first.first.first>=vc[maximum_index].first.first.first)
				{
					maximum_index=start;
					
				}
				start++;
				

			}
			
			//cout<<"nb"<<maximum_index<<endl;
			

		}
		//cout<<"hecy"<<vc[maximum_index].first.first.first<<endl;
		if(vc[maximum_index].first.first.first<xbl)
		{
			cout<<-1<<endl;
			continue;
		}
		

		swap(vr,vc);

		for(ll i=0;i<=m;i++)
		{
			visit[i]=0;
		}

		 start=0;
		 initial,ind,final;
		 maximum_index=0;
		ll res=0;
		
		while(start<vr.size())
		{	
			
			final=vr[maximum_index].first.first.first;
			
			//cout<<start<<" "<<vr[maximum_index].first.first.second<<" "<<final<<" "<<maximum_index<<endl;
			res++;
			visit[vr[maximum_index].second]=1;
			while(vr[start].first.first.second<=final && start<vr.size())
			{
				//cout<<"s"<<start<<" "<<vr[start].first.first.first<<" "<<vr[maximum_index].first.first.first<<endl;
				if(vr[start].first.first.first>=vr[maximum_index].first.first.first)
				{
					maximum_index=start;
					
				}
				start++;
				

			}
			
			//cout<<"nb"<<maximum_index<<endl;
			

		}
		//cout<<"hecy"<<vr[maximum_index].first.first.first<<" "<<xtr<<endl;
		if(vr[maximum_index].first.first.first<ytr)
		{
			cout<<-1<<endl;
			continue;
		}
		// for(ll i=0;i<vc.size();i++)
		// 	cout<<vc[i].first.first.second<<" "<<vc[i].first.first.first<<endl;
		start=0;
		maximum_index=0;
		while(start<vc.size())
		{	
			
			final=vc[maximum_index].first.first.first;
			
			//cout<<start<<" "<<vc[maximum_index].first.first.second<<" "<<final<<" "<<maximum_index<<endl;
			if(visit[vc[maximum_index].second]==0)
				res++;
			visit[vc[maximum_index].second]=1;
			while(vc[start].first.first.second<=final && start<vc.size())
			{
				//cout<<"s"<<start<<" "<<vc[start].first.first.first<<" "<<vc[maximum_index].first.first.first<<endl;
				if(vc[start].first.first.first>=vc[maximum_index].first.first.first)
				{
					maximum_index=start;
					
				}
				start++;
				

			}
			
			//cout<<"nb"<<maximum_index<<endl;
			

		}
		//cout<<"hecy"<<vc[maximum_index].first.first.first<<endl;
		if(vc[maximum_index].first.first.first<xbl)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<min(res,ans)<<endl;
		

	}
	return 0;
}
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll maxi=0;
set<char> sta,stb;
ll strmin(string a , string b , ll ind,ll len)
{
	if(ind==(len-1))
	{
		sta.clear();
		stb.clear();
		
		for(ll i=0;i<len;i++)
		{
			sta.insert(a[i]);

			stb.insert(b[i]);
		}	
		//cout<<a<<" "<<sta.size()<<" "<<b<<" "<<stb.size()<<endl;
		return max(sta.size(),stb.size());

	}
	ll ans=0;
	ans=strmin(a,b,ind+1,len);
	swap(a[ind],b[ind]);
	ans=min(ans,strmin(a,b,ind+1,len));
	return ans;

}


int main()
{
	ll t,len;
	string stra, strb;
	cin>>t;
	while(t--)
	{
		cin>>len;
		cin>>stra>>strb;
		cout<<strmin(stra,strb,0,len)<<endl;
	}
}
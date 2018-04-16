#include <bits/stdc++.h>
#define ll long long int
using namespace std;
char arr[1002][1002];
 
ll len,t,n;
ll randomgrid(ll x,ll y,ll i,ll papa,string s)
{
	
	//cout<<x<<" "<<y<<" "<<papa<<""<<endl;
	if(i==len-1)		{return papa+1;}
	if(arr[x][y]=='#')	{return papa;}
	if(x>n)				{return papa;}
	if(y>n)				{return papa;}
	if(x<=0)			{return papa;}
	if(y<=0)			{return papa;}
	i++;
	papa++;
	if(s[i]=='R') {if(arr[x][y+1]!='#')return randomgrid(x,y+1,i,papa,s);return papa;}
	else if(s[i]=='U') {if(arr[x-1][y]!='#')return randomgrid(x-1,y,i,papa,s);return papa;}/*	# 3 3 # 
																								# 3 1 0 
																								1 1 0 # 
																								0 0 # 0*/
	else if(s[i]=='D') {if(arr[x+1][y]!='#')return randomgrid(x+1,y,i,papa,s);return papa;}
	else if(s[i]=='L') {if(arr[x][y-1]!='#')return randomgrid(x,y-1,i,papa,s);return papa;}
}
 
int main(int argc, char const *argv[])
{
	cin.tie(0),cerr.tie(0),ios_base:: sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		cin>>len>>n;
		//cout<<len<<" "<<n<<endl;
		string s;
		cin>>s;	
		ll c=0;
		//cout<<s<<endl;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				{
						cin>>arr[i][j];
						if(arr[i][j]=='#')
							c++;
 
				}		
		if(c==0)
		{
			cout<<0<<endl;
			continue;
		}				
		ll xorlenahai=0;	
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				if(arr[i][j]!='#')
				{
					
			xorlenahai^=randomgrid(i,j,-1,-1,s);
		}
			cout<<xorlenahai<<endl;
	}
 
	return 0;
}
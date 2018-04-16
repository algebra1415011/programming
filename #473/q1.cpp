#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll maxi=0;
string s;
ll hua=0;
void check(string ss)
{
	ll i,l=ss.length();
	//cout<<ss<<endl;
	ll flag=0;
	if(ss[0]=='0'){
		return ;
	}
	else{
		ll num=0;
		for(i=0;i<l;i++){
			ll h=ss[i]-'0';
			num+=h;
			if(i<(l-1)){
				num*=10;
			}
		}
		//cout<<num<<endl;
		ll sq=sqrt(num);
		if((sq*sq)==num && num!=0){
			hua=1;
			//cout<<num<<endl;
			ll g=s.length()-ss.length();
			maxi=min(maxi,g);
		}
	}
}
int main()
{
	
	cin>>s;
	maxi=s.length();
	check(s);
	ll x=0;
	ll len=s.length();
	for(ll i=1;i<(1<<len);i++){
		ll xx=i;
		ll ind=0;
		string temp="";
		while(xx>0){
			ll k=xx%2;
			if(k==1){
				temp+=s[ind];
			}
			ind++;
			xx/=2;
		}
		check(temp);
	}
	if(hua==0){
		maxi=-1;
	}
	cout<<maxi<<endl;
}
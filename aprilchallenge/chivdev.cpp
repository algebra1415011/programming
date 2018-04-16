#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool check[1000010];
vector<ll>dp[100001];
vector<ll>sti;
vector<ll> v;
void sieve()
{
		check[0]=1;
	    check[1]=1;
	    for(ll i=2;i<=sqrt(1000001);i++){
	        if(!check[i]){
	            for(ll j=2*i;j<1000001;j+=i){
	                check[j]=1;
	            }
	        }
	    }
	    
	    for(ll i=2;i<1000001;i++){
	        if(!check[i]){
	            v.push_back(i);
	           
	        }
	    }


}

ll divfact1(ll n, ll m)
{
	for(ll t=0;t<v.size();t++)
	{
		//cout<<v[t]<<" "; 
        ll k=n%v[t];
        if(k!=0){
            k=v[t]-k;
        }
        for(ll j=n+k;j<=m;j+=v[t]){
            //cout<<j-n<<endl;
            dp[j-n].push_back(v[t]);
        }
    }
    ll ans=0;
    for(ll i=n;i<=m;i++){
        if(i==1){
           continue;
        }
        else if(dp[i-n].size()==0)
            ans+=2;
        else{
            sti.clear();
            ll k=i;
            for(ll j=0;j<dp[i-n].size();j++){
                ll current=dp[i-n][j];
                ll papa=0;
                while(k%current==0){
                    k/=current;
                    papa++;
                }
                sti.push_back(papa+1);
            }
            if(k!=1){
                sti.push_back(2);
            }
            ll c=1;
            
            while(true){
                c=1;
                priority_queue<ll>q;
                for(ll j=0;j<sti.size();j++){
                    c*=sti[j];
                    q.push(sti[j]);
                }
                //cout<<c<<" "<<q.top()<<endl;
                if(q.top()==1){
                    break;
                }
                else{
                    k=q.top();
                    k--;
                    q.pop();
                    q.push(k);
                    sti.clear();
                    while(!q.empty()){
                        sti.push_back(q.top());
                        q.pop();
                    }
                    if(c!=1){
                        {
                        	//cout<<"i"<<i<<" "<<c<<endl;
                        	ans+=c;

                        }	
                    }
                }
            }
            
        }
    }
    return ans;

}



int main()
{
	sieve();
	ll a,b;
	cin>>a>>b;
	cout<<divfact1(a,b)<<endl;

}
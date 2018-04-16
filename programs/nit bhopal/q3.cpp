#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans=0;

ll cnta=0;
ll solve(ll i,string s,ll n)
{
    ll temp=0,ind=i;

   ll data;
    for(ll j=i;j>=0;j--)
    {
        cout<<"ind"<<j<<" "<<ind<<" "<<s[j]<<endl;
        if(s[j]=='0')
            continue;

        data=(s[j]-'0');
        data=data*pow(10,i-j);
        cout<<data<<" ";
        if(temp+data<n)
        {
            temp=data+temp;
            ind=j;
        }
        else
        {

            ans=ans+temp*pow(n,cnta++);
            cout<<"temp"<<temp<<" "<<ans<<endl;
            return ind;

        }


    }
    if(temp<n)
    {
        ans+=temp*pow(n,cnta++);
        cout<<ans<<endl;
        return 0;
    }
    return ind;

}

int main()
{
    string s;
    ll n;
    cin>>n;
    cin>>s;
    ll i=s.length()-1;
    while(i>=0)
    {
        ll ind=solve(i,s,n);
        i=ind-1;

    }
    cout<<ans<<endl;
}

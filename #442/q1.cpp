#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[3][3];
        int sum[3]={0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                {
                    cin>>a[i][j];
                    sum[i]+=a[i][j];
                }
        }
        for(ll i=0;i<3;i++)
        	sort(a[i],a[i]+3);

        set<ll> st;
        st.insert(a[0][2]);
        st.insert(a[1][2]);
        st.insert(a[2][2]);
        vector <pair<ll, pair<ll,ll> > > st2;
        if(st.size()==3)
        {
        	st2.push_back(make_pair(a[0][2],make_pair(a[0][0],a[0][1])));
       		st2.push_back(make_pair(a[1][2],make_pair(a[1][0],a[1][1])));
        	st2.push_back(make_pair(a[2][2],make_pair(a[2][0],a[2][1])));
        	sort(st2.begin(),st2.end());


        }

        int flag=1;
        // cout<<sum[0]<<" "<<sum[1]<<" "<<sum[2]<<endl;
        if(sum[0]!=sum[1] and sum[1]!=sum[2]  and sum[0]!=sum[2])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

}
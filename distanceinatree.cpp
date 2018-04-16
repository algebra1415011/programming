#include <bits/stdc++.h>
using namespace std;
int vl[50001][501]={0};
vector<int> v[1000001];
vector<int> parent[50001];
map<long long int,long long int>visit;
long long int ans=0;
long long int k;
void dfs(long long int src)
    {
            visit[src]=1;
            vl[src][0]=1;
            for(long long int i=0;i<v[src].size();i++)
                {
                    if(!visit[v[src][i]])
                    {
                        
                        vl[src][1]++;
                        parent[v[src][i]].push_back(src);
                        dfs(v[src][i]); 
                        for(long long int j=2;j<=k;j++)
                                vl[src][j]+=vl[v[src][i]][j-1];
                    
                    }
                }

            //cout<<src<<" "<<vl[src][k]<<endl;
        
    }

long long int solve(long long int n)
    {
        //cout<<"hi";
        long long int b;
        long long int prev;
        for(long long int i=1;i<=n;i++)
            {
                
                ans=ans+vl[i][k];
                long long int c=i;
                long long int j=1;
                while(parent[c].size() && (k-j-1)>=0)
                {
                    int par=parent[c][0];
                    ans=ans+vl[par][k-j]-vl[c][k-j-1];
                    c=par;
                    j++;
                }if((k-j)==0 && parent[c].size())
                        ans++;
               
            }

        return ans;
    }



int main()
{
    //cout<<"land"<<endl;
   long long int n,m,a,b;
    cin>>n>>m;
    k=m;
    //cout<<n<<m<<endl;
    for(long long int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);

        }

    dfs(1);
    //cout<<"hello"<<endl;
   /* for(long long int i=1;i<=n;i++)
        cout<<parent[i]<<" ";
    cout<<endl;*/
    cout<<solve(n)/2<<endl;


}
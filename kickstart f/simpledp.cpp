#include <bits/stdc++.h>
#define ll long long int 

using namespace std;


string res;
vector<int> v,a,b;
int temp,sum,n;

int main(){
  cin>>n;
  sum=0;
  for(int i=0;i<n;i++){
    cin>>temp;
    sum+=temp;
    v.push_back(temp);
  }
 
  sort(v.begin(),v.end());
  //  for(ll i=0;i<v.size();i++)
  //   cout<<v[i]<<" ";
  // cout<<endl;
  if(v[0]!=0){
    cout<<"-1"<<endl;
    exit(0);
  }
  // cout<<sum<<endl;
  for(int i=0;i<n;i++){
    if(v[i]%3==1 )
      a.push_back(i);
    if(v[i]%3==2 )
      b.push_back(i);
  }
  // for(ll i=0;i<v.size();i++)
  //   cout<<v[i]<<" ";
  // cout<<endl;
  // cout<<sum<<endl;
  if(sum%3==1){
    if(a.size()>0)
      {
        // cout<<a[0]<<endl;
      v.erase(v.begin()+a[0]);

    }
    else if(b.size()>=2){
      // cout<<endl;
      // cout<<b[0]<<endl;
      // cout<<v[v.begin()+b[1]-1]<<endl;
      v.erase(v.begin()+b[0]);
      v.erase(v.begin()+b[1]-1);
    }
    else{
      cout<<"-1"<<endl;
      exit(0);
    }
  //   for(ll i=0;i<v.size();i++)
  //   cout<<v[i]<<" ";
  // cout<<endl;
  }
  else if(sum%3==2){
    if(b.size()>0)
      v.erase(v.begin()+b[0]);
    else if(a.size()>=2)
    {
      v.erase(v.begin()+a[0]);
      v.erase(v.begin()+a[1]-1);
    }
    else{
      cout<<"-1"<<endl;
      exit(0);
    }
  //   for(ll i=0;i<v.size();i++)
  //   cout<<v[i]<<" ";
  // cout<<endl;
  }
  if(v[v.size()-1]==0)
  {
    cout<<0<<endl;
    exit(0);
  }
  for(int i=v.size()-1;i>=0;i--)
    cout<<v[i];
  cout<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int pre[100005], suf[100005];

int main()
{
    string  a,b;
    cin>>a>>b;
    a = '$'+a;
    b = '@' + b;
    pre[0]=0;
    int j = 1;
    for(int i=1;i<a.length();i++)
    {
        if(b[j]==a[i])
        {
            pre[i] = j;
            j++;
        }
        else
            pre[i]=pre[i-1];
    }
    int k = a.size();
    j = b.length()-1;
    suf[k]=b.length();
    for(int i=k-1;i>=1;i--)
    {
        if(b[j]==a[i])
        {

            suf[i]=j;
           // cout<<i<<" "<<j<<"\n";
            j--;
        }
        else
            suf[i]=suf[i+1];
    }

    int len = b.length()-1;
    int l = 0;
    int r = b.length();
    //a.push_back('5');

    for(int i=0;i<a.size();i++)
    {
       // cout<<pre[i]<<" "<<suf[i+1]<<"\n";
        if(pre[i]<suf[i+1])
        {
            int p = suf[i+1]-pre[i]-1;
            if(p<len)
            {
               len = p;
               l = pre[i];
               r = suf[i+1];
            }
        }
    }

    string v;
    for(int i=1;i<=l;i++)
        v.push_back(b[i]);
    for(int i=r;i<b.size();i++)
        v.push_back(b[i]);
    if(v.size()==0)
        puts("-");
    else
        cout<<v;

}
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
bool visited[1000000];
int count1=0;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int dfs(int src,int P[100]){

    visited[src]=true;
    //cout<<P[src-1]<<" ";
    count1++;
    if(!visited[P[src-1]])
        dfs(P[src-1],P);
    return count1;
}

int lcm(int a,int b)
{
    return ((a*b)/gcd(a,b));
}

int danceTime(int N, int P[100]) {

    int ans=1;
    for(int i=0;i<N;i++)
    {
        if(!visited[P[i]])
        {
            dfs(P[i],P);
           // cout<<endl;
            ans=lcm(ans,count1);
            count1=0;
        }
    }


    //add code to this function to solve the problem
    //don't write code in this editor
    //your code will not be saved across submissions
    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        for(int i=0;i<=1000000;i++)
            visited[i]=false;
        int P[100];
        for(int i=0;i<N;i++) scanf("%d",&P[i]);
        printf("%d\n",danceTime(N,P));
    }
    return 0;
}

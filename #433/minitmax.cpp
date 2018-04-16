#include <bits/stdc++.h>
#define  ll long long int
using namespace std;


bool check(int arr[],int n, int m, int mid)
{
	int sum=0;
	int c=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>mid)
			return false;
		if(arr[i]+sum>mid)
		{
			c++;
			sum=arr[i];
			if(c>m)
				return false;
		}
		else

			sum+=arr[i];
	}
	return true;
}

int binary_search(int arr[],int start, int high,int n,int m)
{
	int count=0;
	int ans=INT_MAX;
	if(m>n)
		return 0;
	if(m==n)
		return high;
	while(start<=high)
	{
		int mid=(start+high)/2;
		// cout<<mid<<endl;
		if(check(arr,n,m,mid))
		{
			high=mid-1;
			ans=min(ans,mid);
		}
		else
			start=mid+1;
	}
	if(ans==INT_MAX)
		return -1;
	return ans;
}




int main()
{
	int t;
	cin>>t;
	int n,m;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m;
		int arr[n+1];
		int high=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			high+=arr[i];
		}

		cout<<binary_search(arr,0,high,n,m)<<endl;
	}

}
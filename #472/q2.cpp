#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
queue<ll> row,column;
ll roww[1000];
ll columnn[1000];
int main()
{

	ll r,c;
	cin>>r>>c;
	char arr[r][c];
	ll flag=0;
	for(ll i=0;i<r;i++)
			for(ll j=0;j<c;j++)
				
					cin>>arr[i][j];

				
	for(ll i=0;i<r;i++)
	{
		for(ll j=0;j<c;j++)
		{
			if(arr[i][j]=='#')
			{
				if(!roww[i] || !columnn[j])
				{
					row.push(i);
					column.push(j);
					
					
					while(!row.empty())
					{
						ll vla=row.front();
						row.pop();
						
						
						if(roww[vla]==1)
						{
							cout<<"nor"<<vla<<endl;
							cout<<"No"<<endl;
							return 0;
						}
						cout<<"row"<<vla<<endl;
						roww[vla]=1;
						for(ll k=0;k<c;k++)
						{

							if(arr[vla][k]=='#' and k!=j)
								column.push(k);
						}
						while(!column.empty())
						{
							ll val=column.front();
							column.pop();
							if(columnn[val]==1)
							{
								cout<<"noc"<<val<<endl;
								cout<<"No"<<endl;
								return 0;
							}
							columnn[val]=1;
							cout<<"column"<<val<<endl;
							for(ll k=0;k<r;k++)
							{
								if(arr[k][val]=='#' and k!=i)
									{
										row.push(k);
										cout<<"push"<<k<<endl;
									}	
							}
						}
					}
				}
			}
		}
	}
	for(ll i=0;i<r;i++)
	{
		for(ll j=0;j<c;j++)
		{
			if(arr[i][j]=='#')
			{
				if(!roww[i] || !columnn[j])
				{
					cout<<"No"<<endl;
					return 0;
				}
				
			}
		}
	}
	cout<<"Yes"<<endl;




	return 0;

}
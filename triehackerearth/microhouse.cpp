#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Trienode
{
	map<ll, Trienode* > children;
	ll value;
};
struct Trienode *root;
void insert(ll n)
{
	struct Trienode* temp=root;
	for(ll i=31;i>=0;i--)
	{
		bool bit=(n&(1<<i));
		if(temp->children[bit])
			temp=temp->children[bit];
		else
		{
			struct Trienode* newnode = new Trienode();
			temp->children[bit]=newnode;
			temp=newnode;
		}
	}temp->value=n;
}

ll query(ll n)
{
	struct Trienode* temp=root;
	for(ll i=31;i>=0;i--)
	{
		bool bit=(n&(1<<i));
		if(temp->children[1-bit])
			temp=temp->children[1-bit];
		else if(temp->children[bit])
			temp=temp->children[bit];
	}
	//cout<<"hello"<<temp->value<<endl;
	return n^(temp->value);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr.tie(0);
	root=new Trienode();
	insert(0);
	ll r,c,k;
	cin>>r>>c;
	ll prexor=0,ans=0;
	for(ll i=0;i<r*c;i++)
	{
		cin>>k;
		prexor^=k;
		insert(prexor);
		ans=max(ans,query(prexor));
		//cout<<ans<<endl;

	}
	cout<<ans<<endl;

}
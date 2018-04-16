#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct trienode
{
	map<char,trienode*> children;
	char sign;
};
struct trienode* root;
void insert(char c, string s)
{
	struct trienode *currentnode=root; 
	for(ll i=0;i<s.length();i++)
	{
		if(currentnode->children[s[i]])
		{
			if(c=='+')
				currentnode->sign=c;
			currentnode=currentnode->children[s[i]];

		}
		else
		{
			trienode  *newnode=new trienode();
			currentnode->children[s[i]]=newnode;
			newnode->sign=c;
			currentnode=newnode;
		}
	}
}

ll search(string s)
{
	struct trienode *currentnode=root;
	for(ll i=0;i<s.length();i++)
	{
		cout<<currentnode->sign<<" ";
		currentnode=currentnode->children[s[i]];
	}
}

int main()
{
	cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0);
	ll n;
	char c;
	string s;
	root=new trienode();
	cin>>n;
	vector<string> vs;
	for(ll i=0;i<n;i++)
	{
		cin>>c>>s;
		//cout<<c<<" "<<s<<endl;
		insert(c,s);
		if(c=='-')
			vs.push_back(s);

	}
	for(ll  i=0;i<vs.size();i++)
		search(vs[i]),cout<<endl;

	return 0;
}
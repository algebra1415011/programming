#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Trienode
{
	map<char, Trienode*> children;
	bool endofnode;
	ll weight;

};
struct Trienode* root;

void insert(string s,ll w)
{

	//cout<<s<<endl;
	struct Trienode* current=root;
	for(ll i=0;i<s.length();i++)
	{

		if(current->children[s[i]])
		{
			//cout<<"1 "<<current->children[s[i]]<<endl;
			current->weight=max(current->weight,w);
			current=current->children[s[i]];

		}	
		else
		{
			//cout<<"1 "<<current->children[s[i]]<<endl;
			struct Trienode* newnode=new Trienode();
			newnode->endofnode=false;
			//cout<<""<<newnode->weight<<endl;
			current->weight=max(current->weight,w);
			newnode->weight=max(newnode->weight,w);
			current->children[s[i]]=newnode;
			current=newnode;
			
		}
	}
	current->endofnode=true; 	 	
}

ll search(string s)
{

	struct Trienode* current=root;
	ll index=0;
	while(current->children[s[index]])
	{
		current=current->children[s[index]];
		index++;
	}
	if(current==root || index!=s.length())
			return -1;
	return current->weight;		
}

int main()
{
	ll n,m,w;
	string s;
	//cout<<root->children['a']<<endl;
	root=new Trienode();
	root->endofnode=false;
	//cout<<root->children['a']<<endl;
	//cout<<root->endofnode<<endl;
	//root->children['a']=getnewnode();
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		cin>>s>>w;
		insert(s,w);
	}
	for(ll i=0;i<m;i++)
	{
		cin>>s;
		cout<<search(s)<<endl;

	}
}
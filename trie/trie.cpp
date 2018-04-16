#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Trienode
{
	map<char, Trienode*> children;
	bool endofnode;


};
struct Trienode* root;

void insert(string s)
{

	//cout<<s<<endl;
	struct Trienode* current=root;
	for(ll i=0;i<s.length();i++)
	{

		if(current->children[s[i]])
		{
			cout<<"1 "<<current->children[s[i]]<<endl;
			current=current->children[s[i]];

		}	
		else
		{
			cout<<"1 "<<current->children[s[i]]<<endl;
			struct Trienode* newnode=new Trienode();
			newnode->endofnode=false;
			current->children[s[i]]=newnode;
			current=newnode;
			
		}
	}
	current->endofnode=true; 	 	
}

bool search(string s)
{

	struct Trienode* current=root;
	ll index=0;
	while(current->children[s[index]])
	{
		current=current->children[s[index]];
		index++;
	}
	if(current->endofnode==true)
		{
			cout<<"Complete string"<<endl;
			return true;
		}
	else
	{
		if(current==root)
			return false;
		else
		{
			cout<<"substring present"<<endl;
			return true;
		}
	}		
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
		insert(s);
	}
	for(ll i=0;i<m;i++)
	{
		cin>>s;
		search(s);

	}
}
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
struct trie{
	struct trie* c[26];
	bool endOfWord;
	int MAX;
};
 
struct trie* getNewNode(){
	struct trie* n = (struct trie*)malloc(sizeof(struct trie));
	for(int i=0 ; i<26 ; i++)
	{
		n->c[i] = NULL;
	}
	n->endOfWord = false;
	n->MAX = 0;
	return n;
}
 
void cnstr(struct trie* node,string s,int val)
{
	struct trie* temp = node;
	int l = s.length();
	for(int i=0 ; i<l ; i++)
	{
		//cout << s[i] << " = " ;
		if(temp->c[s[i]-'a'] == NULL)
		{
			temp->c[s[i]-'a'] = getNewNode();
		}
		temp->MAX=max(temp->MAX, val);
		//cout << temp->prefixSum<<endl;
		temp = temp->c[s[i]-'a'];
	}
	temp->endOfWord = true;
}
 
void check(struct trie* node,string s)
{
	struct trie* temp = node;
	//struct trie* prev;
	int l = s.length();
	for(int i=0 ; i<l ; i++)
	{	
		if(temp->c[s[i]-'a'] != NULL)
		{
			temp = temp->c[s[i]-'a'];
		}
		else
		{	
		    cout << -1 << endl;
			return;
		}
	}
	cout << temp->MAX << endl;
	return;
}
 
int main()
{
	int n,q,i,j,val;
	cin >> n >> q;
	string s;
	struct trie* root = getNewNode();
	for(i=0 ; i<n ; i++)
	{
		cin >> s >> val;
		cnstr(root,s,val);
	}
	
	while(q--)
	{
		cin >> s;
		check(root,s);
	}
	
}
#include <bits/stdc++.h>

#define s(n) scanf("%d", &n)
using namespace std;

map<int,int> mp;
struct node {
	node *left;
	node *right;
	int label;
};


void _makeTree(node *root,int lleft[1024],int rright[1024]) {

	int num = root->label;

	if(lleft[num] == -1 && rright[num] == -1) return;

	if(lleft[num] != -1) {
		node *leftNode = new node;
		leftNode->label =  lleft[num];
		leftNode->left = NULL;
		leftNode->right = NULL;
		_makeTree(leftNode,lleft,rright);
		root->left = leftNode;
	}

	if(rright[num] != -1) {
		node *rightNode = new node;
		rightNode->label =  rright[num];
		rightNode->left = NULL;
		rightNode->right = NULL;
		_makeTree(rightNode,lleft,rright);
		root->right = rightNode;
	}

}

void _deleteNode(node *root) {
	if(root == NULL) return;

	_deleteNode(root->left);
	_deleteNode(root->right);
	delete root;
}

int HeightOfTree(node *Root)
{
    int n=0,m=0;
    if(!Root)return 0;
    n=HeightOfTree(Root->left);
    m=HeightOfTree(Root->right);
    if(n>m)
    return n+1;
    else 
    return m+1;
}
void Level1(node *Root,int i,int height)
{  
	node *temp=NULL;
    if(!Root)return NULL;
    if(Root->left==NULL&&Root->right==NULL)
    {

    	
    	return Root;

    }	
    mp[root->left->label]=i+1;
   	mp[root->right->label]=i+1;
    Level1(Root->left,i+1,height);

    Level1(Root->right,i+1,height);
    
}
node *NearestLeafNode(node *root)
{  
	node *temp=NULL;
    if(!root)
     return NULL;
     int height=HeightOfTree(root);
     for(int i=0;i<height;i++)
      {
          
          Level1(root,0,i);
          if(temp)
          	return temp;
      }
}


int getRootWhichMinimizesFurthestLeafDistance(node *root) {

	return NearestLeafNode(root)->label;

}

int main() {

	int runs, nodeNo, nodeLeft, nodeRight, rootLabel;
	s(runs);
	while(runs-- > 0) {
		int n;
		int lleft[1024];
		int rright[1024];
		for(int i=0;i<1024;i++)
			lleft[i] = rright[i] = -1;

		s(n); s(rootLabel);
		for(int i=0;i<n;i++) {
			s(nodeNo); s(nodeLeft); s(nodeRight);
			lleft[nodeNo] = nodeLeft;
			rright[nodeNo] = nodeRight;
		}

		node *root = new node;
		root->label = rootLabel;
		root->left = NULL;
		root->right = NULL;
		_makeTree(root,lleft,rright);
		int answer = getRootWhichMinimizesFurthestLeafDistance(root);
		cout << answer << endl;
		_deleteNode(root);
	}

	return 0;
}

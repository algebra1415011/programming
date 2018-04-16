#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
	string s;
	cin>>s;
	int cap=0;
	int line=1;
	int currentline=1;
	string h="";
	int pointer=0;

	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='#')
		{
			//cout<<"kella"<<endl;
			h+="#";
			pointer++;
		}
		else if(s[i]=='@')
		{
			cap=cap^1;

		}
		else if(s[i]=='^')
		{
			int current=pointer;
			// cout<<h<<endl;
			// cout<<"pointer"<<current<<endl;
			while(current!=0)
			{
				current--;
				if(h[current]=='#')
				{
					pointer=current;
					break;
				}
				
			}
			// cout<<pointer<<endl;

		}
		else if(s[i]=='/')
		{
	
				//cout<<pointer<<endl;
				h.erase(pointer-1,1);

				pointer--;
				


			

		}
		else if(s[i]=='?')
		{
			int current=pointer;
			while(current<h.length())
			{
				current++;
				if(h[current]=='#')
				{
					pointer=current;
					break;
				}
				
			}
		}
		else if(s[i]=='=')
		{
			h+=" ";
			pointer++;
		}
		else
		{


			if(cap)
				{
					//if()
					h.insert(pointer,1,toupper(s[i]));
				}	
			else
				h.insert(pointer,1,s[i]);
			//cout<<h<<endl;

			pointer++;
		}
		//cout<<h<<endl;	
	}
	
	for(int i=0;i<h.length();i++)
	{
		if(h[i]!='#')
			cout<<h[i];
		else
			cout<<endl;
	}
	// cout<<h<<endl;

}
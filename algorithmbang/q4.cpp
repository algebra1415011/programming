#include <bits/stdc++.h>
 
using namespace std;
int main()
{
	float x1,x2,x3,x4;
	float y1,y2,y3,y4;
	set<pair<float,float> > st1;
	cin>>x1>>y1;
	st1.insert(make_pair(x1,y1));
 
	cin>>x2>>y2>>x3>>y3>>x4>>y4;
	st1.insert(make_pair(x2,y2));
	st1.insert(make_pair(x3,y3));
	st1.insert(make_pair(x4,y4));
	if(st1.size()!=4)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	float p1=sqrt(abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1));
	float p2=sqrt(abs(x2-x3)*abs(x2-x3)+abs(y2-y3)*abs(y2-y3));
	float p3=sqrt(abs(x3-x4)*abs(x3-x4)+abs(y3-y4)*abs(y3-y4));
	float p4=sqrt(abs(x4-x1)*abs(x4-x1)+abs(y4-y1)*abs(y4-y1));
	float p5=sqrt(abs(x3-x1)*abs(x3-x1)+abs(y3-y1)*abs(y3-y1));
	float p6=sqrt(abs(x2-x4)*abs(x2-x4)+abs(y2-y4)*abs(y2-y4));
	set<float> st;
	st.insert(p1);
	st.insert(p2);
	st.insert(p3);
	st.insert(p4);
	st.insert(p5);
	st.insert(p6);
	//cout<<p1<<p2<<p3<<p4<<p5<<p6<<endl;
	
 
	if(st.size()==3)
	{
		cout<<"YES"<<endl;
	}		
	else
		cout<<"NO"<<endl;
 
 
	return 0;
 
}
#include <iostream>
#include<math.h>
using namespace std;
 
int main() {
    double n,b,i,j,a,sum=0;
    double s;
	cin>>n>>b;
	
	for(i=0;i<n;i++)
	{
	      cin>>a;
	      sum+=a;
	}
	s=sum/b;
	
	cout<<ceil(s);
	return 0;
} 
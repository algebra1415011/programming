/*
 * Avinash Gurjar, NIT Silchar
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class TriangleMaking{
public:
	 	int maxPerimeter(int a, int b, int c){
	ll value=0;
	for(ll i=1;i<=a;i++)
		for(ll j=1;j<=b;j++)
			for(ll k=1;k<=c;k++)
				if(2*max(i,max(j,k))<(i+j+k))
					value=max(value,i+j+k);
	return value

	}
};

#include <bits/stdc++.h>
#define  ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    int tes = 0;
    while(t--){
    	tes++;
    	int n;
    	cin>>n;
    	int A[n];
    	priority_queue< int > maxPQ;
    	priority_queue< int, vector<int> ,greater<int> > minPQ;
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>A[i];
    		maxPQ.push(A[i]);
    		minPQ.push(A[i]);
    	}

    	int temp = n;
    	bool yes = true;
    	int del=0;
    	while(temp){
          int a = (temp-1)/2;
          int mid ;
          if(temp%2==0){
             mid = a;
          }else{
            mid = a+del;
          }
         
          if(A[mid]==maxPQ.top()){
             maxPQ.pop();
          }else if(A[mid]==minPQ.top()){
             minPQ.pop();
             if(!minPQ.empty() and A[mid]==minPQ.top()){
             	yes = false;
             	break;
             }
          }
          else{
          	yes = false;
          	break;
          }
          temp--;
          del++;
    	}

    	if(yes){
             cout<<"Case #"<<tes<<": YES"<<endl;
    	}else{
            cout<<"Case #"<<tes<<": NO"<<endl;
    	}
    }
	return 0;
}
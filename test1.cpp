#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int input[n][n];
	vector<int> answer;
	for(int i(0);i<n;i++){
		bool flag(true);
		for(int j(0);j<n;j++){
			cin>>input[i][j];
			if(!(input[i][j] == -1 or input[i][j] == 0 or input[i][j] == 2)){
				flag = false;
			}
		}
		if(flag){
				answer.push_back(i+1);
		}
	}
	cout<<answer.size()<<endl;
	for(int i(0);i<answer.size();i++){
		cout<<answer[i]<<" ";
	}
	return 0;
}
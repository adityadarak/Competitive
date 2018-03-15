#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	priority_queue<int> ma;
	for(int i=0;i<n;i++){
		int q;
		cin>>q;
		ma.push(q);
	}
	cin>>m;
	priority_queue<int> fe;
	for(int i=0;i<m;i++){
		int q;
		cin>>q;
		fe.push(q);
	}
	int more=0;
	while(!fe.empty() && !ma.empty()){
			if(abs(ma.top()-fe.top())<=1){
				fe.pop();
				ma.pop();
				more++;
			}
			else if(ma.top()>fe.top()){
				ma.pop();
			}
			else{
				fe.pop();
			}
	}
	cout<<more<<endl;
	return 0;
}
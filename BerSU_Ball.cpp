#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	vector<int> ma;
	vector<int> fe;
	for(int i=0;i<n;i++){
		int q;
		cin>>q;
		ma.push_back(q);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int q;
		cin>>q;
		fe.push_back(q);
	}
	int dp[n+1][m+1];
	for(int i=0;i<n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<m;i++){
		dp[0][i]=0;
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(abs(ma[i-1]-fe[j-1])<=1){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=dp[i-1][j-1];
			}
			if(dp[i][j]>max){
				max=dp[i][j];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
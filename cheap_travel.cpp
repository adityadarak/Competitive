#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int dp[n+1];
	dp[0]=0;
	for(int i=0;i<n+1;i++){
		if(i-1==0){
			dp[i]=min(a,b);
		}
		else if(i-m==0){
			dp[i]=min(dp[i-1]+a,b);
		}
		else if(i-m>0){
			dp[i]=min(dp[i-m]+b, dp[i-1]+a);
		}
		else{
			dp[i]=min(b,dp[i-1]+a);
		}
	}
	cout<<dp[n];
	return 0;
}
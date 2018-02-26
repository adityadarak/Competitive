#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	while(N--){
		int K,M;
		cin>>K>>M;
		int A[M],B[M];
		for(int i=0;i<M;i++){
			int a,b;
			cin>>a>>b;
			A[i]=a;
			B[i]=b;
		}
		int dp[M+1][K+1];
		for(int i=0;i<M+1;i++){
			for(int j=0;j<K+1;j++){
				if(j==0 || i==0){
					dp[i][j]=0;
				}
				else if(j-A[i-1]>=0){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i-1]]+B[i-1]);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		cout<<"Hey stupid robber, you can get "<<dp[M][K]<<"."<<endl;
	}
	return 0;
}
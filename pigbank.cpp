#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int e,f;
		cin>>e>>f;
		int weight=f-e;
		int n;
		cin>>n;
		vector<int> a,b;
		while(n--){
			int c,d;
			cin>>c>>d;
			a.push_back(c);
			b.push_back(d);
		}
		int N=a.size();
		int dp[weight+1];
		dp[0]=0;
		int value=0;
		for(int i=0;i<weight+1;i++){
			int max=INT_MAX;
			for(int j=0;j<N;j++){
				if(i-b[j]==0){
					max=min(max,a[j]);
				}
				else if(i-b[j]>0){
					if(dp[i-b[j]]>0){
						max=min(max,dp[i-b[j]]+a[j]);
					}
				}
			}
			if(max==INT_MAX){
				dp[i]=0;
			}
			else
				dp[i]=max;
		}
		if(dp[weight]==0)
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[weight]<<"."<<endl;
	}
	return 0;
}
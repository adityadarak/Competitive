#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,y;
	cin>>n>>y;
	int a[y+1],b[y+1],m[n+1];
	bool adj[n+1][n+1];
	for(int i=0;i<=n;i++){
		m[i]=0;
		for(int j=0;j<=n;j++){
			adj[i][j]=false;
		}
	}
	
	for(int i=1;i<=y;i++){
		cin>>a[i]>>b[i];
		m[a[i]]++;
		m[b[i]]++;
		adj[a[i]][b[i]]=true;
		adj[b[i]][a[i]]=true;
	}
	
	// for(int i=1;i<=n;i++){
	// 	cout<<m[i]<<"\t";
	// }
	// cout<<endl;

	int mi=INT_MAX;
	for(int i=1;i<=y;i++){
		for(int j=1;j<=n;j++){
			if(adj[j][a[i]] && adj[j][b[i]]){
				//cout<<mi<<"\t"<<m[j]<<"\t"<<m[a[i]]<<"\t"<<m[b[j]]<<endl;
				mi=min(mi,m[j]+m[a[i]]+m[b[i]]-6);
			}
		}
	}
	
	if(mi==INT_MAX)
		cout<<-1<<endl;
	else
		cout<<mi<<endl;
	return 0;
}
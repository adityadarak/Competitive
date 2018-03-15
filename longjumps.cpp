#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
	int n,l,x,y;
	bool donex,doney;
	donex=doney=false;
	cin>>n>>l>>x>>y;
	map<int,bool> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]=true;
	}
	if(binary_search(a,a+n,x)){
		donex=true;
	}
	if(binary_search(a,a+n,y)){
		doney=true;
	}
	if(!donex){
		for(int i=0;i<n;i++){
			if(m[a[i]+x] || m[a[i]-x]){
				donex=true;
				break;
			}
		}
	}
	if(!doney){
		for(int i=0;i<n;i++){
			if(m[a[i]+y] || m[a[i]-y]){
				doney=true;
				break;
			}
		}
	}
	if(!donex && !doney){
		bool q=false;
		int new1[n],new2[n],new3[n],new4[n];
		for(int i=0;i<n;i++){
			new1[i]=a[i]+x;
			new2[i]=a[i]+y;
			new3[i]=a[i]-x;
			new4[i]=a[i]-y;
		}
		for(int i=0;i<n;i++){
			if(binary_search(new1,new1+n,new2[i])){
				if(new2[i]<l){
					cout<<1<<endl;
					cout<<new2[i]<<endl;
					q=true;
					break;
				}
			}
			else if(binary_search(new3,new3+n,new4[i])){
				if(new4[i]>0){
					cout<<1<<endl;
					cout<<new4[i]<<endl;
					q=true;
					break;
				}
			}
			else if(binary_search(new3,new3+n,new2[i])){
				if(new2[i]<l){
					cout<<1<<endl;
					cout<<new2[i]<<endl;
					q=true;
					break;
				}
			}
			else if(binary_search(new1,new1+n,new4[i])){
				if(new4[i]>0){
					cout<<1<<endl;
					cout<<new4[i]<<endl;
					q=true;
					break;
				}
			}
		}
		if(!q){
			m[x]=true;
			bool got1=false;
			bool got2=false;
			for(int i=0;i<n;i++){
				if(m[y+x]){
					got1=true;
					break;
				}
				if(m[y-x]){
					got2=true;
					break;
				}
			}
			if(!got1 && !got2){
				cout<<2<<endl;
				cout<<x<<" "<<y<<endl;
			}
			else{
				cout<<1<<endl;
				if(got1)
					cout<<x<<endl;
				if(got2)
					cout<<y<<endl;
			}
		}
	}
	else if(!donex){
		cout<<1<<endl;
		cout<<x<<endl;
	}
	else if(!doney){
		cout<<1<<endl;
		cout<<y<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
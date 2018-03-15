#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int c=0;
	map<char,int> m;
	for(int i=0;i<2*n-2;i++){
		char s;
		if(i%2==0){
			int x=(i+2)/2;
			cin>>s;
			///cout<<s<<endl;
			m[s]=m[s]+1;
			//cout<<m[s]<<endl;
		}
		else{
			cin>>s;
			s=s+32;
			//cout<<s<<endl;
			//cout<<m[s]<<endl;
			if(m[s]==0){
				//m[s]=false;
				c++;
			}
			else{
				m[s]--;
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
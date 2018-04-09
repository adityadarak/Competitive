#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	int hash[256]={0};
	for(int i=0;i<s.length();i++){
		hash[s[i]]++;
	}

	int count=0;
	for(int i=0;i<s.length();i++){
		if(hash[s[i]]==1){
			count++;
		}
		if(count==k){
			cout<<s[i]<<endl;
			break;
		}
	}
	return 0;
}
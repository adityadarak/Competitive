#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<n<<endl;
	}
	else{
		map<vector<int>,int> m;
		int fin=INT_MIN;
		//int prevk=0;
		for(int i=1;i<n;i++){
			int d=pow(-1,i);
			int k=a[i]-a[i-1];
			//if(prevk!=k*d){
			//	m[k*d]=2;
			//}
			//else{
			//int p;
			vector<int> s(2);
			if(a[i]<=a[i-1]){
				s.push_back(a[i]);
				s.push_back(a[i-1]);
			}
			else{
				s.push_back(a[i-1]);
				s.push_back(a[i]);
			}
			
			//s.push_back(p);
			s.push_back(k*d);
			m[s]++;
			cout<<k*d<<" "<<a[i]<<" "<<a[i-1]<<" "<<m[s]<<endl;

			//}
			fin=max(m[s]+1,fin);
			//prevk=k*d;
		}
		cout<<fin<<endl;
	}

	return 0;
}
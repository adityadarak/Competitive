#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    
    char o[n];
    for(int i=0;i<n;i++){
        cin>>o[i];
    }
    
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        map<char,int> m;
        for(int i=a-1;i<b;i++){
            m[o[i]]++;
        }
        char s[26];
        int c=0;
        for(char p='a';p<='z';p++){
            char w= 'a'+m[p]%26;
            s[c]=w;
            c++;
        }
        int j=0;
        char mm;
        mm=s[0];
        while(s[j]==s[25-j] && i<26){

            if(j==25 && s[j]==mm){
                break;
            }
            cout<<s[j];
            j++;
        }
        if(j==0){
            cout<<"None";
        }
        cout<<endl;
    }
    
    return 0;
}
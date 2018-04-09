#include<bits/stdc++.h>
using namespace std;

string findsubstring(string str, string s){
	// Finds the smallest possible substring of str which contains all the elemenst as of s.
	int l1=str.length();
	int l2=s.length();
	if(l1<l2){
		return "";
	}
	map<char,int> m1,m2;
	for(int i=0;i<l2;i++){
		m2[s[i]]++;
	}
	int start=0,max_len=INT_MAX,index=-1,count=0;
	for(int i=0;i<l1;i++){
		m1[str[i]]++;
		if(m1[str[i]]<=m2[str[i]] && m2[str[i]]!=0){
			count++;
		}
		if(count==l2){
			while(m2[str[start]]<m1[str[start]] || m2[str[start]]==0){
				if(m2[str[start]]<m1[str[start]]){
					m1[str[start]]--;
				}
				start++;
			}
			int temp=i-start+1;
			if(temp<max_len){
				max_len=temp;
				index=start;
			}
		}
	}
	if(index==-1){
		return "";
	}
	return str.substr(index,max_len);
}

pair<char,int> maxoccuringchar(string s){
	//sends pair of maximum occuring character
	int max=INT_MIN;
	char p;
	map<char,int> m;
	for(int i=0;i<s.length();i++){
		m[s[i]]++;
		if(max<m[s[i]]){
			max=m[s[i]];
			p=s[i];
		}
	}

	return make_pair(p,max);
}

int kthnonrepaeatingchar(string s, int k){
	//finds index of kth nonrepeating character in the string
	map<char,int> m;
	int l=s.length();
	if(l<k){
		cout<<"No kth nonrepeating char"<<endl;
		return -1;
	}
	for(int i=0;i<l;i++){
		m[s[i]]++;
	}
	int count=0,i=0;
	for(i=0;i<l;i++){
		if(m[s[i]]==1){
			count++;
		}
		if(count==k){
			break;
		}
	}
	if(count<k){
		cout<<"No kth nonrepeating char"<<endl;
		return -1;
	}
	return i;
}

string decrypt(string str){
	//Decrypts the given str with the freq count at the end of every char or string
	string ans="";
	for(int i=0;i<str.length();i++){
		string temp="";
		while(str[i]>='a' && str[i]<='z'){
			temp.push_back(str[i]);
			i++;
		}
		int freq=0;
		while(str[i]>='1' && str[i]<='9'){
			freq=freq*10+str[i]-'0';
			i++;
		}
		for(int j=0;j<freq;j++){
			ans.append(temp);
		}
		i--;
	}
	return ans;
}

int findcountatcorrectpos(string str){
	//Find the number of positions in the string which are at the same position as of its English language position
	int result=0;
	for(int i=0;i<str.length();i++){
		if(str[i]-'a'==i || str[i]-'A'==i){
			result++;
		}
	}
	return result;
}

bool areanagrams(string s1, string s2){
	map<char,int> m1,m2;
	if(s1.length()!=s2.length()){
		return false;
	}
	for(int i=0;i<s1.length();i++){
		m1[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		m2[s2[i]]++;	
	}
	int count=0;
	for(char i='a';i<='z';i++){
		if(m1[i]!=m2[i]){
			return false;		}
	}
	return true;
}

int arekAnagrams(string s1, string s2){
	//FInds the count of diifference if s1 and s2 are not anagrams
	map<char,int> m1,m2;
	for(int i=0;i<s1.length();i++){
		m1[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		m2[s2[i]]++;	
	}
	int count=0;
	for(char i='a';i<='z';i++){
		if(m1[i]>m2[i]){
			count=count+m1[i]-m2[i];
		}
	}
	return count;
}


bool canBecomeEmpty(string str, string sub_str){
	// Returns true if str can be made empty by recursively removing sub_str.
    while (str.size() > 0){
        int idx = str.find(sub_str);
        if (idx == -1)
            break;
        str.erase(idx, sub_str.size());
    }
    return (str.size() == 0);
}

int countwords(string s){
	//Given a string, count number of words in it. The words are separated by following characters: space (‘ ‘) or new line (‘\n’) or tab (‘\t’) 
	//or a combination of these.
	int count=0;
	bool state=true;
	for(int i=0;i<s.length();i++){
		if(s[i]==' ' || s[i]=='\n' || s[i]=='\t'){
			state=true;
		}
		else if(state){
			count++;
			state=false;
		}
	}
	return count;
}

vector<string> splitstr(string s, char delim){
	//Splits strings into array of words
	int i = 0;
	vector<string> v;
    int pos = s.find(delim);
    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
    return v;
}

int countrepetitionword(string s, string word){
	//FInds the number of times word is repeated in a string
	vector<string> sp=splitstr(s,' ');
	int count=0;
	for(int i=0;i<sp.size();i++){
		if(sp[i]==word){
			count++;
		}
	}
	return count;
}

bool isPalindrome(string str){
	int l=str.length();
	int a=0,b=l-1;
	while(b>a){
		if(str[a++]!=str[b--]){
			return false;
		}
	}
	return true;;
}

bool isPalindromeWithRotation(string str){
	//Given a string, check if it is a rotation of a palindrome. For example your function should return true for “aab” as it is a rotation of “aba”.
	if(isPalindrome(str)){
		return true;
	}
	int n=str.length();
	string s=str.append(str);
	int l=s.length();
	for(int i=0;i<l-n;i++){
		if(isPalindrome(s.substr(i,n))){
			return true;
		}
	}
	return false;
}

int lengthOfLastWord(string s) {
    int len = s.length();
	if (!len) return 0;
	int n=0,  i = len-1;
	while (s[i] == ' ') i--;
	for (; i >= 0; i--,n++)
		if (s[i] == ' ')
			return n;
	return n;
}

string countAndSay(int A){
/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.
*/
	if(A==1){
        return "1";
    }
    else{
        string s=countAndSay(A-1);
        int len=s.length();
        int prev,count;
        string ans="";
        for(int i=0;i<len;i++){
            if(i==0){
                prev=s[i];
                count++;
            }
            else{
                if(s[i]==prev){
                    count++;
                }
                else{
                    ans+=to_string(count);
                    ans+=prev;
                    count=1;
                    prev=s[i];
                }
            }
        }
        ans+=to_string(count);
        ans+=prev;
        return ans;
        
    }
    return "";
}

string longestCommonPrefix(vector<string> &A) {
/*
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.
*/
    int n=A.size();
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(min>A[i].length()){
            min=A[i].length();
        }
    }
    int j,k;
    for(j=0;j<min;j++){
        char s=A[0][j];
        bool flag=false;
        for(k=1;k<n;k++){
            if(s!=A[k][j]){
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    return A[0].substr(0,j);
}

int isPalindromeRemoveChar(string A) {
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
    int n=A.length();
    string s="";
    for(int i=0;i<n;i++){
        if(A[i]<='z' && A[i]>='a'){
            s+=A[i];
        }
        else if(A[i]<='Z' && A[i]>='A'){
            s+=A[i]+32;
        }
        else if(A[i]>='0' && A[i]<='9'){
            s+=A[i];
        }
    }
    //cout<<s;
    string p=s;
    reverse(p.begin(),p.end());
    //cout<<p;
    if(p==s){
        return true;
    }
    return false;
}

//For power of 2 solution
string multiplyByTwo(string A){
    string ans = "";
    int sum = 0, carry = 0;
    for(int i = A.size()-1; i >= 0; i--){
        sum=(A[i]-'0')*2+carry;
        carry = sum/10;
        sum = sum%10;
        ans+=(sum+'0');
    }
    if(carry > 0){
        ans+=(carry+'0');
    }
    for(int i = 0; i < ans.size()/2; i++){
        char c = ans[i];
        ans[i] = ans[ans.size()-i-1];
        ans[ans.size()-i-1] = c;
    }
    
    return ans;
}

bool compareString(string temp, string num){
    if(temp.size() == num.size()){
        return temp<num;
    }
    else if(temp.size() < num.size()){
        return true;
    }
    return false;
}
//Important
int power(string A) {
	/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.
	*/
    
    int i = 0;
    int length = A.size();
    while(A[i] == '0' && i < length){
        i++;
    }
    if(i == length){
        return 0;
    }
    
    string num = "";
    while(i != length){
        num = num + A[i];
        i++;
    }
    
    string temp = "2";
    while(compareString(temp, num)){
        temp = multiplyByTwo(temp);
    }
    
    if(temp == num){
        return 1;
    }
    
    return 0;
}


int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
//Important
int romanToInt(string A) {
	//Roman TO Integer from 1 to 3999
    int res=0;
    for(int i=0;i<A.length();i++){
        int a=value(A[i]);
        if(i+1<A.length()){
            int b=value(A[i+1]);
            if(b>a){
                res=res+b-a;
                i++;
            }
            else{
                res=res+a;
            }
        }
        else{
            res=res+a;
            i++;
        }
        //cout<<res;
    }
    return res;
}

string addst(string A, string B){
    int n1=A.length();
    int n2=B.length();
    int carry=0;
    string s="";
    int j=n1-1,i=n2-1;
    while(i>=0){
        //cout<<i;
        int temp=A[j]-'0'+B[i]-'0'+carry;
        if(temp==0 || temp==1){
            s+=to_string(temp);
            carry=0;
        }
        if(temp==2){
            s+="0";
            carry=1;
        }
        if(temp==3){
            s+="1";
            carry=1;
        }
        i--;
        j--;
    }
    if(n1==n2){
        if(carry){
            s+="1";
        }
        reverse(s.begin(),s.end());
        return s;
    }
    //cout<<1;
    while(j>=0){
        int temp=A[j]-'0'+carry;
        if(temp==0 || temp==1){
            s+=to_string(temp);
            carry=0;
        }
        if(temp==2){
            s+="0";
            carry=1;
        }
        j--;
    }
    if(carry){
        s+="1";
    }
    reverse(s.begin(),s.end());
    return s;
}

string addBinary(string A, string B) {
	//Adds strings which contains binary numbers
    int n1=A.length();
    int n2=B.length();
    if(n1>n2){
        return addst(A,B);
    }
    return addst(B,A);
    
}

int atoi(const string A) {
	//Converrt String to Integer
    int n=A.length();
    int index=0;
    int start;
    int sign=1;
    while(A[index]==' '){
        index++;
    }
    while(A[index]=='0'){
        index++;
    }
    if(A[index]=='-'){
        sign=-1;
        index++;
    }
    if(A[index]=='+'){
        sign=1;
        index++;
    }
    while(A[index]=='0'){
        index++;
    }
    start=index;
    while(A[index]>='0' && A[index]<='9'){
        index++;
    }
    if(index-start>=10){
        if(index-start>=11){
            if(sign==-1){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }
        string s;
        if(sign==1){
           s=to_string(pow(2,31)-1);
        }
        else{
            s=to_string(pow(2,31));
        }
        string p=A.substr(start,31);
        for(int i=0;i<31;i++){
            if(p[i]<s[i]){
                break;
            }
            if(p[i]>s[i]){
                //cout<<1;
                if(sign==-1){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
        }
    }
    //cout<<start<<index<<sign<<endl;
    int ans=0;
    for(int i=start;i<index;i++){
        ans=ans*10+A[i]-'0';    
    }
    //cout<<ans;
    return sign*ans;
}

//Given a string which contains lower alphabetic characters, 
//we need to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string.
bool allSame(int freq[], int N)
{
    int same;
 
    //    get first non-zero element
    int i;
    for (i = 0; i < N; i++)
    {
        if (freq[i] > 0)
        {
            same = freq[i];
            break;
        }
    }
 
    //    check equality of each element with variable same
    for (int j = i+1; j < N; j++)
        if (freq[j] > 0 && freq[j] != same)
            return false;
 
    return true;
}
 
// Returns true if we can make all character
// frequencies same
bool possibleSameCharFreqByOneRemoval(string str)
{
    int l = str.length();
 
    //    fill frequency array
    int freq[M] = {0};
    for (int i = 0; i < l; i++)
        freq[str[i]-'a']++;
 
    //    if all frequencies are same, then return true
    if (allSame(freq, M))
        return true;
 
    /*  Try decreasing frequency of all character
        by one and then    check all equality of all
        non-zero frequencies */
    for (char c = 'a'; c <= 'z'; c++)
    {
        int i = c-'a';
 
        // Check character only if it occurs in str
        if (freq[i] > 0)
        {
            freq[i]--;
 
            if (allSame(freq, M))
                return true;
            freq[i]++;
        }
    }
 
    return false;
}


int mininsertionatbeginningforpalindrome(string A) {
/*
You are given a string. The only operation allowed is to insert characters in the beginning of the string. 
How many minimum characters are needed to be inserted to make the string a palindrome string
Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2
*/
    int n=A.length();
    if(n==0){
        return 0;
    }
    if(n==1){
        return 0;
    }

    int i=0,j=n-1;
    int count=0;
    while(i<j){
        if(A[i]==A[j]){
            int temp1=i,temp2=j;
            while(temp1<temp2){
                if(A[temp1]!=A[temp2]){
                    break;
                }
                else{
                    temp1++;
                    temp2--;
                }
            }
            if(temp1>=temp2){
                break;
            }
            else{
                count++;
                j--;
            }
        }
        else{
            count++;
            j--;
        }
    }
    return count;
}


string addstdec(string A,string B){
    int n1=A.length();
    int n2=B.length();
    int carry=0,i=n2-1,j=n1-1;
    string ans="";
    for(;i>=0;i--,j--){
        int temp=A[j]+B[i]-'0'-'0'+carry;
        carry=temp/10;
        int t=temp%10;
        //cout<<t;
        ans+=to_string(t);
    }
    for(;j>=0;j--){
        int temp=A[j]+carry-'0';
        carry=temp/10;
        int t=temp%10;
        ans+=to_string(t);
    }
    
    if(carry){
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string add(string A, string B){
    int n1=A.length();
    int n2=B.length();
    if(n1>n2){
        return addstdec(A,B);
    }
    return addstdec(B,A);
}

string multiply(string A, string B) {
    //Given two numbers represented as strings, return multiplication of the numbers as a string.
    int n1=A.length();
    int n2=B.length();
    string ans="0";
    string temp=A;
    int p;
    for(p=0;p<n1;p++){
        if(temp[p]!='0'){
            break;
        }
    }
    temp=temp.substr(p,n1-p);
    
    for(int i=n2-1;i>=0;i--){
        int t=B[i]-'0';
        //cout<<t<<",";
        for(int k=0;k<t;k++){
            ans=add(ans,temp);
            //cout<<ans<<"#";
        }
        //cout<<" ";
        //cout<<temp<<" ";
        temp=temp+"0";
    }
    return ans;
}

string ZigZagconvert(string A, int B) {
    if(B==1){
        return A;
    }
    if(A.length()<=B){
        return A;
    }
    
    vector<string> ans(B);
    int step=1,j=0;
    for(int i=0;i<A.length();i++){
        ans[j].push_back(A[i]);
        if(j==B-1){
            step=-1;
        }
        if(j==0){
            step=1;
        }
        j+=step;
    }
    string final="";
    for(int i=0;i<B;i++){
        final+=ans[i];    
    }
    return final;
}


int main(){
	string ans=findsubstring("Aditdya","dt");
	cout<<ans<<endl;
	pair<char,int> s=maxoccuringchar("aditya");
	cout<<s.first<<" "<<s.second<<endl;
	string str="aditya";
	int k=kthnonrepaeatingchar(str,2);
	if(k!=-1){
		cout<<str[k]<<endl;
	}
	cout<<decrypt("a1ab2")<<endl;
	cout<<findcountatcorrectpos("AbCed")<<endl;
	cout<<arekAnagrams("anagram","grammar")<<endl;
	cout<<countwords("One two         three\n    four\tfive  ")<<endl;
	cout<<countrepetitionword("Aditya is good Aditya","Aditya")<<endl;
	cout<<isPalindromeWithRotation("aab")<<endl;
	cout<<isPalindromeWithRotation("aaaab")<<endl;
	cout<<isPalindromeWithRotation("abcde")<<endl;
	return 0;
}
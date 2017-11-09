#include <bits/stdc++.h>
using namespace std;

void hashing(int hash[], string s, int i){
	hash[i] = (s[i-1] - 'a' + 1 + 27*hash[i-1])%INT_MAX;
}



int main(){
	string s;
	cin>>s;
	int t;
	cin>>t;
	int hash[1+s.length()] = {0};
	int mul = 1;
	for(int i=1;i<=s.length();i++){
		hashing(hash, s, i);
	}
	while(t--){
		int s1, e1, s2, e2;
		cin>>s1>>e1>>s2>>e2;
		// s1--;
		// e1--;
		// s2--;
		// e2--;
		if(hash[e1]-hash[s1-1]*pow(27, e1-s1+1)==hash[e2]-hash[s2-1]*pow(27, e2-s2+1)){
			string p,q;
			for(int i=s1-1;i<=e1-1;i++){
				p = p + s[i];
			}
			for(int i=s2-1;i<=e2-1;i++){
				q = q + s[i];
			}
			if(p==q)
				cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
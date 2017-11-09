#include <bits/stdc++.h>
using namespace std;
//hash function for strings
int string_hash(int start, int end, string hash){
	int h=0;
	for(int i=start;i<=end;i++){
		h = (h*31 + hash[i]);
	}
	return h;
}
//MAIN function
int main(){
	string s;
	cin>>s;
	int t;
	cin>>t;
	while(t--){
		int s1, e1, s2, e2;
		cin>>s1>>e1>>s2>>e2;
		s1--;
		e1--;
		s2--;
		e2--;
		int a = string_hash(s1, e1, s);
		int b = string_hash(s2, e2, s);
		//if hashy values are equal, then string compare (Reduces run time)
		if(a==b){
			string p,q;
			//string comparison
			for(int i=s1;i<=e1;i++){
				p = p + s[i];
			}
			for(int i=s2;i<=e2;i++){
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
#include <bits/stdc++.h>
using namespace std;
//string hash function
int string_hash(int start, int end, string hash){
	int h=0;
	for(int i=start;i<=end;i++){
		h = (h*31 + hash[i]);
	}
	return h;
}
//MAIN function
int main(){
	int t;
	cin>>t;
	while(t--){

		string s;
		cin>>s;

		int flag=0;

		string test;
		cin>>test;
		int p = string_hash(0, test.length()-1, test);
		//scans the hole string and removes all the ocurrences in 1 go
		//by comparing hash value of test string to the small parts of main string
		for(int i=test.length()-1;i<=s.length();i++){

			if(string_hash(i-test.length()+1, i, s)==p){
				//for accurate results, we do string comparison
				string y;
				for(int j=i-test.length()+1;j<=i;j++){
					y = y + s[j];
				}
				if(y==test){
					//erase if found
					s.erase(i-test.length()+1, test.length());
					//removes the possiblity of formation of new test string without our knowledge
					i = i - test.length();
					//if(i<0)i = test.length()-1;
				}
			}

		}	

		cout<<s<<endl;
		
	}
	return 0;
}
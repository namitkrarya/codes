#include <iostream>
using namespace std;

int hash_val(string str, int m, int n, int base, int prime) {
	m = m-1;
	n = n-1;
	int result=0;
	for (int i = 0; i <= n-m; ++i) {
		result= (base*result + str[m+i])%prime;
	}
	return result;
}

int main()
{
	string str;
	int N, base=7, prime=101;
	cin >> str >> N;
	int ind_1s, ind_1e;
	int ind_2s, ind_2e;

	for (int _ = 0; _ < N; ++_)
	{
		cin >> ind_1s >> ind_1e >> ind_2s >> ind_2e;
		int hash_value1 = hash_val(str,ind_1s,ind_1e,base,prime);
		int hash_value2 = hash_val(str,ind_2s,ind_2e,base,prime);

		if(hash_value1 != hash_value2)
			cout << "NO\n";
		else
		{
			int i;
			for (i = 0; i < ind_2e - ind_2s; ++i)
			{
				if(str[i+ind_1s] != str[i+ind_2s])
				{
					cout << "NO\n";
					break;
				}
			}
			if(i == ind_2e - ind_2s)
				cout << "YES\n";
		} 	
	}
}
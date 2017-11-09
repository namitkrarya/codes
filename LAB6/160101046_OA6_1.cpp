#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Input :"<<endl;	
	char words[100][100];															//stores the input words
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>words[i];
	}	
	int arr[26][26];																//2-d array ,each segment corresponding to an alphabet
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			arr[i][j] = -1;															//initialiizing the array with -1(means no info given yet)
		}
	}
	int base = 'a';																	//stores ASCII value of 'a'
	for(int i=0;i<t;i++)
	{																				//scans all possible combination of letters in every word
		for(int k=0;k<strlen(words[i]);k++)
		{
			for(int j=k+1;j<strlen(words[i]);j++)
			{
				if(arr[words[i][k]-base][words[i][j]-base]==-1)
				{
					arr[words[i][k]-base][words[i][j]-base] = 1;					//if letter combination found, makes it 1 in the arr
					for(int m=0;m<26;m++)
					{
					    if(arr[words[i][j]-base][m]==1)								//for examples like ab bc ca, we make ab = 1, then bc = 1 and ac = 1
					    {
					        arr[words[i][k]-base][m] = 1;
					        if(m!=(words[i][j]-base))
					        {
						        arr[m][words[i][k]-base] = 0;						//makes the opposite of it 0 only if both are not same
					        }
					    }
					    
					    if(arr[m][words[i][k]-base]==1)
					    {
					        arr[m][words[i][j]-base] = 1;
					        if(m!=(words[i][j]-base))
					        {
						        arr[words[i][j]-base][m] = 0;
					        }
					    }
					}
					if(words[i][k]!=words[i][j])
					{
						arr[words[i][j]-base][words[i][k]-base] = 0;
					}
					continue;
				}
				else if(arr[words[i][k]-base][words[i][j]-base]==1)continue;		//if same data is already stores, continue	
				else if(arr[words[i][k]-base][words[i][j]-base]==0)					//if location is 0 already,means impossible
				{
					cout<<"Impossible"<<endl;
					return 0;	
				}
			}
		}
	}
	cout<<"Possible"<<endl;
	return 0;
}
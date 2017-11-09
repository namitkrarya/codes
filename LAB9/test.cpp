#include <bits/stdc++.h>
#include <string>
using namespace std;
struct node
{
	int d;
	int max;
	int color;
	string s;
	int cn;
	int fn;
	node * next;
};

// node * getNode(int d, int cn, int fn){
// 	node * temp = new node;
// 	temp->max = 1;
// 	temp->d = d;
// 	temp->color = 0;
// 	temp->cn = cn;
// 	temp->fn = fn;
// 	temp->next = NULL;
// 	string s;
// 	if(fn==0)s = " front\n";
// 	if(fn==1)s = " back\n";
// 	if(fn==2)s = " left\n";
// 	if(fn==3)s = " right\n";
// 	if(fn==4)s = " top\n";
// 	if(fn==5)s = " bottom\n";
// 	stringstream ip;
// 	ip<<(cn);
// 	s = ip.str() + s;
// 	temp->s = s;
// 	return temp; 
// }

void ins(node * &last, int cn, int fn){
	node * temp = new node;
	temp->cn = cn;
	temp->fn = fn;
	last->next = temp;
	last = temp;
	return;
}

void dfs(node * head[][6], int cn, int fn){
	node * temp = head[cn][fn]->next;
	head[cn][fn]->color = 1;
	while(temp!=NULL){

		if(head[temp->cn][temp->fn]->color==0){
			
			dfs(head, temp->cn, temp->fn);
		}
		temp = temp->next;
	}
	head[cn][fn]->color = 2;
	if(head[cn][fn]->next==NULL){
		return;
	}
	temp = head[cn][fn]->next;
	int ma=0;
	string s = "";
	while(temp!=NULL){
		if(ma<head[temp->cn][temp->fn]->max){
			ma = head[temp->cn][temp->fn]->max;
			s = head[temp->cn][temp->fn]->s;
		}
		temp = temp->next;
	}
	head[cn][fn]->max = 1 + ma;
	head[cn][fn]->s = head[cn][fn]->s + s;
	return; 
}

int main(){
	int t;
	int a = 0;
	while(1){
		cin>>t;
		if(t==0)break;
		a++;
		node * head[t+1][6];
		node * last[t+1][6];
		for(int i=1;i<=t;i++){
			for(int j=0;j<6;j++){
				int l;
				cin>>l;
				head[i][j] = new node;
				head[i][j]->max = 1;
				head[i][j]->d = l;
				head[i][j]->color = 0;
				head[i][j]->cn = i;
				head[i][j]->fn = j;
				head[i][j]->next = NULL;
				string s;
				if(j==0)s = " front\n";
				if(j==1)s = " back\n";
				if(j==2)s = " left\n";
				if(j==3)s = " right\n";
				if(j==4)s = " top\n";
				if(j==5)s = " bottom\n";
				stringstream ip;
				ip<<(i);
				s = ip.str() + s;
				head[i][j]->s = s;
				last[i][j] = head[i][j];
			}
		}
		for(int cn=1;cn<=t;cn++){
			for(int j=cn+1;j<=t;j++){
				for(int i=0;i<6;i++){
					for(int k=0;k<6;k++){
						if(head[j][k]->d==head[cn][i]->d){
							if(i%2==0){
								ins(last[cn][i+1], j, k);
							}	
							else{
								ins(last[cn][i-1], j, k);
							}
						}
					}
				}
			}
		}

		for(int cn=1;cn<=t;cn++){
			for(int i=0;i<6;i++){
				if(head[cn][i]->color==0)
					dfs(head, cn, i);
			}
		}
		int ma=0;
		string f = "";
		for(int cn=1;cn<=t;cn++){
			for(int i=0;i<6;i++){
				if(ma<head[cn][i]->max){
					ma = head[cn][i]->max;
					f = head[cn][i]->s;
				}
			}
		}
		cout<<"Case #"<<a<<endl;
		cout<<ma<<endl;
		cout<<f<<endl;
	}
	return 0;
}
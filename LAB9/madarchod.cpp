#include <bits/stdc++.h>
#include <string>
using namespace std;
struct node2{
	int cn;
	int fn;
	node2 * next;
};
struct node
{
	int d;
	int max;
	int color;
	string s;
	int cn;
	int fn;
	node2 * next;
};

node * getNode(node * temp, int d, int cn, int fn){
	//node * temp = new node;

	temp->max = 1;
	temp->d = d;
	temp->color = 0;
	temp->cn = cn;
	temp->fn = fn;
	temp->next = NULL;
	string s;
	if(fn==0)s = " front\n";
	else if(fn==1)s = " back\n";
	else if(fn==2)s = " left\n";
	else if(fn==3)s = " right\n";
	else if(fn==4)s = " top\n";
	else if(fn==5)s = " bottom\n";
	stringstream ip;
	ip<<(cn);
	s = ip.str() + s;
	temp->s = s;
	return temp; 
}

void ins(node * head, node2 * &last, int cn, int fn){
	node2 * temp = new node2;
	temp->cn = cn;
	temp->fn = fn;
	if(last==NULL){
		head->next = temp;
		last = temp;
		return;
	}
	last->next = temp;
	last = temp;
	return;
}

void dfs(node * head[][6], int cn, int fn){
	node2 * temp = head[cn][fn]->next;
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

// node * free_fucks(node * head){
// 	node * temp = head;
// 	node * temp1;
// 	while(temp!=NULL){
// 		temp1 = temp;
// 		temp = temp->next;
// 		delete temp1;
// 	}
// 	return NULL;
// }

int main(){
	int t;
	int a = 0;
	node * head[501][6] = {NULL};
	node2 * last[501][6] = {NULL};
	for(int i=1;i<501;i++){
		for(int j=0;j<6;j++){
			head[i][j] = new node;
		}
	}
	while(1){
		cin>>t;
		if(t==0)break;
		a++;
		

		for(int cn=1;cn<=t;cn++){
			int x1, x2, x3, x4, x5, x6;
			cin>>x1>>x2>>x3>>x4>>x5>>x6;
			head[cn][0] = getNode(head[cn][0], x1, cn, 0);
			//last[cn][0] = head[cn][0];
			head[cn][1] = getNode(head[cn][1], x2, cn, 1);
			//last[cn][1] = head[cn][1];
			head[cn][2] = getNode(head[cn][2], x3, cn, 2);
			//last[cn][2] = head[cn][2];
			head[cn][3] = getNode(head[cn][3], x4, cn, 3);
			//last[cn][3] = head[cn][3];
			head[cn][4] = getNode(head[cn][4], x5, cn, 4);
			//last[cn][4] = head[cn][4];
			head[cn][5] = getNode(head[cn][5], x6, cn, 5);
			//last[cn][5] = head[cn][5];
			for(int j=1;j<cn;j++){
				for(int k=0;k<6;k++){
					for(int i=0;i<6;i++){
						if(head[j][k]->d==head[cn][i]->d){
							if(k==0)
								ins(head[j][1], last[j][1],cn,i);
							if(k==1)
								ins(head[j][0], last[j][0],cn,i);
							if(k==2)
								ins(head[j][3], last[j][3],cn,i);
							if(k==3)
								ins(head[j][2], last[j][2],cn,i);
							if(k==4)
								ins(head[j][5], last[j][5],cn,i);
							if(k==5)
								ins(head[j][4], last[j][4],cn,i);
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
				head[cn][i]->next = NULL;
				//delete head[cn][i];
				//head[cn][i] = free_fucks(head[cn][i]);
			}
		}

		cout<<"Case #"<<a<<endl;
		cout<<ma<<endl;
		cout<<f<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#include <string>
using namespace std;

//creating struct
struct node
{
	int d;
	int max;
	int color;
	int cn;
	int fn;

	string s;

	node * next;
};

//alloting space and initializing nodes
node * getNode(int d, int cn, int fn){

	node * temp = new node;

	temp->max = 1;
	temp->d = d;
	temp->color = 0;
	temp->cn = cn;
	temp->fn = fn;
	temp->next = NULL;
	
	string s;

	switch(fn){
		case 0: s = " front\n";break;
		case 1: s = " back\n";break;
		case 2: s = " left\n";break;
		case 3: s = " right\n";break;
		case 4: s = " top\n";break;
		case 5: s = " bottom\n";break;
	}

	stringstream ip;
	ip<<(cn);
	s = ip.str() + s;
	temp->s = s;

	return temp; 
}

//inserts in each nodes adjacent list
void ins(node * &last, int cn, int fn){

	node * temp = new node;

	temp->cn = cn;
	temp->fn = fn;
	last->next = temp;
	last = temp;

	return;
}

//Depth-First-Search
void dfs(node * head[][6], int cn, int fn){

	node * temp = head[cn][fn]->next;

	head[cn][fn]->color = 1;

	while(temp!=NULL){

		if(head[temp->cn][temp->fn]->color==0)						//if color is white, traverse the node
			dfs(head, temp->cn, temp->fn);

		temp = temp->next;
	}

	head[cn][fn]->color = 2;

	if(head[cn][fn]->next==NULL)
		return;
	
	temp = head[cn][fn]->next;

	int ma=0;
	string s = "";

	while(temp!=NULL){												//find max in adjacent list

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

	//initializing all heads
	node * head[501][6] = {NULL};
	node * last[501][6];

	while(1){

		cin>>t;
		if(t==0)break;

		a++;
		
		for(int cn=1;cn<=t;cn++){

			int x1, x2, x3, x4, x5, x6;
			cin>>x1>>x2>>x3>>x4>>x5>>x6;

			head[cn][0] = getNode(x1, cn, 0);
			last[cn][0] = head[cn][0];

			head[cn][1] = getNode(x2, cn, 1);
			last[cn][1] = head[cn][1];

			head[cn][2] = getNode(x3, cn, 2);
			last[cn][2] = head[cn][2];

			head[cn][3] = getNode(x4, cn, 3);
			last[cn][3] = head[cn][3];

			head[cn][4] = getNode(x5, cn, 4);
			last[cn][4] = head[cn][4];

			head[cn][5] = getNode(x6, cn, 5);
			last[cn][5] = head[cn][5];

			//traversing bottom to top for each cube to create adjacent list of every node
			for(int j=1;j<cn;j++){

				for(int k=0;k<6;k++){

					for(int i=0;i<6;i++){

						if(head[j][k]->d==head[cn][i]->d){
							
							switch(k){
								case 0: ins(last[j][1],cn,i);break;
								case 1: ins(last[j][0],cn,i);break;
								case 2: ins(last[j][3],cn,i);break;
								case 3: ins(last[j][2],cn,i);break;
								case 4: ins(last[j][5],cn,i);break;
								case 5: ins(last[j][4],cn,i);break;
							}

						}
					}
				}
			}
		}

		//calling dfs for every node if its white
		for(int cn=1;cn<=t;cn++){

			for(int i=0;i<6;i++){

				if(head[cn][i]->color==0)
					dfs(head, cn, i);

			}
		}

		int ma=0;
		string f = "";

		//finds max in all nodes
		for(int cn=1;cn<=t;cn++){

			for(int i=0;i<6;i++){

				if(ma<head[cn][i]->max){

					ma = head[cn][i]->max;
					f = head[cn][i]->s;

				}

				head[cn][i]=NULL;
			}
		}

		cout<<"Case #"<<a<<endl;
		cout<<ma<<endl;
		cout<<f<<endl;

	}
	return 0;
}
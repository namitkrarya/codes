#include <bits/stdc++.h>
using namespace std;

//color 0 - white
//color 1 - gray
//color 2 - black

struct node{
	int k;		//stores the distance
	int d;		//stores vertex no.
	int f;		
	int color;	//color of node
	int parent;	//node parent
	int rank;	//rank in stack
	int flag;
	node * next;
};
//stores cycle in linked list
struct node1{
	int data;
	int flag;
	node1 * next;
};

node * getNode(int d){
	node * temp = new node;
	temp->d = d;
	temp->k = INT_MAX;
	temp->f = INT_MAX;
	temp->flag=0;
	temp->parent = 0;
	temp->color = 0;
	return temp;
}

node1 * getNode1(int d){
	node1 * temp = new node1;
	temp->data = d;
	temp->flag=0;
	return temp;
}
//linked list to store cycles
void store(node1 ** head, int d, int f){
	node1 * temp = *head;
	node1 * nw = getNode1(d);
	nw->flag = f;
	if(temp==NULL){
		*head = nw;
	}
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = nw;
	}
}
//insert in stack
void in_stack(int q[], int &top, int d){
	top++;
	q[top] = d;
}
//delete from stack
void out_stack(int &top){
	top--;
}
//insert in adjacent list
void ins_last(node * head[], int d, int n){
	node * temp = head[d];
	node * inp = getNode(n);
	if(temp==NULL){
		head[d] = inp;
	}
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = inp;
	}
}
//stores cycle in linked list
void printstack(int q[], int &top, int s,node1**head1){
	for(int i=s-1;i<=top;i++){
		//whenever a cycle is stored, at the end of every cycle, flag of node is made 1, otherwise 0
		if(i==top){
			store(head1, q[i],1);	
		}
		else store(head1, q[i],0);
	}
}

void dfs_visit(int q[], int &top, node * head[], int n, int &time, int &count, int &count1, int &r,node1**head1){
	head[n]->color = 1;
	time++;
	head[n]->k = time;
	in_stack(q, top, n);
	head[n]->rank = r;
	r++;
	node * temp = head[n]->next;
	while(temp!=NULL){
		//whenever a gray node is found and it is not the parent, its a cycle
		if(head[temp->d]->color==1&&head[n]->parent!=temp->d){
			in_stack(q, top, temp->d);
			printstack(q,top,head[temp->d]->rank,head1);
			out_stack(top);
			count++;
		}
		if(head[temp->d]->color==0){
			head[temp->d]->parent = n;
			dfs_visit(q, top, head, temp->d, time, count, count1, r,head1);
		}
		temp = temp->next;
	}
	out_stack(top);
	head[n]->color = 2;
	head[n]->flag=count1;
	time++;
	head[n]->f = time;
	return;
}

void dfs(int q[], int &top, node * head[], int n, int &count, int &count1,node1**head1){
	int time = 0;
	int r=1;
	for(int i=1;i<=n;i++){
		//counts no. of components
		if(head[i]->color!=2&&i!=1)count1++;
		if(head[i]->color==0){
			dfs_visit(q, top, head, i, time, count, count1, r,head1);
			r=1;
		}
	}
}



int main(){
	int n, e;
	node1 * head1 = NULL;
	cout<<"Input no. of nodes : ";
	cin>>n;
	cout<<"Input no. of edges : ";
	cin>>e;
	cout<<"Input next "<<e<<" lines in the form <u v>"<<endl;
	node * head[n+1];
	for(int i=1;i<=n;i++){
		head[i] = getNode(i);
	}
	int q[n+1] = {0};
	int top=-1;
	int count=0,count1=1;
	for(int i=0;i<e;i++){
		int n1, n2;
		cin>>n1>>n2;
		ins_last(head, n1, n2);
		if(n1!=n2){
			ins_last(head, n2, n1);
		}
	}
	dfs(q, top, head, n,count,count1,&head1);
	//prints all the components
	cout<<"The number of connected components are : "<<count1<<endl;
	for(int i=1;i<=count1;i++){ 
		cout<<"Connected components "<<i<<": ";		
		for(int j=1;j<=n;j++){
			node * temp = head[j];
			if(temp->flag==i){
				cout<<temp->d<<" ";
			}
			temp = temp->next;
		}
		cout<<endl;
	}
	//prints all the cycles
	cout<<"The number of cycles: "<<count<<endl;
	node1 * temp = head1;
	int u = 2;
	if(count!=0)cout<<"Cycle 1: ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		if(temp->flag==1){
			cout<<endl;
			if(temp->next!=NULL)cout<<"Cycle "<<u++<<": ";
		}
		temp = temp->next;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct node{
	int k;
	int d;
	int color;
	int parent;
	node * next;
};

node * getNode(int d){
	node * temp = new node;
	temp->d = d;
	temp->k = INT_MAX;
	temp->parent = 0;
	temp->color = 0;
	return temp;
}

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

void enq(int q[], int d, int &rear){
	q[++rear] = d;
}

int deq(int q[], int &front){
	front++;
	return q[front-1];
}

void bfs(node * head[], int q[], int y, int &rear, int &front){
	head[y]->color = 1;
	head[y]->k = 0;
	enq(q, y, rear);
	while(front-rear!=1){
		int u = deq(q,front);
		node * temp = head[u];
		while(temp!=NULL){
			if(head[temp->d]->color==0){
				head[temp->d]->color=1;
				head[temp->d]->k=head[u]->k+1;
				head[temp->d]->parent = u;
				enq(q, temp->d, rear);
			}
			temp = temp->next;
		}
		head[u]->color = 2;
	}
}

int printpath(node * head[], int s, int v){
	if(v==s){
		cout<<head[s]->d<<" ";
		return 1;
	}
	else if(head[v]->parent==0){
		cout<<"No path"<<endl;
		return 0;
	}
	else{
		int u = printpath(head, s, head[v]->parent);
		if(u==0)return 0;
		cout<<head[v]->d<<" ";
		return 1;
	}
}

int main(){
	int n, e;
	cin>>n>>e;
	node * head[n+1];
	for(int i=1;i<=n;i++){
		head[i] = getNode(i);
	}
	int q[n+1] = {0};
	int rear = -1;
	int front = 0;
	for(int i=0;i<e;i++){
		int n1, n2;
		cin>>n1>>n2;
		ins_last(head, n1, n2);
		ins_last(head, n2, n1);
	}
	cout<<endl;
	
	bfs(head, q, 1, rear, front);
	for(int i=1;i<n+1;i++){
		cout<<head[i]->k<<" ";
	}
	cout<<endl;
	int f = printpath(head, 1, 5);
	cout<<endl;

	return 0;
}
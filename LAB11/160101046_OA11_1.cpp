#include <bits/stdc++.h>
using namespace std;

struct node
{	
	node * left;
	node * right;
	node * par;
	int mark;
	int key;
};


node * getNode(int key){
	node * temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->key = key;
	temp->mark = 0;
	temp->par = NULL;
	return temp;
}


void insertNode(node * &root, int key){
	node * temp = root;
	if(root==NULL){
		node * inp = getNode(key);
		root = inp;
	}
	else{
		if(key<=root->key){
			insertNode(root->left, key);
		}
		else{
			insertNode(root->right, key);
		}
	}
}

void inorder(node * root){
	if(root->left!=NULL){
		inorder(root->left);
	}
	cout<<root->key<<" ";
	if(root->right!=NULL){
		inorder(root->right);
	}
}


void perm(node * root,node * head[], int &c, string &s, int n, int &count, string &final){
	if(c==0){
		count++;
		final = final + s + '\n';
		return;
	}
	int t = c;
	for(int i=0;i<t;i++){
		node * h[n] = {NULL};
		for(int j=0;j<t;j++){
			h[j] = head[j];
		}
		int y = i;
		node * temp = h[y];
		if(temp==NULL)continue;
		for(int k=y;k<t-1;k++){
			h[k] = h[k+1];
		}
		h[t-1] = NULL;
		stringstream ip;
		ip<<temp->key;
		s = s + ip.str() + " ";
		c--;
		if(temp->left!=NULL){
			for(int k=c;k>y;k--){
				h[k] = h[k-1];
			}
			h[y] = temp->left;
			y++;
			c++;
		}
		if(temp->right!=NULL){
			for(int k=c;k>y;k--){
				h[k] = h[k-1];
			}
			h[y] = temp->right;
			y++;
			c++;
		}
		perm(root, h, c, s, n, count, final);
		s.erase(s.length()-ip.str().length()-1, ip.str().length()+1);
		c = t;
	}
}

int main(){
	int n;
	cin>>n;
	node * root = NULL;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		insertNode(root, t);
	}
	//inorder(root);
	node * head[n];
	int c = 0;
	string s = "";
	head[0] = root;
	// stringstream ip;
	// ip<<root->key;
	// s = s + ip.str() + " " ;
	c++;
	int count = 0;
	cout<<endl;
	string final = "";
	perm(root, head, c, s, n, count, final);
	cout<<count<<endl;
	cout<<final;
	return 0;
}
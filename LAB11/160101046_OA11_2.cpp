#include <bits/stdc++.h>
using namespace std;
struct node{
	node * left;
	node * right;
	node * par;
	int key;
	int fq;
};

node * getNode(int key){
	node * temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->par = NULL;
	temp->key = key;
	temp->fq = 1;
}

node * getNode1(int fq, int key){
	node * temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->par = NULL;
	temp->key = key;
	temp->fq = fq;
}

void insertNode(node * &root, int key){
	node * temp = root;
	if(root==NULL){
		node * inp = getNode(key);
		root = inp;
		return;
	}
	else{
		node * temp1 = temp;
		while(temp!=NULL && temp->key!=key){
			temp1 = temp;
			if(temp->key>key){
				temp = temp->left;
			}
			else if(temp->key<key){
				temp = temp->right;
			}
		}
		if(temp==NULL){
			node * inp = getNode(key);
			if(key>temp1->key)temp1->right = inp;
			else temp1->left = inp;
			inp->par = temp1;
			return;
		}
		else{
			(temp->fq)++;
			return;
		}
	}
}

void insertNode1(node * &root, int fq, int key){
	node * temp = root;
	if(root==NULL){
		node * inp = getNode1(fq, key);
		root = inp;
		return;
	}
	else{
		node * temp1 = temp;
		while(temp!=NULL){
			temp1 = temp;
			if(temp->fq<fq){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}
		}
		if(temp==NULL){
			node * inp = getNode1(fq, key);
			if(fq>temp1->fq)temp1->left = inp;
			else temp1->right = inp;
			inp->par = temp1;
			return;
		}
	}
}

void inOrder(node * root, node * &root1){
	if(root==NULL)return;
	if(root->left!=NULL){
		inOrder(root->left, root1);
	}

	insertNode1(root1, root->fq, root->key);

	if(root->right!=NULL){
		inOrder(root->right, root1);
	}
	return;
}

void ino(node * root1){
	if(root1==NULL)return;
	if(root1->left!=NULL){
		ino(root1->left);
	}
	for(int i=0;i<root1->fq;i++)
		cout<<root1->key<<" ";
	if(root1->right!=NULL){
		ino(root1->right);
	}
	return;
}

int main(){
	node * root = NULL;
	node * root1 = NULL;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		insertNode(root, t);
	}
	inOrder(root, root1);
	ino(root1);
	cout<<endl;
	return 0;
}
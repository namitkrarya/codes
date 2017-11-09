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

struct node1
{
	node1 * next;
	node * p;
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


void perm(node * root,node1 * head, string &s, int n, int &count, string &final){
	if(head==NULL){
		count++;
		final = final + s + '\n';
		return;
	}
	node1 * trav = head;
	while(trav!=NULL){
		cout<<trav->p->key<<endl;
		node1 * h = new node1;
		h->next = NULL;
		h->p = head->p;
		node1 * temp2=h;
		node1 * temp1 = head->next;
		while(temp1!=NULL){
			node1 * t = new node1;
			t->next = NULL;
			t->p = temp1->p;
			temp2->next = h;
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		node1 * r = h;
		cout<<r->p->key;
		// while(r!=NULL){
		// 	cout<<r->p->key<<"x";
		// 	r = r->next;
		// }
		node * temp = trav->p;
		if(temp==NULL)continue;
		node1 * ty = h;
		node1 * ty1 = h;
		if(ty->next==NULL)h = NULL;
		else{
			while(ty->p->key!=trav->p->key){
				ty1 = ty;
				ty = ty->next;
			}
		}
		if(h!=NULL){
			if(ty==h){
				h = ty->next;
				ty1 = h;
			}
			else ty1->next = ty->next;
		}
		stringstream ip;
		ip<<temp->key;
		s = s + ip.str() + " ";
		if(temp->left!=NULL){
			node1 * i1 = new node1;
			i1->p = temp->left;
			i1->next = NULL;
			if(h==NULL){h = i1;ty1=h;}
			else{
				i1->next = ty1->next;
				ty1->next = i1;
				ty1 = ty1->next;
			}
		}
		if(temp->right!=NULL){
			node1 * i1 = new node1;
			i1->p = temp->right;
			i1->next = NULL;
			if(h==NULL)h = i1;
			else{
				i1->next = ty1->next;
				ty1->next = i1;
				ty1 = ty1->next;
			}
		}
		cout<<"x"<<endl;
		perm(root, h, s, n, count, final);
		s.erase(s.length()-ip.str().length()-1, ip.str().length()+1);
		trav = trav->next;
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
	node1 * head = new node1;
	string s = "";
	head->next = NULL;
	head->p = root;
	// stringstream ip;
	// ip<<root->key;
	// s = s + ip.str() + " " ;
	int count = 0;
	cout<<endl;
	string final = "";
	perm(root, head, s, n, count, final);
	cout<<count<<endl;
	cout<<final;
	return 0;
}
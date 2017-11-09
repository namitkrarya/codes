#include <bits/stdc++.h>
using namespace std;

struct node{
	int key;
	int deg;
	node * left;
	node * right;
	node * son;
};

node * getNode(int key){
	node * temp = new node;
	temp->key = key;
	temp->deg = 0;
	temp->right = temp;
	temp->left = temp;
	temp->son = NULL;
	return temp;
}
//concats 2 circular doubly linked list
node * concat(node * head1, node * head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	node * temp1 = head1->right;
	node * temp2 = head2->right;
	temp1->left = head2;
	head2->right = temp1;
	temp2->left = head1;
	head1->right = temp2;
	return head1;
}
//takes union of 2 circular doubly linked list mainting the min
node * unionF(node * head1, node * head2, node ** min1, node * min2){
	if(head2==NULL){
		(*min1) = (min2);
		return head1;
	}
	head1 = concat(head1,head2);
	if((*min1)->key>(min2)->key)
		(*min1) = (min2);
	return head1;
}
//inserts element in heap
node * insertF(node * head, int k, node ** min){
	node * temp = getNode(k);
	head = unionF(temp,head,min,temp);
	return head;
}
//transfers node from root list to child list
node * FHlink(node ** tra, node * head, node ** x, node ** y){
	if(head==(*x)){
		head = head->left;
	}
	if((*tra)==(*x)){
		(*tra) = (*tra)->left;
	}
	(*x)->right->left = (*x)->left;
	(*x)->left->right = (*x)->right;
	(*x)->right = (*x);
	(*x)->left = (*x);
	(*y)->son = concat((*x),(*y)->son);
	((*y)->deg)++;
	return head;
}
//consolidates child of min and the root list
node * consolidate(node * head,int n){
	if(head==NULL){
		return head;
	}
	int size = log2(n);
	node * tra = head;
	int d;
	node * ptr;
	node * a[size+1];
	for(int i=0;i<size+1;i++){
		a[i]=NULL;
	}
	do{
		node * x = tra;
		d = x->deg;
		tra = tra->left;
		while(a[d]!=NULL){
			ptr = a[d];
			if(x->key>ptr->key){
				node * sw = x;
				x = ptr;
				ptr = sw;
			}
			head = FHlink(&tra,head,&ptr,&x);
			a[d] = NULL;
			d++;
		}
		a[d] = x;	
	}while(tra!=head);
	return head;
}
//deletes min from the heap
node * extractMin(node * head, node ** min, int n){
	if(head==NULL){
		cout<<"Empty Heap"<<endl;
		return NULL;
	}
	node * temp = (*min);
	node * temp1 = temp->left;
	temp1->right = temp->right;
	temp->right->left = temp1; 
	if(head==(*min)){
		if(head->right==head)
			head = NULL;
		else{
			head = temp1;
		}
	}
	head = concat(head,temp->son);
	head = consolidate(head, n);
	free(temp);
	temp = NULL;
	if(head==NULL){
		return head;
	}
	node * temp2 = head;
	node * tra = head->right;
	(*min)=head;
	while(tra!=temp2){
		if(tra->key<(*min)->key)
			(*min) = tra;
		tra = tra->right;
	}
	return head;
}

//prints heap with degree and key of every node
void showheap(node *list , int depth )
{
	if (list != NULL)
	{
		node *ptr = list;
		do{
			for(int i = 0;i<depth;i++)
				cout<<"\t";
			cout<<"{"<<ptr->key<<", "<<ptr->deg<<"}\n";
			if (ptr->son != NULL)
			{
				showheap(ptr->son , depth+1);
			}
			ptr = ptr->right;
		}while(ptr != list && ptr != NULL);
	}
	else
	{
		cout<<"Empty List"<<endl;
	}
	return ;
}
//frees all the nodes and makes head NULL
node * makeheap(node * head){
	node * temp = head;
	if(head==NULL)return head;
	makeheap(temp->son);
	if(temp->right==temp){
		free(temp);
		return NULL;
	}
	node * temp1 = temp->right;
	temp->right->left = temp->left;
	temp->left->right = temp->right;
	free(temp);
	head = makeheap(temp1);
	return head;
}
//MAIN function
int main(){
	node * head = NULL;
	//maintains min of heap
	node * min = head;
	string s;
	int n=0;
	int flag=1;
	cout<<"Input('quit' to exit) : "<<endl;
	//command line interface
	while(cin>>s){
		if(s=="c"){
			head = makeheap(head);
			head = NULL;
			cout<<"Created Empty Heap"<<endl;
		}
		if(s=="i"){
			int l;
			cin>>l;	
			head = insertF(head, l, &min);
			n++;
		}
		if(s=="e"){
			if(flag==1&&head!=NULL)cout<<"Minimum extracted : "<<min->key<<endl;
			head = extractMin(head, &min,n);
			n--;
		}
		if(s=="S"){
			cout<<endl;
			cout<<"Structure of Fibonacci Heap :"<<endl;
			showheap(head,0);
			cout<<endl;
		}
		if(s=="+"){
			flag = 1;
		}
		if(s=="-"){
			flag = 0;
		}
		if(s=="#"){
			cin.ignore(2e9, '\n');
		}
		if(s=="quit"){
			return 0;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct node{
	string cmd;
	int val;
};
//to store output
struct output{
	output * next;
	string s;
	int d;
};

//swap function
void swap(int a[], int c, int b){
	int temp;
	temp = a[c];
	a[c] = a[b];
	a[b] = temp;
}
//finds min
int findmin(int a[], int l, int r){
	if(a[l]<a[r])return l;
	else return r;
}

//min heapify
void min_heapify(int n, int a[], int i){
	if(i>n/2)return;
	int l = 2*i;
	int r = 2*i+1;
	if(r>n){
		if(a[i]>a[l])swap(a,i,l);
		else return;
		return;
	}
	int k;
	int p = findmin(a,l,r);
	k = i;
	if(a[k]>a[p]){
		swap(a,k,p);
		min_heapify(n, a, p);
	}
	else return;
	return;
}
//returns value of top element of binary heap
int getMin(int *n, int a[]){
	int p = a[1];
	return p;
}

//delets minimum element
void removeMin(int *n, int a[]){
	swap(a,1,*n);
	(*n)--;
	return;
}
//insert in output linked list
output * insert(output * head, int v, string w){
	output * temp = head;
	output * ins = new output;
	if(head==NULL){
		head = ins;
		ins->s = w;
		ins->d = v;
		return head;
	}
	while(temp->next!=NULL){
		temp = temp->next;
	}
	
	temp -> next = ins;
	ins->s = w;
	ins->d = v;
	return head;
}
//MAIN function
int main(){
	cout<<"Input :"<<endl;
	int t;
	cin>>t;
	node inp[t];
	int a[100];
	for(int i=0;i<t;i++){
		cin>>inp[i].cmd;
		if(inp[i].cmd!="removeMin"){
			cin>>inp[i].val;
		}
	}
	output * head = NULL;
	int counter=0;
	int n=0;
	cout<<endl;
	for(int i=0;i<t;i++){
		if(inp[i].cmd=="insert"){
			counter++;
			n++;
			head = insert(head, inp[i].val, "insert ");
			//cout<<"insert "<<inp[i].val<<endl;
			a[n] = inp[i].val;
			min_heapify(n,a,0);
			continue;
		}
		if(inp[i].cmd=="getMin"){
			//check if heap is empty
			if(n==0){
				head = insert(head, inp[i].val, "insert ");
				n++;
				a[n] = inp[i].val;
				min_heapify(n,a,0);
				head = insert(head, inp[i].val, "getMin ");
				counter = counter + 2;
				continue;
			}
			//remove min till we get desired min
			while(getMin(&n, a)!=inp[i].val&&(n)!=0){
				//cout<<"removeMin"<<endl;
				removeMin(&n,a);
				head = insert(head, inp[i].val, "removeMin");
				counter++;
			}
			int k = n;
			//if heap get empty, insert element and getMin 
			if(n==0){
				//cout<<"insert "<<inp[i].val<<endl;
				head = insert(head, inp[i].val, "insert ");
				n++;
				a[n] = inp[i].val;
				min_heapify(n,a,0);
				//cout<<"getMin "<<inp[i].val<<endl;
				head = insert(head, inp[i].val, "getMin ");
				counter = counter +2;
			}

			else{
				//cout<<"getMin "<<inp[i].val<<endl;
				head = insert(head, inp[i].val, "getMin ");
				counter++;
			}

		}
		if(inp[i].cmd=="removeMin"){
			//check if heap is empty
			if(n==0){
				//cout<<"insert 0"<<endl;
				head = insert(head, 0, "insert ");
				n++;
				a[n] = inp[i].val;
				min_heapify(n,a,0);
				counter++;
			}
			//then remove
			removeMin(&n, a);
			//cout<<"removeMin"<<endl;
			head = insert(head, inp[i].val, "removeMin");
			counter++;
		}

	}
	cout<<counter<<endl;
	output * temp = head;
	//print output linked list
	while(temp!=NULL){
		cout<<temp->s;
		if(temp->s!="removeMin"){
			cout<<temp->d;
		}
		temp = temp->next;
		cout<<endl;
	}
	return 0;
}
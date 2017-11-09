#include <bits/stdc++.h>
using namespace std;

struct node{
	int key;
	int deg;
	node * sib;						
	node * son;										//leftmost son
};

node * getNode(int k){
	node * head = new node;
	head->deg = 0;
	head->key = k;
}
//links 2 nodes with same degree
node * BinomialLink(node * y, node * z, node ** head){		
	y->sib = z->son;
	z->son = y;
	(z->deg)++;
	if(*head==y){
		*head = z;
	}
	return z;
}

void showHeap(node* temp, int depth){
	if(temp->sib!=NULL){
		showHeap(temp->sib,depth);
	}
	if((temp->son)!=NULL){
		int p = temp->key/10;
		for(int i=0;i<depth;i++){
			cout<<"\t";
		}
		cout<<"\t"<<temp->key;
		if(temp->son==NULL)
			cout<<endl;
	}
	else{
		int k = temp->key/10;
		cout<<"\t"<<temp->key<<endl;
	}
	if(temp->son!=NULL){
		showHeap(temp->son, depth+1);
	}
}
//prints heap
void show(node * head){
	cout<<"Stucture of binomial heap (rotated 90 degrees ccwise):"<<endl;
	if(head==NULL){
		cout<<endl;
	}
	else{
		
		showHeap(head, 0);
		cout<<endl;
	}
}
//takes union of 2 binomial heaps
node * Union(node * head1, node * head2){
	node * head3 =NULL;
	node * temp3 = head3;
	node * tem3 = head3;
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	else{
		
		node * temp1 = head1;
		node * temp2 = head2;
		//merging the 2 heaps according to degree
		while(temp1!=NULL&&temp2!=NULL){
			if(temp1->deg<temp2->deg){
				if(head3==NULL){
					head3 = temp1;
				 	temp3 = temp1;
				 	temp1 = temp1->sib;
				 }
				else{
					temp3->sib = temp1;
					temp3 = temp3->sib;
					temp1 = temp1->sib;
				}
			}
			else{
				if(head3==NULL){
					head3 = temp2;
				 	temp3 = temp2;
				 	temp2 = temp2->sib;
				 }
				else{
					temp3->sib = temp2;
					temp3 = temp3->sib;
					temp2 = temp2->sib;
				}
			}
		}
		while(temp2!=NULL){
			temp3->sib = temp2;
			temp2 = temp2->sib;
			temp3 = temp3->sib;
		}
		while(temp1!=NULL){
			temp3->sib = temp1;
			temp1 = temp1->sib;
			temp3 = temp3->sib;
		}
	}
	temp3 = head3;
	tem3 = head3;
	//making links according to degree
	if(temp3->sib!=NULL){
		while((temp3->sib)->sib!=NULL){
			if(temp3->deg!=(temp3->sib)->deg){
				tem3 = temp3;
				temp3 = temp3->sib;
				continue;
			}
			if(temp3->deg==(temp3->sib)->deg&&temp3->deg==((temp3->sib)->sib)->deg){
				tem3 = temp3;
				temp3 = temp3->sib;
				continue;
			}
			if(temp3->deg==(temp3->sib)->deg&&temp3->deg!=((temp3->sib)->sib)->deg){
				if(temp3->key<temp3->sib->key){
					node * tem = temp3->sib->sib;
					temp3 = BinomialLink(temp3->sib,temp3, &head3);
					temp3->sib = tem;
				}
				else{
					if(tem3==temp3)
						tem3 = temp3 = BinomialLink(temp3, temp3->sib, &head3);
					else{
						temp3 = BinomialLink(temp3, temp3->sib, &head3);
						tem3->sib = temp3;
					}	
				}
				continue;
			}
		}
		if(temp3->deg==temp3->sib->deg){
			if(temp3->key<temp3->sib->key){
				node * tem = temp3->sib->sib;
				temp3 = BinomialLink(temp3->sib,temp3, &head3);
				temp3->sib = tem;
			}
			else{
				if(tem3==temp3)
					tem3 = temp3 = BinomialLink(temp3, temp3->sib, &head3);
				else{
					temp3 = BinomialLink(temp3, temp3->sib, &head3);
					tem3->sib = temp3;
				}	
			}
		}	
	}
	return head3;
}
//extracts minimum from the binomial heap
void BH_Extract_Min(node ** head,int t){
	if((*head)==NULL){
		cout<<"Heap Empty"<<endl;
		return;
	}
	node * prev = (*head);
	node * min = (*head);
	node * temp = (*head);
	node * temp1= (*head);
	while(temp!=NULL){
		if(temp->key<min->key){
			min = temp;
			temp1 = temp;
		}
		temp = temp->sib;
	}
	if((*head)!=temp1){
		while(prev->sib!=temp1){
			prev = prev->sib;
		}
		prev->sib = temp1->sib;
	}
	else if((*head)==temp1&&temp1->sib!=NULL){
		(*head) = temp1->sib;
	}
	else if((*head)==temp1&&temp1->sib==NULL){
		(*head) = NULL;
	}
	int m = min->key;
	
	node * flag = temp1->son;
	node * tem = temp1->son;
	//reverses the child list
	if(tem!=NULL){
		while(tem->sib!=NULL){
			tem = tem->sib;
		}
		node * temp2 = tem;
		while(temp2!=flag){
			node * temp3 = flag;
			while(temp3->sib!=temp2){
				temp3 = temp3->sib;
			}
			temp2->sib = temp3;
			temp2 = temp2->sib;
		}
		temp1 = NULL;
		free(temp1);
		temp2->sib = NULL;
	}
	//takes union
	*head = Union(tem, (*head));
	if(t==1)
		cout<<"Minimum extracted: "<<m<<endl;
	return;
}
//inserts in binomial heap
node * BinomialInsert(node * head, int k){
	node * temp = getNode(k);
	head = Union(temp, head);
	return head;
}
//free's all the nodes and makes head NULL
node * makeheap(node * head){
	node * temp = head;
	if(temp==NULL){
		return temp;
	}
	if(temp->sib!=NULL){
		temp = makeheap(temp->sib);
	}
	if(temp->son!=NULL){
		temp = makeheap(temp->son);
	}
		temp = NULL;
		free(temp);
		return head;
}


int main(){
	node * head = NULL;
	int flag=1;
	cout<<"Input( quit to exit) :"<<endl;
	//command line interface
	string s;
	while(cin>>s){
		if(s=="quit")break;
		if(s=="c"){
			head = makeheap(head);
			head = NULL;
			cout<<"Created Empty Heap"<<endl;
			continue;
		}
		if(s=="i"){
			int d;
			cin>>d;
			head = BinomialInsert(head, d);
			continue;
		}
		if(s=="S"){
			show(head);
			continue;
		}
		if(s=="-"){
			flag=0;
			continue;
		}
		if(s=="+"){
			flag=1;
			continue;
		}
		if(s=="d"){
			BH_Extract_Min(&head, flag);
			continue;
		}
		if(s=="#"){
			cin.ignore(2e9,'\n');
		}
	}
	return 0;
}
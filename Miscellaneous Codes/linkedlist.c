#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int data;
	struct _node *next;

}node ;
node * getnode(){
	node *ptr = (node*)malloc(sizeof(node));
	ptr->next = NULL;
	return ptr;
}
void insnap(node *p, node *head, int d){
	if(p!=NULL){

	node* q = getnode();
	q->data = d;
	q->next = p->next;
	p->next = q;
}
else printf("Error");
	

}
node* insnah(node *head, int d){
	node* q = getnode();
	q->data=d;
	if(head!=NULL){
		q->next = head;
		head = q;
		return head;
	}
	else {head = q;return head;}
}

void delap(node *p, node *head){
	if(p!=NULL && (p->next)!=NULL){
	node *temp = p->next;
	p->next = temp->next;
	free(temp);}
	else printf("Error");
}
node* prev(node *p, node *head){
	node *temp = head;
	while((temp->next)!=p){
		temp = temp->next;
	}
	return temp;
}
node* delp(node *p, node *head){
	if(p!=NULL){
		if(p==head){
			head = p->next;
			free(p);
			return head;
		}
		else{
			node *temp;
			temp = prev(p,head);
			temp->next = p->next;
			free(p);
			return head;
		}


	}
}
void printl(node *head){
	node *temp = head;
	while(temp!= NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}
}

int main(){
	node *head;
	node *node1 = getnode();
	node1->data = 1;
	head = node1;
	insnap(node1, head, 2);
	head = insnah(head, 0);
	printl(head);
	printf("\n");
	delap(node1, head);
	delp(node1, head);
	printl(head);
	return 0;
}

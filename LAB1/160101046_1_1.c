#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}node;

node * getnode(){
	node * temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	return temp;
}

void insnah(node **head, int d){
	node* q = getnode();
	q->data=d;
	if(*head!=NULL){
		q->next = *head;
		*head = q;
		return;
	}
	else {*head = q;return;}
}
void insal(node **head, int d){
	node *temp = getnode();
	node *temp1 = *head;
	while((temp1->next)!=NULL){
		temp1 = temp1->next;
	}
	temp->data = d;
	temp1->next = temp;



}
node * find(node **head, int d){

	node * temp = (*head);
	while((temp->data)!=d){
		temp = temp->next;
	}
	return temp;
}

void ins(node ** head, int d, int i, int k){
	if(k==0){
		if((*head)!=NULL){
		insal(head, d);
		return;
		}
		else{
		insnah(head, d);
		return;
		}
	}
	if(i==0){
		insnah(head, d);
		return ;
	}


	node * temp = getnode();
	node * temp1 = find(head, i);
	node * temp2 = find(head, k);
	temp->data = d;
	(temp1->next) = temp;
	temp->next = temp2;
	return;




}


int main(){
	int i=0,m=0;
	int j=0,k=0, l;
	printf("Enter the input :\n");
	node * head = NULL;
	while(1){
		scanf("%d", &i);
		
		if(i==-1)break;
		m++;
		scanf("%d %d", &j, &k);
		ins(&head, j, i ,k);
	}
	
	printf("Enter the number you want to find : ");
	scanf("%d", &l);
	node * temp = head;

	do{
		if(temp==NULL){printf("NOT FOUND\n");return 0;}
		if((temp->data)==l){printf("FOUND\n");return 0;}
		temp = temp->next;
		m--;
	}while(m!=-1);
	printf("NOT FOUND\n");
	
	return 0;
}
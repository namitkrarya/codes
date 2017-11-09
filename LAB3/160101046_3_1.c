#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//creates new 'type'
typedef struct _node{
	int data;
	struct _node * next;
}node;

//function returns new node
node * getnode(){
	node * temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	return temp;
}

//function checks if 'n' is a power of 2
bool check_powerof_2(int n){
  if(n == 0)return 0;
  while (n != 1)
  {
    if (n%2 != 0)return 0;
    n = n/2;
  }
  return 1;
}

//function inserts new node at the end of linked list
void ins_last(node ** head, int d){
	node * temp = *head;
	node * p = getnode();
	if((*head)==NULL){
		*head = p;
		p->data = d;
	}
	else{
		while(temp->next==NULL){
			temp = temp->next;
		}
		temp->next = p;
		p->data = d;
	}
}

//function inserts new node in the starting of the linked list
void ins_head(node ** head, int d){
	node * p = getnode();
	p->next = (*head);
	p->data = d;
	*head = p;
}

//function prints the linked list
void print(node * head){
	node * temp = head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

//function creates the winner tree using array and returns the index for the head of winning element
int winnerTree(node * p[], int n, int *m){
	int l;
	if(n==1)return 0;

	for(int i=n-1;i<(2*n-1);i=i+2){
		if(p[i+1]==NULL&&p[i]==NULL){
			p[(i-1)/2]=NULL;
			m[(i-1)/2]=m[i];
		}
		else if(p[i+1]==NULL&&p[i]!=NULL){
			p[(i-1)/2]=p[i];
			m[(i-1)/2] = m[i];
		}
		else if(p[i]==NULL&&p[i+1]!=NULL){
			p[(i-1)/2]=p[i+1];
			m[(i-1)/2] = m[i+1];
		}	
		else{
			if((p[i]->data)>(p[i+1]->data)){
				p[(i-1)/2]=p[i];
				m[(i-1)/2]=m[i];
			}
			else {
				p[(i-1)/2]=p[i+1];
				m[(i-1)/2] = m[i+1];
			}
		}
	}
	l = winnerTree(p, n/2, m);
	return m[0];
}

//main function
int main(){
	int n;
	printf("Enter input : \n");
	//input of no. of ordered sequence
	scanf("%d", &n);
	if(n==0){
		printf("No Input\n");
		return 0;
	}
	int v = n;
	while(!check_powerof_2(n)){
		n++;
	}
	node * arr[n+1];
	for(int i=0;i<n+1;i++){
		arr[i] = NULL;
	}
	int counter=0;
	//Do not enter a space after each ordered sequence otherwise the input will not get stored properly
	for(int i=0;i<v;i++){
		int a;
		char c = 'a';
		arr[i] = NULL;
		while(1){
			//please enter only ordered sequences
			scanf("%d%c", &a, &c);			
			ins_head(&arr[i], a);
			counter++;
			if(c=='\n')break;
		}
	}
	//changes n to the greater nearest power of 2
	node * head=NULL;
	node * p[(2*n)-1];
	int m[(2*n)-1];
	//initiates all the tree array elements with NULL
	for(int i=0;i<(2*n-1);i++){
			p[i] = NULL;
			m[i]=0; 
		}
	int j=0;
	int k=0;
	int u;
	//sets leaf node equal to the nodes among whick the matches have to be done
	for(int i=0;i<counter;i++){
		for(int k=n-1;k<(2*n-1);k++){
			p[k] = arr[j];
			m[k] = j;
			j++;
		}
		u = winnerTree(p,n,m);
		//inserts new node with data equal to the winner in the final linked list
		ins_head(&head, arr[u]->data);
		//moves head ahead
		arr[u] = arr[u]->next;
		j=0;
		}
	printf("Merged ordered sequence : \n");
	//prints final ordered sequence
	print(head);
	printf("\n");
	return 0;
}
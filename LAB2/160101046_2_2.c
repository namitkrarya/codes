#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
	char data;
	int f;
	struct _node * next;
	struct _node * left;
	struct _node * right;	
}node;

node * getnode(){
	node *ptr = (node*)malloc(sizeof(node));
	ptr->next = NULL;
	ptr->f=0;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
node * before(node ** head, node * p, node * n){
	node * temp = getnode();
	if(p==*head){
		temp->next = *head;
		*head = temp;
		temp->f = n->f;
		temp->data = n->data;
		temp->left = n->left;
		temp->right = n->right;
		return temp;
	}
	else{
		node * temp1 = *head;
		while(temp1->next!=p){
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
		temp->f = n->f;
		temp->left = n->left;
		temp->right = n->right;
		temp->data = n->data;
		return temp;
	}
}

node * after1(node * head, node *p){
	node * temp = getnode();
	temp->next = p->next;
	p->next = temp;
	return temp;
}

node * after(node ** head, node * p, node * n){
	node * temp = getnode();
	temp->next = p->next;
	p->next = temp;
	temp->f = n->f;
	temp->left = n->left;
	temp->right = n->right;
	temp->data = n->data;
	return temp;
}

node * check(node * head, char a){
	node * temp = head;
	while(temp->next!=NULL){
		if(a==temp->data)return temp;
		temp = temp->next;
	}
	if(a==temp->data)return temp;
	return NULL;
}

void createList(node ** head, char a){
	node * temp1 = (*head);
		if(*head!=NULL){
			if(check(*head, a)!=NULL){
				(check(*head, a)->f)++;return;
			}
		}
		node * temp = getnode();
		temp->data=a;
		(temp->f)++;
		if(*head!=NULL){temp->next = *head;}
		(*head) = temp;
		return;	
}
void sort(node * head, node ** head1){
	node * temp = head;
	node * temp1 = getnode();
	(*head1) = temp1;
	temp1->f = temp->f;
	temp1->left = temp->left;
	temp1->right = temp->right;
	temp1->data = temp->data;
	temp = temp->next;
	node * ptr = (*head1);
	while(temp!=NULL){
		while(1){
			if(temp->f<ptr->f){
				before(head1, ptr, temp);
				break;
			}
			if(temp->f==ptr->f){
				if(temp->data>ptr->data){
					if(ptr->next==NULL){
						after(head1, ptr, temp);
						break;
					}
					ptr = ptr->next;
				}
				else{
					before(head1, ptr, temp);
					break;
				}
			}
			if(temp->f>ptr->f){
				if(ptr->next==NULL){
					after(head1, ptr, temp);
					break;
				}
				else{
					ptr = ptr->next;
				}
			}
		}
		temp = temp->next;
		ptr = (*head1);
	}
}
void printl(node *head){
	node *temp = head;
	while(temp!= NULL){
		printf("%c %d ", (temp->data), temp->f);
		temp = temp->next;
	}
}
void buildTree(node ** head1){
	while(1){
		if((*head1)->next==NULL)break;
		node * root=NULL;
		node * temp = getnode();
		temp->data = (*head1)->data;
		temp->f = (*head1)->f + ((*head1)->next)->f;
		temp->left = (*head1);
		temp->right = (*head1)->next;
		temp->next = (*head1);
		(*head1) = temp;
		sort(*head1, &root);
		(*head1) = root;
		(*head1)=(*head1)->next->next;
	}
}

void code(node * root, char b[]){
	char p[50];
	char q[50];
	node * temp = root;
	strcpy(p,b);
	strcat(p,"0");
	strcpy(q,b);
	strcat(q,"1");
	if(root->left==NULL&&root->right==NULL)printf("%c=%s ",root->data, b);
	else{
		code(temp->left, p);
		code(temp->right, q);
	}
}

int main(){
		node * head = NULL;
		node * head1 = NULL;
		char a[100];
		scanf("%s", a);
		int i=0;
		for(i=0;i<strlen(a);i++){
		if(a[i]=='\n')break;
		createList(&head, a[i]);
		sort(head, &head1);
		}
		if(head1->next==NULL){
			printf("No need of encoding\n");
			return 0;
		}
		buildTree(&head1);
		char b[100];
		code(head1, b);
		printf("\n");
		return 0;
}
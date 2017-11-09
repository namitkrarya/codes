#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	char data[20];
	struct _node * next;
	struct _node * file;
}node;

node * getnode(){
	node * temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->file = NULL;
	return temp;
}

void newFolder(node ** head,node **present, char a[]){
	node * temp = (*head);
	node * temp1 = getnode();
	strcpy((temp1->data),a);
	if((*head)!=NULL){
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next=temp1;
		(*present) = temp1;
		return;
	}
	else{
		(*head) = temp1;
		(*present) = temp1;
		return;
	}
}

void newFile(node ** head, char f[]){
	node * temp = (*head);
	node * temp1 = getnode();
	strcpy(temp1->data, f);
	if((*head)!=NULL){
		while(temp->file!=NULL){
			temp = temp->file;
		}
		temp->file=temp1;
		return;
	}
	else{
		(*head) = temp1;
		return;
	}
}


void createFile(node ** present,  char f[]){
	node * temp = getnode();
	newFile(present, f);
	return;
	}

void delete(node ** present){
	node * temp = ((*present)->file)->file;
	free((*present)->file);
	(*present)->file = temp;
	return;
}

void back(node ** present, node * head){
	node * temp = head;
	node * temp1 = (*present);
	if(temp!=NULL){
		while((temp->next)!=temp1){
			temp = temp->next;
		}
		(*present) = temp;
		(*present)->next = NULL;
	}
	return;
}

node * prev(node * present, node * head){
	node * temp = head;
	if(head!=NULL){
		while(temp->next!=present){
			temp = temp->next;
		}
		return temp;
	}
	return NULL;
}

int main(){
	char a[20];
	char b[20];
	char d[20];
	int i;
	node * head = getnode();
	node * present = head;
	char c[20] = "root";
	strcpy((present->data), c);
	while(1){
		scanf("%s", a);
		if(strcmp(a,"-1")==0)break;
		if((strcmp(a,"CREATE")==0)||(strcmp(a,"NEW")==0))
			scanf("%s", b);
		if(strcmp(a,"CREATE")==0){
			createFile(&present, b);
			printf("Created %s in %s\n", b, (present->data));
		} 
		else if(strcmp(a,"NEW")==0){
			printf("Made %s in %s\n", b, (present->data));
			newFolder(&head, &present, b);	
		}
		else if(strcmp(a,"BACK")==0){
			node * temp = present;
			if(head==present){
				printf("Cannot back from root\n");
				continue;
			}
			printf("Back from %s\n", (temp->data));
			back(&present, head);
		}
		else if(strcmp(a,"DELETE")==0){
			node * temp = present;
			temp = temp->file;
			if(present->file==NULL){
				printf("Cannot delete from %s\n", present->data);
				continue;
			}
			printf("Deleted %s from %s\n", temp->data,present->data);
			delete(&present);
		}
		else{printf("Wrong Input\n");}
	}
	return 0;
}
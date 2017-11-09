#include <bits/stdc++.h>
using namespace std;
struct node{
	node * right;
	node * down;
	int row;
	int col;
	int value;
};

struct head{
	node * down;
	node * right;
};

node * getnode(){
	node * temp = new node;
	temp->down = NULL;
	temp->right = NULL;
	temp->row = -1;
	temp->value = -1;
	temp->col = -1;
	return temp;
}

head * gethead(){
	head * temp = new head;
	temp->right = NULL;
	temp->down = NULL;
}

void ins(int row, int col, int value, head * arr[]){
	node * temp = getnode();
	temp->value = value;
	temp->row = row;
	temp->col = col;

	if(arr[row]->right==NULL){
		arr[row]->right = temp;	
	}
	else{
		node * temp1 = arr[row]->right;
		if(temp1->col>col){
			temp->right = arr[row]->right;
			arr[row]->right = temp;
		}
		else{
			while(1){
				if(temp1->right==NULL){
					temp1->right = temp;
					temp->right = NULL;
					break;
				}
				else{
					if(temp1->right->col>col){
						temp->right = temp1->right;
						temp1->right = temp;
						break;
					}
					else{
						temp1 = temp1->right;
					}				
				}	
			}	
		}
	}

	if(arr[col]->down==NULL){
		arr[col]->down = temp;	
	}
	else{
		node * temp1 = arr[col]->down;
		if(temp1->row>row){
			temp->down = arr[col]->down;
			arr[col]->down = temp;
		}
		else{
			while(1){
				if(temp1->down==NULL){
					temp1->down = temp;
					temp->down = NULL;
					break;
				}
				else{
					if(temp1->down->row>row){
						temp->down = temp1->down;
						temp1->down = temp;
						break;
					}
					else{
						temp1 = temp1->down;
					}				
				}	
			}	
		}
	}
}

void print(node * head){
	node * temp = head;
	while(temp!=NULL){
		printf("%d ", temp->value);
		temp = temp->right;
	}
}

int main(){

	
	int row;
	int col;
	cin>>row>>col;
	head * arr[col];
	int elements;
	cin>>elements;
	for(int i=0;i<row;i++){
		arr[i] = gethead();
	}
	int counter=0;
	srand(time(NULL));
	while(1){
		if(counter==elements)break;
		int r = rand();
		r = r%(row);
		int c = rand();
		c = c%(col);
		int e;
		e = rand();
		e = e%20;
		ins(r,c,e,arr);
		counter++;
	}
	printf("______________________\n");
	for(int i=0;i<row;i++){
		print(arr[i]->right);
		printf("\n");
	}

	return 0;
}
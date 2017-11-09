#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
        char data[50];
        int info;
        struct _node * right;
        struct _node * down;
        struct _node * prev;
}node;

typedef struct sparse_arr{
    char row[50];
    char col[50];
    int dist;
 }arr;

node * getnode(){
	node *ptr = (node*)malloc(sizeof(node));
	ptr->right = NULL;
	ptr->down = NULL;
    ptr->prev = NULL;
	return ptr;
}

arr * createnode(){
    arr * ptr = (arr*)malloc(sizeof(arr));
    return ptr;
}

int find_max(node * head[], char city1[], char city2[],int r,arr * spar[], int n){
    int max=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<n;j++){
            if(!strcmp(head[j]->data, spar[i]->row)||!strcmp(head[j]->data, spar[i]->col)){
                if(!strcmp(head[j+1]->data, spar[i]->col)||!strcmp(head[j+1]->data, spar[i]->row)){
                    if((spar[i]->dist)*((head[j]->down)->info)<=max)break;
                    max = (spar[i]->dist)*((head[j]->down)->info);
                    strcpy(city1, spar[i]->row);
                    strcpy(city2, spar[i]->col);
                    break;  
                }
            }
        }
    }
    return max;
}

int find(node * head[], char c[], int n){
    for(int i=0;i<n;i++){
        if(!strcmp(head[i]->data,c))return i+1;
    }
    return 0;
}

int main(){
    int n,r,f;
    scanf("%d %d %d", &n, &r, &f);
    node * head[n];
    arr *spar[r];
    for (int i = 0; i < n; i++)
    {
        head[i] = getnode();
    }  
    for (int i = 0; i < r; i++)
    {
        spar[i] = createnode();
    }   
    for(int i=0;i<r;i++){
        char p[50], q[50];
        int d;
        scanf("%s %s %d", p, q, &d);
        strcpy(spar[i]->row,p);
        strcpy(spar[i]->col,q);
        spar[i]->dist = d;
    }
    int i=0;
    int j=0;
    while(f>j){
        char p[50], q[50];
        int d;
        scanf("%s %s %d", p, q, &d);
        node * temp = getnode();
        if(!find(head, p, n)){
            strcpy(head[i]->data,p);
            head[i]->down = temp;
            i++;
        }
        else{
            int l = find(head,p,n);
            if(head[l-1]==NULL){
                head[l-1]->down = temp;
            }
            else{
                node * ptr = head[l-1]->down;
                node * ptr1;
                while(find(head,ptr->prev->data,n)<find(head,q,n)){
                    ptr1 = ptr;
                    ptr = ptr->down;
                }
                temp->down = ptr->down;
                ptr->down = temp;
            }
        }
        if(!find(head, q, n)){
            strcpy(head[i]->data,q);
            head[i]->right = temp;
            temp->prev = head[i];
            i++;
        }
        else{
            int l = find(head,q,n);
            if(head[l-1]==NULL){
                head[l-1]->right = temp;
                temp->prev = head[l-1];
            }
            else{
                node * ptr = head[l-1]->down;
                node * ptr1;
                while(find(head,ptr->prev->data,n)<find(head,p,n)){
                    ptr1 = ptr;
                    ptr = ptr->right;
                }
                temp->right = ptr->right;
                ptr->right = temp;
                
            }
        }
        temp->info = d;
        j++;

    }
    j=0;
    /*int max=0;
    int count=0;
    char city1[50], city2[50];
    max = find_max(head, city1, city2, r,spar, n);
	if(max==0){
		printf("Insufficient Information\n");
		return 0;
	}
    printf("%s %s %d\n", city1, city2, max);
    */
    for (j = 0; j < i; ++j)
    {   
        node * temp = head[j];
        while(temp!=NULL){
            printf("%d", temp->info);
            temp = temp->right;
        }
        printf("\n");
    }
    //printf("%s")
    return 0;
}
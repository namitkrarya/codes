#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct to create sparse matrix using linked list
typedef struct _node{
        char data[50];
        int info;
        struct _node * right;
        struct _node * down;
}node;
//struct to create sparse matrix using array
typedef struct sparse_arr{
    char row[50];
    char col[50];
    int dist;
 }arr;
//creates node
node * getnode(){
    node *ptr = (node*)malloc(sizeof(node));
    strcpy(ptr->data,"\0");
    ptr->right = NULL;
    ptr->down = NULL;
    return ptr;
}
//creates arr
arr * createnode(){
    arr * ptr = (arr*)malloc(sizeof(arr));
    return ptr;
}
//finds the max distance between 2 cities
int find_max(node * head[], char city1[], char city2[],int r,arr * spar[], int n){
    int max=-1;
    for(int i=0;i<r;i++){
        for(int j=0;j<2*n;j=j+2){
            if(head[j]==NULL)continue;
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
//Main function
int main(){
    int n,r,f;
    printf("Input : \n");
    //takes input
    scanf("%d %d %d", &n, &r, &f);
    node * head[2*n];
    arr *spar[r];
    for (int i = 0; i < 2*n; i++)
    {
        head[i] = getnode();
    }  
    for (int i = 0; i < r; i++)
    {
        spar[i] = createnode();
    }   
    //creates sparse matrix using array
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
    //creates sparse matrix using linked list
    while(f>j){
        char p[50], q[50];
        int d;
        scanf("%s %s %d", p, q, &d);
        node * temp=getnode();
        strcpy(head[i]->data,p);
        head[i]->down = temp;
        i++;
        strcpy(head[i]->data,q);
        head[i]->right = temp;
        i++;
        temp->info = d;
        j++;
    }
    j=0;
    int max;
    char city1[50], city2[50];
    max = find_max(head, city1, city2, r,spar, n);
    //if sufficient information is not given
    if(max==-1){
        printf("\nOutput : \n");
        printf("Insufficient Information\n");
        return 0;
    }
    printf("\nOutput : \n");
    //prints final output
    printf("%s %s %d\n", city1, city2, max);
    return 0;
}
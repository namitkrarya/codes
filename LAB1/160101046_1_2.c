#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void enq(int data[], int *rear, int *front, int d){
	
	(*rear)++;
	
	data[(*rear)]=d;
}

int isEmpty(int *rear, int *front){
	if((*front)==(*rear))return 1;
	return 0;
}

int delq(int data[], int *rear, int *front){
	 
	return data[(*front)++]; 
}



void push(int s[], int *top, int d){
	s[(*top)] = d;
	(*top)++;
}

int pop(int s[], int *top){
	if((*top)!=0){
	(*top)--;
	return s[(*top)];
	}
	else return 0;	
}

int main(){
	

	int q, i=0,n , j=0, m=0,k,l;
	
	
	int top=0;
	printf("Enter the number of inputs : ");
	scanf("%d", &n);

	int s[100], p;

	int front1=0;
	int rear1=-1;
	int data1[n];

	int front2=0;
	int rear2=-1;
	int data2[n];

	int front3=0;
	int rear3=-1;
	int data3[n];
	printf("Enter the input :\n");
	for(i=0;i<n;i++){
		scanf("%d", &p);
		enq(data1, &rear1, &front1, p);
		enq(data2, &rear2, &front2, i+1);
	}
	i=0;
	
	
	
	for(j=0; j<n;j++){
		
		if(j!=0){
			if(data1[j]<data1[j-1]){
				q = pop(s, &top);
				if(q!=data1[j]){printf("Not permutation as next expected output was %d\n", q);goto outer;}
				printf("enqueue(Q2, pop(S)) -> %d\n", q);
				enq(data3, &rear3, &front3, q);
				goto here;
			}
		}	
		for(k=0;k<n;k++){
			if(data2[k]==0)m++;
			if(m==n)goto outer;
		}

		while(data2[i]!=data1[j]){
			if(data2[i]!=0){
				printf("push(S, dequeue(Q1))-> %d\n", data2[i]);
				push(s, &top,data2[i]);data2[i]=0;
			}
			i++;
		}
			
		
		data2[i]=0;
		printf("enqueue(Q2, dequeue(Q1)) -> %d\n", data1[j]);
		enq(data3, &rear3, &front3, data1[j]);
		

		here :
		m = 0;
		i = 0;
		}
		
		
	outer :
	
	
	

	return 0;
}
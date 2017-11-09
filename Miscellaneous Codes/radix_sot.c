#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_arr(int n, int a[]){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}

void push(int n, int k, int a[10][n], int m, int f[], int r[]){
	f[k]++;
	a[k][f[k]] = m;
}

int pop(int n, int k, int a[10][n], int f[], int r[]){
	r[k]++;
	return a[k][r[k]-1];
}

void radix(int n,int b[], int a[10][n], int l, int f[], int r[]){
	for(int i=0;i<l;i++){
		for(int j=0;j<n;j++){
			push(n, (b[j]%((int)pow(10,i+1)))/(int)pow(10,i), a, b[j], f, r);
		}
		for(int j=0;j<n;j++){
			int t = 0;
			while(1){
				if((r[t]-f[t])==1){
					if(t==9)break;
					t++;
					continue;}
				else{
					b[j] = pop(n, t, a, f, r);
					break;
				}
			}
		}
	}
}

int main(){
	int n,l=0;

	scanf("%d", &n);
	int a[10][n];
	int b[n];
	int r[10] = {0};
	int f[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++)a[j][i]=0;
		b[i] = 0;
	}
	int max=0, u;
	for(int i=0;i<n;i++){
		scanf("%d", &u);
		b[i] = u;
		if(u>max)max = u;
	}
	while(max!=0){
		max = max/10;
		l++;
	}
	radix(n,b,a,l,f,r);
	print_arr(n, b);
	printf("\n");
	return 0;
}
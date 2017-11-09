#include <stdio.h>
#include <stdlib.h>

void print_arr(int n, int a[]){
	for(int i=1;i<=n;i++){
		printf("%d ", a[i]);
	}
}

void swap(int a[], int c, int b){
	int temp;
	temp = a[c];
	a[c] = a[b];
	a[b] = temp;
}

int findmin(int a[], int l, int r){
	if(a[l]<a[r])return l;
	else return r;
}

void min_heapify(int n, int a[], int i){
	if(i>n/2)return;
	int l = 2*i;
	int r = 2*i+1;
	if(r>n){
		if(a[i]>a[l])swap(a,i,l);
		else return;
		return;
	}
	int k;
	int p = findmin(a,l,r);
	k = i;
	if(a[k]>a[p]){
		swap(a,k,p);
		min_heapify(n, a, p);
	}
	else return;
	return;
}

int extract_min(int *n, int a[]){
	int x = a[1];
	a[1] = a[*n];
	(*n)--;
	min_heapify(*n, a, 1);
	return x;

}

int parent(int i){
	if(i%2==0)return i/2;
	else return (i-1)/2;
}

void decrease(int a[], int i, int x){
	if(x>a[i])return;
	a[i] = x;
	while(i>1 && a[parent(i)]>a[i]){
		swap(a, parent(i), i);
		i = parent(i);
	}
}

void ins(int a[], int *n, int x){
	(*n)++;
	a[*n] = 50000000;
	decrease(a, *n, x);
}



void build_min_heap(int n, int a[]){
	for(int i=n/2;i>0;i--){
		min_heapify(n, a,i);
	}
}

void heap_sort(int n, int a[]){
	build_min_heap(n, a);
	for(int i=n;i>=1;i--){
		swap(a, 1, i);
		min_heapify(i-1,a, 1);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n+1+1];
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	//heap_sort(n, a);
	build_min_heap(n, a);
	ins(a, &n, 0);
	print_arr(n, a);
	return 0;
}
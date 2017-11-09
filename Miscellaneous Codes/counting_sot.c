#include <stdio.h>
#include <stdlib.h>

void counting_sort(int n, int a[], int b[], int k){
	int c[k+1];
	for(int i=0;i<=k;i++){
		c[i] = 0;
	}
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
	for(int i=0;i<=k;i++){
		c[i] = c[i] + c[i-1];
	}
	// for(int i=0;i<=k;i++){
	// 	printf("%d ", c[i]);
	// }
	for(int i=n;i>=1;i--){
		b[(c[a[i]])] = a[i];
		c[a[i]]--;
	}
}

void print_arr(int n, int a[]){
	for(int i=1;i<=n;i++){
		printf("%d ", a[i]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n+1], b[n+1];
	int k=0,u;
	for(int i=1;i<=n;i++){
		scanf("%d", &u);
		a[i] = u;
		if(u>k)k=u;
	}
	counting_sort(n, a, b, k);
	print_arr(n,b);
	return 0;
}
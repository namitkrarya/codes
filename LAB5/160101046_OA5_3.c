#include <stdio.h>
#include <stdlib.h>
//creates struct
typedef struct _arr{
	int *a;
}array;
//alots space to struct
array * getspace(){
	array * temp = (array*)malloc(sizeof(array));
	return temp;
}
//Bubble Sort
void bs(int a[],int n){
	int i,j,t;
	for (i = 0; i < n-1; ++i)
	{
		for(j=0;j<n-1-i;j++){
			if (a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

int main(){
	int n, t;
	printf("Input : \n");
	scanf("%d %d", &n, &t);
	int e;
	int flag=0;
	scanf("%d", &e);
	int count[e+1];
	int c[n+1];
	for(int i=1;i<n+1;i++)
		c[i]=0;
	//array of struct
	array * arr[e+1];
	for(int i=1;i<e+1;i++){
		arr[i] = getspace();
		arr[i]->a = (int*)malloc(e*sizeof(int));
		count[i] = 0;
		for(int j=0;j<e;j++){
			arr[i]->a[j] = 0;
		}
	}
	for(int i=0;i<e;i++){
		int p,q;
		scanf("%d %d", &p, &q);
		(count[p])++;
		arr[p]->a[i] = q;
	}
	for(int i=1;i<e+1;i++){
		int counter=0;
		if(t==i)continue;
		for(int j=0;j<e;j++){
			counter = counter + arr[i]->a[j];
		}
		//no. of seats less than no. of passengers, so its impossible
		if(counter<count[i]){flag=1;break;}
		bs(arr[i]->a, e);
		int sum = arr[i]->a[e-1];
		//counts least no. of cars required
		for(int w=e-1;w>=0;w--){
			if(sum>=count[i]&&sum!=0){c[i]++;break;}
			sum = sum + arr[i]->a[w-1];
		}
	}
	printf("Output :\n");
	if(flag==1){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i=1;i<n+1;i++){
		printf("%d ", c[i]);
	}
	printf("\n");
	return 0;
}
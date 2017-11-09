/*Output of second test input is coming 42 instead of 43.
Which is better as lesser comparisons are done.
Sir said the output might vary dependent on the algorithm, so you can check my code accordingly.
*/
#include <stdio.h>
#include <stdlib.h>
//Binary Search
int binarySearch(int a[], int l, int u, int m, int * count)
{	
   if (u >= l)
   {	
        int half = (l+u)/2;
        //if elements are consecutive
        if(u-l==1){
        	(*count)++;
        	if(m<a[l])return l;
        	(*count)++;
        	if(m>=a[l]&&m<=a[u])return u;
        	else return u+1;
        }
        //if only one element left to check
        if(u-l==0){
        	(*count)++;
        	if(m<a[l])return l;
        	else return l+1;
        }
        (*count)++;
        //compares with mid element
        if (a[half] <= m)  return binarySearch(a, half+1, u, m, count);
        else return binarySearch(a, l, half-1, m, count);
   }
   return -1;
}
//prints array
void printarr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}
//main function
int main(){
	int n,u,k;
	printf("Input : \n");
	scanf("%d", &n);
	int a[n];
	int count=0;
	for(int i=0;i<n;i++){
		scanf("%d", &u);
		//get index where we need to insert new element
		int p = binarySearch(a, 0, i-1, u, &count);
		if(p==-1){
			a[0] = u;
			continue;
		}
		for(int k=i;k>p;k--){
		a[k] = a[k-1];
		}
		a[p] = u;
	}
	printf("Output :\n");
	printf("%d\n", count);
	printarr(a, n);
	printf("\n");
	return 0;
}
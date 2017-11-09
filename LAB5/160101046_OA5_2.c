#include <stdio.h>
//Merge function
void merge(int a[],int l,int q,int u, int * counter)
{	
	int i;
	int rsize = u-q;
	int lsize = q-l+1;
	int Right[rsize],Left[lsize];
	//copies elements from main array into 2 temporary arrays
	for (i = 0; i < rsize; ++i)
	{
		Right[i] = a[q+1+i];
	}
	for (i = 0; i < lsize; ++i)
	{
		Left[i] = a[l+i];
	}
	int j=0,c=l;
	i=0;
	//pushes elements in sorted order from temp. arrays by comparing each element
	while (i<lsize && j<rsize)
	{
		if (Left[i] <= Right[j]){
			a[c] = Left[i];
			i++;
		}
		else{	
			//counter increases whenever right element(greater than left) is pushed
			for(int p=0;p<lsize-i;p++){
				(*counter)++;
			}
			a[c] = Right[j];
			j++;
		}
		c++;
	}
	//the non empty array is pushed completely
	while(i<lsize){	
		a[c] = Left[i];
		i++;
		c++;
	}
	while (j<rsize){	
		a[c] = Right[j];
		j++;
		c++;
		for(int p=0;p<lsize-i;p++){
			(*counter)++;
		}
	}
}
//Merge Sort
void mergesort(int a[],int l,int u, int *count)					//merge sort
{
	if(l<u)
	{
		int q = (l+u)/2;
		mergesort(a,l,q, count);
		mergesort(a,q+1,u,count);
		merge(a,l,q,u, count);
	}
}

int main(){
	int n;
	printf("Input : \n");
	scanf("%d", &n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	int counter=0;
	//sorts the array and increases counter accordingly
	mergesort(a, 0, n-1, &counter);
	printf("Output : ");
	printf("%d\n", counter);
	return 0;
}
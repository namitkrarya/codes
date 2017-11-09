#include <stdio.h>
#include <stdlib.h>

void bs(int a[],int n){                         //bubble sort
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

void selsort(int a[],int n)						//selection sort
{
	int i,j;
	for (i = n-1; i > 0; --i)
	{
		int large = a[0],index = 0;
		for (j = 1; j <= i; ++j)
		{
			if (a[j] > large)
			{
				large = a[j]; index = j;
			}
		}
		int t = a[i];
		a[i] = a[index];
		a[index] = t;
	}
}

struct node
{
	int data;
	struct node *left,*right;
};
struct node *newnode(int d)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insert(struct node *h,int key)					//binary tree sort
{
	if (h == NULL) return newnode(key);
	if (key < h->data)
		h->left = insert(h->left,key);
	else if (key > h->data)
		h->right = insert(h->right,key);
	return h;
}

void inorder(struct node *h)
{
	if (h == NULL) return;
	inorder(h->left);
	printf("%d ",h->data);
	inorder(h->right);
}

void insertith(int a[],int i)
{
	int y = a[i],j;
	for(j = i-1;j>=0 && y <a[j];j--)
	{
		a[j+1] = a[j];
	}
	a[j+1] = y;
}
void insertionsort(int a[],int n)						//insertion sort
{
	for (int i = 1; i < n; ++i)
	{
		insertith(a,i);
	}
}

int shellsort(int arr[], int n)							//shell sort
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return 0;
}

void merge(int a[],int l,int p,int u, int * counter)
{	
	int i;
	int n1 = p-l+1;
	int n2 = u-p;
	int L[n1],R[n2];
	for (i = 0; i < n1; ++i)
	{
		L[i] = a[l+i];
	}
	for (i = 0; i < n2; ++i)
	{
		R[i] = a[p+1+i];
	}
	i=0;
	int j = 0,k=l;
	while (i<n1 && j<n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
			for(int p=0;p<n2-i;p++){
			*counter++;
			}
		}
		k++;
	}
	while(i<n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j<n2)
	{
		a[k] = R[j];
		j++;
		k++;
		for(int p=0;p<n2-i;p++){
		*counter++;
		}
	}
	
}

void mergesort(int a[],int l,int u, int *count)					//merge sort
{
	if(l<u)
	{
		int p = (l+u)/2;
		mergesort(a,l,p, count);
		mergesort(a,p+1,u, count);
		merge(a,l,p,u, count);
	}
}

int partition(int a[],int l,int u)
{
	int pivot = a[l],t;
	int down = l,up = u;
	while(down<up)
	{
		while(a[down]<=pivot && down<up)
			down++;
		while(a[up]>=pivot && down<=up)
			up--;
		if(down<up)
		{
			t= a[down];
			a[down] = a[up];
			a[up] = t;
		}
	}
	t = a[up];
	a[up] = a[l];
	a[l] = t;
	return up;
}

void quicksort(int a[],int l,int u)						//quick sort
{
	int j;
	if(l<u)
	{
		j = partition(a,l,u);
		quicksort(a,l,j-1);
		quicksort(a,j+1,u);
	}
}

void maxheapify(int a[],int i,int n)
{
	if (i>n/2) return;
	int l = 2*i;
	int r = 2*i + 1;
	int k;
	if (a[i] > a[l] && a[i] > a[r])
		k = i;
	else if (a[i] < a[l] && a[l] > a[r])
		k = l;
	else k =r;
	if (k != i)
	{
		int t = a[k];
		a[k] = a[i];
		a[i] = t;
		maxheapify(a,k,n);
	}
}

void buildheap (int a[],int n)
{
	for (int i = n/2; i >= 1; --i)
	{
		maxheapify(a,i,n);
	}
}

void heapsort(int a[],int n)					//heap sort
{
	int b[n];
	buildheap(a,n);
	for (int i = n; i >= 2; --i)
	{
		int t = a[1];
		a[1] = a[i];
		a[i] = t;
		b[i] = t;
		a[i] = '\0';
		maxheapify(a,1,n);
	}
	b[1] = a[1];
	for (int i = 1; i <= 10; ++i)
	{
		printf("%d ",b[i]);
	}
}

void printarr(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[15] = {109 ,28 ,30 ,34 ,56 ,78 ,112 ,46 ,21 ,10 ,84 ,66 ,98 ,14 ,59};
	struct node *root = newnode(arr[0]);
	int count=0;
	// selsort(arr, 11);
	// printarr(arr, 11);

	// for(int i=1;i<11;i++){
	// 	insert(root, arr[i]);
	// }
	// inorder(root);

	// insertionsort(arr, 11);
	// printarr(arr, 11);

	// mergesort(arr,0,14, &count);
	// printf("%d", count);

	quicksort(arr, 0, 10);
	printarr(arr, 11);


	return 0;
}

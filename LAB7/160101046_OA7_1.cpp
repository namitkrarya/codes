#include <bits/stdc++.h>
using namespace std;
//min heapify for creating heap
void min_heap(int H[], int i, int n){
	int l = 3*i+1;
	int m = 3*i+2;
	int r = 3*i+3;
	int k = i;
	//finds minimum of the 3 children
	if(l<n && H[k]>H[l]){
		k = l;
	}
	if(m<n && H[k]>H[m]){
		k = m;
	}
	if(r<n && H[k]>H[r]){
		k = r;
	}
	if(k!=i){
		//swap(H[i],H[k]);
		int temp;
		temp = H[i];
		H[i] = H[k];
		H[k] = temp;
		min_heap(H,k,n);
	}
	return;
}
//min heapify oof index for finding k smallest elements
void min_heap_index(int a[], int H[], int i, int n){
	int l = 3*i+1;
	int m = 3*i+2;
	int r = 3*i+3;
	int k = i;
	//finds minimum of the 3 children
	if(l<n){
		if(H[a[k]]>H[a[l]]){
			k = l;
		}
	}
	if(m<n){
		if(H[a[k]]>H[a[m]]){
			k = m;
		}
	}
	if(r<n){
		if(H[a[k]]>H[a[r]]){
			k = r;
		}
	}
	if(k!=i){
		//swap(a[i],a[k]);
		int temp;
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
		min_heap_index(a,H,k,n);
	}
	return;
}
//build heap
void buildheap(int H[], int n){
	for(int i=n/3;i>=0;i--){
		min_heap(H,i,n);
	}
	return;
}
//decrease key for heap of index
void min_heap_dec(int a[], int H[], int i, int x){
	if(x>a[i])
		return;
	a[i] = x;
	while(i>0 && H[a[(i-1)/3]]>H[a[i]]){
		//swap(H[(i-1)/3],H[i]);
		int temp;
		temp = a[i];
		a[i] = a[(i-1)/3];
		a[(i-1)/3] = temp;
		i = (i-1)/3;
	}
	return;
}
//delete min for heap of index
int deletemin(int a[], int H[], int *n){
	int x = a[0];
	a[0] = a[(*n)-1];
	(*n)--;
	min_heap_index(a,H,0,*n);
	return x;
}
//insert for heap of index
void insert(int a[], int H[], int *n, int x){
	(*n)++;
	a[(*n)-1] = INT_MAX;
	min_heap_dec(a,H,(*n)-1,x);
}
//finding k smallest elements from heap
void ksmallest(int H[], int n, int k){
	//creating heap which stores indexes of smalllest elements
	int a[2*k];
	int size = 0;
	a[0] = 0;
	int b[k];
	b[0] = H[a[0]];
	int p=0;
	int i=1;
	//inserts children of the current smallest element and deletes smallest among them
	while(i<k){								//loop runs k times
		if(3*p+1<n)	
			insert(a,H,&size,3*p+1);		//complexity = o(log(k))
		if(3*p+2<n)
			insert(a,H,&size,3*p+2);
		if(3*p+3<n)
			insert(a,H,&size,3*p+3);
		//min_heap_index(a,H,0, size);
		p = deletemin(a,H, &size);
		b[i] = H[p];
		i++;
	}
	//overall complexity = o(klog(k))
	for(int i=0;i<k;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl<<endl;
	return;
}
//prints heap
void printarr(int H[], int n){
    for(int i=0;i<n;i++){
        cout<<H[i];
        if(i!=n-1)
            cout<<" ";
    }
    cout<<endl<<endl;
}
//recursive function to print elements less than or equal to a
void asmall(int H[], int n, int a, int i){
	int l = 3*i+1;
	int m = 3*i+2;
	int r = 3*i+3;
	//recursive call only when element is less than or equal to a, complexity = o(t)
	if(l<n && H[l]<=a){
		cout<<H[l]<<" ";
		asmall(H,n,a,l);
	}
	if(m<n && H[m]<=a){
		cout<<H[m]<<" ";
		asmall(H,n,a,m);
	}
	if(r<n && H[r]<=a){
		cout<<H[r]<<" ";
		asmall(H,n,a,r);
	}
	return;
}
//function checks H[0] and give recursive call
void printsmall(int H[], int n, int a){
	if(H[0]<=a){
		cout<<H[0]<<" ";
		asmall(H,n,a,0);
	}
	return;
}
//MAIN function
int main(){
	int n;
	cout<<"Input :"<<endl;
	cin>>n;
	int H[n];
	for(int i=0;i<n;i++){
		cin>>H[i];
	}
	int k;
	cin>>k;
	int a;
	cin>>a;
	buildheap(H,n);
	cout<<endl;
	cout<<"Current Heap : ";
    printarr(H,n);
    cout<<k<<" smallest elements are : ";
	ksmallest(H,n,k);
	cout<<"Current Heap : ";
	printarr(H,n);
	cout<<"Elements <= "<<a<<" : ";
	printsmall(H,n,a);
	cout<<endl<<endl;
	cout<<"Current Heap : ";
	printarr(H,n);
	return 0;
}

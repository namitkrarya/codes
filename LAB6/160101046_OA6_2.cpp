#include <bits/stdc++.h>
using namespace std;
//struct stores arrived time, cook time, and flag
struct node{				
	long int a;
	long int b;
	long int c;
};

//swap function
void swap(node inp[], int x, int y){
	long int temp;
	temp = inp[x].b;
	inp[x].b = inp[y].b;
	inp[y].b = temp;

	temp = inp[x].a;
	inp[x].a = inp[y].a;
	inp[y].a = temp;

	temp = inp[x].c;
	inp[x].c = inp[y].c;
	inp[y].c = temp;
}

//finds min in inp[l].b and inp[r].b
int findmin(node inp[], int l, int r){
	if(inp[l].b<inp[r].b)return l;
	else return r;
}


//min heapify on inp[].b array
void min_heapify(int n, node inp[], int i){
	if(i>n/2)return;
	int l = 2*i;
	int r = 2*i+1;
	if(r>n){
		if(inp[i].b>inp[l].b)swap(inp,i,l);
		else return;
		return;
	}
	int k;
	int p = findmin(inp,l,r);
	k = i;
	if(inp[k].b>inp[p].b){
		swap(inp,k,p);
		min_heapify(n, inp, p);
	}
	else return;
	return;
}

//binary heap extract min
long int extract_min(int *n, node inp[]){
	long int x = inp[1].b;
	inp[1].b = inp[*n].b;
	inp[1].a = inp[*n].a;
	(*n)--;
	min_heapify(*n, inp, 1);
	return x;
}

//decrease key
void decrease(node inp[], int i, long int x, long int y){
	if(x>inp[i].b)return;
	inp[i].b = x;
	inp[i].a = y;
	while(i>1 && inp[i/2].b>inp[i].b){
		swap(inp, i/2, i);
		i =i/2;
	}
}

//insert key
void ins(node inp[], int *n, long int x, long int y){
	(*n)++;
	inp[*n].b = LONG_MAX;
	inp[*n].a = y;
	decrease(inp, *n, x, y);
}

//quick sort partition
int partition(node inp[],int l,int u)
{
	long int pivot = inp[l].a,t;
	int down = l,up = u;
	while(down<up)
	{
		while(inp[down].a<=pivot && down<up)
			down++;
		while(inp[up].a>=pivot && down<=up)
			up--;
		if(down<up)
		{
			t= inp[down].a;
			inp[down].a = inp[up].a;
			inp[up].a = t;

			t= inp[down].b;
			inp[down].b = inp[up].b;
			inp[up].b = t;

			t= inp[down].c;
			inp[down].c = inp[up].c;
			inp[up].c = t;
		}
	}
	t = inp[up].a;
	inp[up].a = inp[l].a;
	inp[l].a = t;

	t = inp[up].b;
	inp[up].b = inp[l].b;
	inp[l].b = t;

	t = inp[up].c;
	inp[up].c = inp[l].c;
	inp[l].c = t;
	return up;
}

//quicksort
void quicksort(node inp[],int l,int u)	
{
	int j;
	if(l<u)
	{
		j = partition(inp,l,u);
		quicksort(inp,l,j-1);
		quicksort(inp,j+1,u);
	}
}

//MAIN function
int main(){
	cout<<"Input :"<<endl;
	int n;
	cin>>n;
	node inp[n+1];
	node out[n+1];
	int k = 0;
	for(int i=1;i<=n;i++){
		cin>>inp[i].a;
		cin>>inp[i].b;
		inp[i].c = 0;
	}
	cout<<endl;
	long int a[n+1];
	long int time=0;
	int flag =0;
	int flag1=0;
	int counter=0;
	int counter1=0;
	quicksort(inp,1,n);
	int j=1;
	for(int i=1;i<=n;i++){
		flag = 0;
		//inserts in heap if arrived time is less than or equal to current time
		while(j<=n&&inp[j].a<=time){							
			if(inp[j].c!=-1){
				//cout<<inp[j].a<<" "<<inp[j].b<<endl;
				ins(out, &k, inp[j].b, inp[j].a);

				inp[j].c=-1;
				flag=1;
				counter++;
				counter1++;	
			}
			j++;
		}
		long int min=LONG_MAX;
		if(flag!=1&&counter1!=n&&k==0){
			time = inp[j].a;
			ins(out, &k, inp[j].b, inp[j].a);
			inp[j].c = -1;
			counter++;
			counter1++;
			j++;
		}
		if(counter==0)break;
		//increase time according to the customer 
		cout<<out[1].a<<" "<<out[1].b<<endl;
		time = time + out[1].b;
		long int u = out[1].a;
		long int p = extract_min(&k, out);
		counter--;
		a[i] = time - u;
	}
	long int average=0;
	for(int i=1;i<=n;i++){
		average = average + a[i];
	}
	average = average/n;
	cout<<average<<endl;
	return 0;
}
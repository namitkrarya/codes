#include<bits/stdc++.h>
using namespace std;

//creating struct
struct node{
	int d;
	int color;
	int inx;

	node * next;
};

//alloting space and initializing
node * getNode(int i){

	node * temp = new node;

	temp->color = 0;
	temp->inx = i;
	temp->d = -1;

	return temp;
}

//insert in adjacent list
void ins_last(node * head[], int i, int n){

	node * temp = head[i];

	while(temp->next!=NULL){

		temp = temp->next;

	}

	node * inp = getNode(n);
	temp->next = inp;

	return;
}

//enqueue
void enq(int q[], int d, int &rear){

	q[++rear] = d;
	return;
}

//dequeue
int deq(int q[], int &front){

	front++;

	return q[front-1];
}

//Breadth-First-Search
void bfs(node * head[], int q[], int y, int &rear, int &front, int end){

	head[y]->color = 1;
	head[y]->d = 0;

	enq(q, y, rear);

	while(front-rear!=1){

		int u = deq(q,front);
		node * temp = head[u]->next;

		while(temp!=NULL){

			if(head[temp->inx]->color==0){

				head[temp->inx]->color=1;
				head[temp->inx]->d=head[u]->d+1;

				if(temp->inx==end)return;							//when end is found end the search
				enq(q, temp->inx, rear);
			}

			temp = temp->next;
		}

		head[u]->color = 2;
	}
}

int main(){
	int t;
	cin>>t;

	int arr[t];
	node * head[10000];
	int q[10001] = {0};
	int rear = -1;
	int front = 0;

	//initializing the heads 
	for(int i = 0;i<10000;i++){

		head[i] = getNode(i);

	}

	//creating adjacent list
	for(int i=0;i<10000;i++){

		int a[4];

		a[0] = i%10;
		a[1] = (i/10)%10;
		a[2] = (i/100)%10;
		a[3] = (i/1000)%10;

		int y=0;
		for(int l=0;l<4;l++){

			if(a[l]==0){
				a[l] = 9;

				//converts 4 digits into number
				for(int j=3;j>=0;j--)
					y = y + pow(10,j)*a[j];

				ins_last(head, i, y);

				y=0;
				a[l] = 1;

				for(int j=3;j>=0;j--)
					y = y + pow(10,j)*a[j];
				
				ins_last(head, i, y);
				y=0;
				a[l] = 0;
			}
			else if(a[l]==9){

				a[l] = 8;
				for(int j=3;j>=0;j--)
					y = y + pow(10,j)*a[j];
				
				ins_last(head, i, y);
				y=0;
				a[l] = 0;
				for(int j=3;j>=0;j--)
					y = y + pow(10,j)*a[j];
				
				ins_last(head, i, y);
				y=0;
				a[l] = 9;
			}
			else{

				a[l]++;
				for(int j=3;j>=0;j--)
					y = y + pow(10,j)*a[j];
				
				ins_last(head, i, y);
				y=0;

				a[l]--;
				a[l]--;

				for(int j=3;j>=0;j--)
					y = y + pow(10,j)*a[j];
				
				ins_last(head, i, y);
				y=0;
				a[l]++;
			}
		}
	}
	int start = 0;
	int end = 0;
	for(int u=0;u<t;u++){

		start = 0;
		end = 0;
		rear = -1;
		front = 0;

		for(int i=0;i<10000;i++){

			head[i]->color = 0;
			head[i]->d=-1;

		}
		
		for(int i=3;i>=0;i--){

			int p;
			cin>>p;
			start = start + pow(10,i)*p;

		}
		
		for(int i=3;i>=0;i--){

			int p;
			cin>>p;
			end = end + pow(10,i)*p;

		}

		int r;
		cin>>r;

		//makes all forbidden nodes black so they are not traversed in bfs()
		while(r--){

			int f=0;	
			for(int i=3;i>=0;i--){

				int p;
				cin>>p;
				f = f + pow(10,i)*p;

			}
			head[f]->color = 2;
		}

		bfs(head, q, start, rear, front, end);
		arr[u] = head[end]->d;

	}

	for(int i=0;i<t;i++)
		cout<<arr[i]<<endl;
	
	return 0;
}

# include <bits/stdc++.h>
using namespace std;
//bubble sort to sort the array after each reduction step
void bubble_sort_imp2(int n, int input[]){
        int p;
        int sort;
        for(int i=0;i<n-1;i++){
                sort = 1;
                for(int j=0;j<n-i-1;j++){
                        if(input[j]>input[j+1]){
                                p = input[j];
                                input[j] = input[j+1];
                                input[j+1] = p;
                                sort = 0;
                        }
                }
                for(int j=n-2;j>i;j--){
                        if(input[j]<input[j-1]){
                                p = input[j];
                                input[j] = input[j-1];
                                input[j-1] = p;
                                sort = 0;
                        }
                }
                if(sort==1)break;
        }
}
//reduces the size of array according to the given rules
void reduce(int i, int n, int arr[]){
        for(int j=0;j<n-1-i;j++){
                arr[j]=arr[j+1]-arr[j];
        }
}
//prints array
void print_arr(int n, int arr[]){
        for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
        }
        cout<<"\n";
}
//Main function
int main(){
        int n;
        cout<<"Input : \n";
        cin>>n;
        if(n==0){
                cout<<"No Input\n";
                return 0;
        }
        int arr[n];
        //taking the input
        for(int i=0;i<n;i++){
                cin>>arr[i];
        }
        //sorts and reduces the given array n times
        for(int i=0;i<n;i++){
        bubble_sort_imp2(n, arr);     
        reduce(i, n, arr);
        }
        printf("Output : \n");
        print_arr(1, arr);
        return 0;   
}
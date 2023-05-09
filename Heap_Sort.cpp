#include<iostream>
#define left(i) (i<<1)+1;
#define right(i) (i<<1)+2;
using namespace std;

void heapify(int arr[],int u,int n){    
    int largest=u;
    int l=left(u);
    int r=right(u);
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=u){
        swap(arr[u],arr[largest]);
        heapify(arr,largest,n);
    }
}

void BuildMaxHeap(int arr[], int n){
    for(int i=(n)>>2; i>=0; i--){
        heapify(arr,i,n);
    }
}

void heapsort(int arr[],int n){ 
    int heapsize=n;
    BuildMaxHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapsize--;
        heapify(arr,0,heapsize);

    }
}
int main(){
    // int arr[]={7,2,1,5,8}; int n= 5;
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Max Heap: ";
    BuildMaxHeap(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"Heap Sort: ";
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
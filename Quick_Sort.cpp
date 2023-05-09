#include<iostream>
#include<ctime>
using namespace std;

int partition(int arr[], int f, int l){
    srand(time(0));
    int p= rand()%(l-f+1) +f;
    swap(arr[l],arr[p]);
    int pivot= arr[l];
    int i= f-1;
    for(int j = f; j<=l-1; j++){
        if(arr[j]<=pivot){
            i+=1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}
void Quick(int arr[], int f, int l){
    if(f>=l){
        return;
    }
    int p= partition(arr,f, l);
    Quick(arr, f, p-1);
    Quick(arr, p+1, l);
}

// Quick_Sort_without_Tail_Recursion
void Quick_without_Tail_Rec(int arr[], int f, int l){
    while(f<l){
        int p=partition(arr,f,l);
        Quick_without_Tail_Rec(arr,f,p-1);
        f= p+1;
    }
}

// H_Partition
int H_partition(int arr[], int p, int r){
    int x= arr[p];
    int i=p-1;
    int j= r+1;
    while(true){
        do{
            j=j-1;
        }while(arr[j]<= x);
        do{
            i=i+1;
        }while(arr[i]>=x);
        if(i<j){
            swap(arr[i],arr[j]);
        }
        else{
            return j;
        }
    }
}


int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter elements in array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Given array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    Quick(arr,0, n-1);
    cout<<"Array Sorted by Quick Sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    cout<<"Quick_Sort_without_Tail_Recursion: ";
    Quick_without_Tail_Rec(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    // cout<<H_partition(arr,0,n-1)<<endl;
    cout<<"H_Partition: ";
    H_partition(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    return 0;
}
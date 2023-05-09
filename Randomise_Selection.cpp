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
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}
int Randomise_Select(int arr[], int p,int r,int i){
    if(p==r){
        return arr[p];
    }
    int q= partition(arr,p,r);
    int k=q-p+1;
    if(i==k){
        return arr[q];
    }
    else if(i<k){
        return Randomise_Select(arr,p,q-1,i);
    }
    else{
        return Randomise_Select(arr,q+1,r,i-k);
    }
    // swap(arr[p],arr[r]);
}

int main(){
    // int n;
    // cout<<"Enter size of array: ";
    // cin>>n;
    // int arr[n];
    // cout<<"Enter elements in array: ";
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // int n=10;
    int arr[]={3,2,0,1,2,3};
    // int arr[]={4,8,4,6,5,9,6,6,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Given Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    cout<<"Element at index 4: "<<Randomise_Select(arr,0,5,4)<<endl;
    cout<<"Randomise_Select Sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
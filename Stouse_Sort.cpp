#include<iostream>
using namespace std;

void stouse(int arr[],int f, int l){
    if(arr[f]>arr[l]){
        swap(arr[f],arr[l]);
    }
    if(f+1>=1){
        return;
    }
    int t= (l-f+1)/3;
    stouse(arr,f,l-t);
    stouse(arr,f+t,l);
    stouse(arr,f,l-t);
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

    cout<<"Stouse Sort: ";
    stouse(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
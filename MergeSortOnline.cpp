#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    // int n1= mid-l+1;
    // int n2= r-mid;
    // int a[n1];
    // int b[n2];
    // for(int i=0; i<n1; i++){
    //     a[i]= arr[l+i];
    // }
    // for(int i=0; i<n2; i++){
    //     b[i]= arr[mid+1+i];
    // }
    // int i=0, j=0;
    // int k=l;
    // while(i<n1 && j<n2){
    //     if(a[i] < b[j]){
    //         arr[k]= a[i];
    //         k++;
    //         i++;
    //     }
    //     else{
    //         arr[k]= b[j];
    //         k++;
    //         j++;
    //     }
    // }
    // while(i<n1){
    //     arr[k]= a[i];
    //     k++;
    //     i++;
    // }
    // while(j<n2){
    //     arr[k]= b[i];
    //     k++;
    //     j++;
    // }




    int merg[r-l+1];
    // int m[] = new int[e-s+1];
    int index1= l;
    int index2= mid+1;
    int x=0;
    while(index1<= mid &&index2<= r){
        if(arr[index1]< arr[index2]){
            merg[x++] = arr[index1++];
            // x++;index1++;
        }
        else{
            merg[x++]= arr[index2++];
            // x++;index2++;
        }
    }
    while(index1 <= mid){
        merg[x++]= arr[index1++];
        // x++;index1++;
    }
    while(index2 <= mid){
        merg[x++]= arr[index2++];
        // x++;index2++;
    }
    // for(int i=0, j=s;i<m.length();i++,j++){
    // for(int i=0, j=l; i<(r-l+1);i++,j++){
    //     arr[j]= merg[i];
    // }
    for (int i = l, x = 0; i <= r; ++i, ++x) {
        arr[i] = merg[x];
    }
}


void MergeSort(int arr[], int first, int last){
    // if(first >= last){
    //     return;
    // }
    // int mid = first + (last - first)/2;
    if(first<last){
    int mid = (last + first)/2;
    MergeSort(arr, first, mid);
    MergeSort(arr, mid+1, last);
    merge(arr, first, mid, last);
    }
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
    // int arr[]={5,9,2,7,4,123,5,32,54,12};
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int arr[n]={5,4,3,2,1};
    
    cout<<"Given array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    MergeSort(arr,0,n-1);
    cout<<"Merge Sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include <iostream>
using namespace std;

void insertion(int arr[], int n){
    int key;
    int comp=0;
    for(int i=1; i<n ; i++){
        int number_of_swap=0;
        key= arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j--;
            comp++;
            number_of_swap++;
        }
        arr[j+1]=key;
        for(int i=0; i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"=> Number of swap: "<<number_of_swap<<endl;
    }
    cout<<"Number of Swap/Comparisons are: "<<comp<<endl;
}


// void bubble(int arr[], int n){
//     bool sorted = false;
//     for(int i=1;i<n; i++){
//         for(int j=0; j<n-i; j++){
//             sorted = true;
//             if(arr[j]>arr[j+1]){
//                 sorted = false;
//                 swap(arr[j],arr[j+1]); 
//             }
//         }
//     }
// }

// void selection(int arr[], int n){
//     int x=0;
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[j]<arr[i]){
//                 int smallest = j;
//                 swap(arr[i],arr[smallest]);
//             }
//         }
//     }
// }

int main(){
    int n, *arr, target;
    cout<<"Enter size of array: ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter array element: ";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Given Array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    insertion(arr, n);


    // cout<<"Given Numbers which Perform :"<<endl;
    // cout<<"  1 for Insertion sort."<<endl;
    // cout<<"  2 for Bubble sort."<<endl;
    // cout<<"  3 for Selsction sort."<<endl;
    // 
    // int x;
    // cout<<"Enter a number which you perform: ";
    // cin>>x;
    // 
    // cout<<"Given Array is: ";
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // 
    // if(x==1){
    //     insertion(arr, n);
    // }
    // else if(x==2){
    //     bubble(arr, n);
    // }
    // else if(x==3){
    //     selection(arr, n);
    // }
    // else{
    //     cout<<"!!! Invalid Choice !!!";
    //     return 0;
    // }

    cout<<"Array after sorting is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include<iostream>
using namespace std;

// void Count_Sort(int arr[], int n){     /////Error ////
//     int y=n;
//     int freq[y];
//     int out[n];
//     int j;
//     for(int i=0; i<y;i++){
//         freq[i]=0;
//     }
//     for(int i=0; i<=n-1; i++){
//         j=arr[i];
//         freq[j]++;
//     }
//     for(int i=1; i<y;i++){
//         freq[i]+=freq[i-1];
//     }
//     for(int i=n-1;i>=0; i--){
//         j=arr[i];
//         freq[j]--;
//         out[freq[j]] = j;
//     }

// }


void Count_Sort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k= max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k; i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--){
        int j= arr[i];
        count[j]--;
        output[count[j]]=j;
        
        // output[--freq[arr[i]]]= arr[i];
    }
    for(int i=0; i<n;i++){
        arr[i]= output[i];
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
    int n=6;
    int arr[n]={3,2,0,1,2,3};
    
    cout<<"Given Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    Count_Sort(arr,n);
    cout<<"Count Sort: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
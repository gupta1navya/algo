#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Bucket_Sort(float arr[],int n){
    //creating 10 buckets
    vector<float> bucket[10];

    //inserting elements of arr in bucket
    for(int i=0;i<n;i++){
        bucket[(int)(n*arr[i])].push_back(arr[i]);
    }
    //Sort the buckets
    for(int i=0;i<n;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[index++]=bucket[i][j];
        }
    }

}
int main(){
    float arr[6]={0.23,0.96,0.53,0.12,0.6,0.8};
    cout<<"Given array: ";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    Bucket_Sort(arr,6);
    cout<<"Bucket Sort: ";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
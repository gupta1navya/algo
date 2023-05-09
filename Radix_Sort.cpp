#include<iostream>
#include<cmath>
using namespace std;

int maxdigits(int arr[],int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    int d=0;
    while(mx!=0){
        mx=mx/10;
        d++;
    }
    return d;
}

int* count_sort(int arr[],int n,int j){
    int freq[10]={0};
    int *out;
    out=new int[n];

    for(int i=0;i<n;i++){
        int x=(arr[i]%(int)(pow(10,j)))/(int)pow(10,j-1);
        freq[x]++;
    }
    
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    
    
    for(int i=n-1;i>=0;i--){
         int x=(arr[i]%(int)(pow(10,j)))/(int)pow(10,j-1);
        freq[x]--;
        out[freq[x]]=arr[i];
    }
    return out;
}

void Radix_Sort(int arr[],int n){
    int d=maxdigits(arr,n);
    for(int i=1;i<=d;i++){
            int *out=count_sort(arr,n,i);
            for(int g=0;g<n;g++){
                arr[g]=out[g];
            }
            delete[] out; 
    }
}
int main(){
    int arr[6]={270,254,345,351,789,111};
    Radix_Sort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
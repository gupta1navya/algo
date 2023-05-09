#include <iostream>
#include <cstring>
using namespace std;
//Memoised 
int Mknapsack(int n, int W, int wt[], int val[], int M[][1001]) {
    if (n == 0) return 0;
    if (M[n][W] != -1) return M[n][W];
    
    int result;
    if (wt[n-1] > W) {
        result = Mknapsack(n-1, W, wt, val, M);
    } else {
        result = max(val[n-1] + Mknapsack(n-1, W-wt[n-1], wt, val, M), Mknapsack(n-1, W, wt, val, M));
    }
    M[n][W] = result;
    return result;
}

//Iterative
int knapsack(int wt[], int val[], int W, int n) {
    int M[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) M[i][w] = 0;
            else if (wt[i-1] <= w) M[i][w] = max(val[i-1] + M[i-1][w-wt[i-1]], M[i-1][w]);
            else M[i][w] = M[i-1][w];
        }
    }
    return M[n][W];
}
int main() {
    // sample test case
    // int wt[] = {10, 20, 30};
    // int val[] = {60, 100, 120};
    int n, W;
    cout << "Enter the number of weights: " << endl;
    cin >> n;
    int val[n], wt[n];
    cout << "Enter the maximum capacity of Weights: "<< endl;
    cin >> W;

    for (int i = 0; i < n; i++){
        cout << "Enter the value and weight of the item " << i+1 << " as '(val,wt)' respectively: ";
        cin >> val[i] >> wt[i];
    }
    
    int M[n+1][1001];
    memset(M, -1, sizeof(M));
    
    int result = knapsack(wt, val, W, n);
    cout << "Maximum value of Knapsack: " << result << endl;

    int result2 = Mknapsack(n, W, wt, val, M);
    cout << "Maximum value of Mknapsack: " << result2 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int Memo[100]; // Memoization array to store previously calculated values

// A structure to represent a job
struct Job {
    int start, finish, weight;
};

// Find the latest job (in sorted array) that doesn't conflict with the current job
int latestNonConflict(Job arr[], int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (arr[j].finish <= arr[i].start) {
            return j;
        }
    }
    return -1;
}

// Recursive function for the maximum weight subset of non-overlapping jobs
int mWis(Job arr[], int n) {
    if (Memo[n] != -1) {
        return Memo[n];
    }
    if (n == 0 || n == 1) {
        Memo[n] = 0;
        return Memo[n];
    }
    // Include the current job with its weight or exclude it
    int j = latestNonConflict(arr, n - 1);
    int include = arr[n - 1].weight + ((j != -1) ? mWis(arr, j + 1) : 0);
    int exclude = mWis(arr, n - 1);
    // Take the maximum of the two cases
    Memo[n] = max(include, exclude);
    return Memo[n];
}

int main() {
    memset(Memo, -1, sizeof Memo);
    Job arr[] = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxWeight = mWis(arr, n);
    cout << "Maximum weight of non-overlapping jobs = " << maxWeight << endl;
    return 0;
}

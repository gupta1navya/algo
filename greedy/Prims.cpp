#include <iostream>
#include <cstring>
using namespace std;
#define INF 9999999
#define V 5

int G[V][V] = {
        0, 1, 0, 0, 5,
        1, 0, 2, 0, 6,
        0, 2, 0, 7, 4,
        0, 0, 7, 0, 8,
        5, 6, 4, 8, 0,

//   {0, 9, 75, 0, 0},
//   {9, 0, 95, 19, 42},
//   {75, 95, 0, 51, 66},
//   {0, 19, 51, 0, 31},
//   {0, 42, 66, 31, 0}
};

int main() {
    int no_edge =0;   // set number of edge to 0
    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];
    memset(selected, false, sizeof(selected));    // set selected false initially

    // choose 0th vertex and make it true
    selected[0] = true;

    int x;
    int y;
    int minweight=0;

    cout << "Edge : " << "Weight" << endl;
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
                        if (min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        minweight = minweight + G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    cout << "Total Minimum weight: " << minweight;

    return 0;
}
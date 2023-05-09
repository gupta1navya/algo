#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int *p;

class Edge{
    int u, v, w;
    public: 
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator < (const Edge &e) const {
        return (this->w < e.w);
    }
    int src(){return u;}
    int dest(){return v;}
    int weight(){return w;}
};

int find(int x){
    if (p[x] == x) return x;
    return find(p[x]);
}

void Union(int a, int b){
    int x = find(a);
    int y = find(b);
    if (x==y) return;
    p[y] = x;
}

void kruskal(vector<Edge> e, int V){
    int solution = 0;
    cout << "all the edges to be included"<<endl;
    for (int i = 0; i < e.size(); i++){
        int r_src = find(e[i].src());
        int r_dest = find(e[i].dest());
        if (r_src != r_dest){
            Union(r_src, r_dest);
            cout << "(" << e[i].src()+1 << ",  " << e[i].dest()+1 << ")" << endl;
            solution += e[i].weight();
        }
    }
    cout << "Total minimum wieght of egde:  ";
    cout << solution;
}

int main(){
    int n = 5;
    int arr[] = {
        0, 1, 0, 0, 5,
        1, 0, 2, 0, 6,
        0, 2, 0, 7, 4,
        0, 0, 7, 0, 8,
        5, 6, 4, 8, 0,

/////----------------------------------
        // 0, 9, 75, 0, 0,
        // 9, 0, 95, 19, 42,
        // 75, 95, 0, 51, 66,
        // 0, 19, 51, 0, 31,
        // 0, 42, 66, 31, 0
    };
    p = new int[n];

    for (int i = 0; i < 5; i++){
        p[i] = i;
    }

    vector<Edge> e;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (arr[i*n+j] > 0){
                e.push_back(Edge(i, j, arr[i*n+j]));
            }
        }
    }
    // sorting the edge based on the weight
    sort(e.begin(), e.end());


    kruskal(e, n);
    return 0;
}

#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;
// #ifndef BINARY_SEARCH_TREE
// #define BINARY_SEARCH_TREE

const int MAX_VERTICES = 6;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data= data;
            this->left=this->right=NULL;
        }
        friend class BinaryTree;
};

class BinaryTree{
    Node* root;
    int index=-1;
public:
    BinaryTree(){ root=0; }
    ~BinaryTree(){clear();}
    void clear(){
        // clear(root); 
        root=0;
    }
    bool isEmpty() const{
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    Node* builtTree(int nodes[]){
        index++;
        if(nodes[index]==-1){
            return NULL;
        }
        Node* newNode= new Node(nodes[index]);
        newNode->left= builtTree(nodes);
        newNode->right= builtTree(nodes);
        return newNode;
    }

    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    void levelorder(Node* root){ //Iterative BFS
        if(root==NULL){return;}
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* curr= q.front();
            q.pop();
            if(curr==NULL){
                cout<<endl;
                if(q.empty()){
                    break;
                }
                else{
                    q.push(NULL);
                }
            }
            else{
                cout<<curr->data<<" ";
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
    }

    void BFS(Node* root){  // Recursive BFS
            queue<Node*> q;
            q.push(root);
            while (!q.empty()){
                Node *cur_node  = q.front();
                cout << cur_node->data << " ";
                q.pop();
                if (cur_node->left) q.push(cur_node->left);
                if (cur_node->right) q.push(cur_node->right);
        }
    }


    // void DFS(int start) {
    //     // create a visited array and initialize it to false
    //     bool visited[MAX_VERTICES] = { false };

    //     // create a stack for DFS
    //     stack<int> s;

    //     // mark the current node as visited and push it to stack
    //     visited[start] = true;
    //     s.push(start);

    //     while (!s.empty()) {
    //         // pop a vertex from stack and print it
    //         int u = s.top();
    //         cout << u << " ";
    //         s.pop();

    //         // get all adjacent vertices of the popped vertex u
    //         for (int v = 0; v < V; v++) {
    //             if (adj[u][v] && !visited[v]) {
    //                 visited[v] = true;
    //                 s.push(v);
    //             }
    //         }
    //     }
    //     cout << endl;
    // }
    void DFS(Node* root){

    }

};


int main(){
try{
    // int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int nodes[]={5,3,2,-1,-1,4,-1,-1,7,-1,8,-1,-1};
    BinaryTree tree;
    Node* root= tree.builtTree(nodes);
    cout<<"Root is: "<<root->data<<endl;
    
    cout<<"Level Order Traversal: ";
    tree.levelorder(root);
    cout<<"BFS: ";
    tree.BFS(root);
    cout<<endl<<"Display elements of the BST by following Traversals:"<<endl;
    cout<<"Pre Order:  ";
    tree.preorder(root);
    cout<<endl<<"In  Order:  ";
    tree.inorder(root);
    cout<<endl<<"Post Order: ";
    tree.postorder(root);

    cout<<endl<<"DFS: ";
    tree.DFS(root);

}
catch(char const msg){
    cout<<msg<<endl;
}
return 0;
}
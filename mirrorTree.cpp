#include <bits/stdc++.h>
using namespace std;
#define pb push_back  
#define loop(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
#define asort(a) sort(a,a+n)
#define vsort(v) sort(v.begin(), v.end())
#define remdup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

class Node{
    public:
    int data;
    Node* left, *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void levelOrder(Node* node, int level){
    if(node == NULL) return;
    if(level == 1)
        cout << node->data << " ";
    else{
        levelOrder(node->left, level-1);
        levelOrder(node->right, level-1);
    }
}

int height(Node* node){
    if(node == NULL) return 0;
     int lheight = height(node->left);
    int rheight = height(node->right);
    return (max(lheight, rheight)+1);
}

void printLevelOrderTree(Node* node){
    if(node == NULL) return;
    int h = height(node);
    for(int i = 1; i <= h; i++)
        levelOrder(node, i);
}

void mirror(Node* node){
    if(node == NULL) return;
    //using level order traversal to swap left and right node
    queue<Node *> q;
    q.push(node);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        swap(curr->left, curr->right);
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

int main() {
    Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    printLevelOrderTree(node);
    mirror(node);
    printLevelOrderTree(node);
}
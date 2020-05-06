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
    int val;
    Node* left, *right;
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

int height(Node* tree){
    if(tree == NULL) return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    return max(lheight, rheight)+1;
}

void levelOrder(Node* tree, int level, Node* &curr){
    if(tree == NULL) return;
    if(level == 1){
        curr = tree;
    }
    else{
        levelOrder(tree->left, level-1, curr);
        levelOrder(tree->right, level-1, curr);
    }
}

void rightView(Node* tree){
    int h = height(tree);
    for(int i = 1; i <= h; i++){
        Node* curr;
        levelOrder(tree, i , curr);
        cout << curr->val << " ";
    }
}


int main(){
    Node* tree;
    tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->right->left = new Node(5);
    tree->right->right = new Node(6);
    tree->right->left->left = new Node(7);
    rightView(tree);
}
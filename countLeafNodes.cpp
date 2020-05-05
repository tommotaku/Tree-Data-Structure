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
    return (max(lheight, rheight)+1);
}

void levelOrder(Node* tree, int level, int& count){
    if(tree == NULL) return;
    if(level == 1){
        if(tree->left == NULL && tree->right == NULL)
            count++;
    }
    else{
        levelOrder(tree->left, level-1, count);
        levelOrder(tree->right, level-1, count);
    }
}

int leafNodes(Node* tree){
    int count = 0;
    int h = height(tree);
    for(int i = 1; i <= h; i++)
        levelOrder(tree, i, count);
    return count;
}

int main(){
    Node* tree;
    tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->right->left = new Node(5);
    tree->right->right = new Node(6);

    cout << leafNodes(tree);
}
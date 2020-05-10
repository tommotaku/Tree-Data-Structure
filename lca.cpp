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

Node* lca(Node* root, int a, int b){
    //we have to check if the node's data is between a or b or not
    if(root == NULL) return root;
    if(root->val > a && root->val > b)
        return lca(root->left, a, b);
    if(root->val < a && root->val < b)
        return lca(root->right, a, b);
    else return root;
}


int main(){
    Node* tree;
    tree = new Node(5);
    tree->left = new Node(2);
    tree->right = new Node(8);
    tree->left->left = new Node(1);
    tree->left->right = new Node(4);
    tree->right->right = new Node(10);
    Node* node = lca(tree, 4, 1);
    cout << node->val << endl;
}
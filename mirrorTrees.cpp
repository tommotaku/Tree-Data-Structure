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

bool areMirrorTrees(Node* a, Node* b){
    if(a == NULL && b == NULL) 
        return true;
    if(a == NULL || b == NULL)
        return false;
    if(a->val != b->val)
        return false;
    return areMirrorTrees(a->left, b->right) && areMirrorTrees(a->right, b->left);
}

int main(){
    Node* tree;
    tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    Node* tree1;
    tree1 = new Node(1);
    tree1->left = new Node(3);
    tree1->right = new Node(2);
    tree1->right->left = new Node(5);
    tree1->right->right = new Node(4);
    if(areMirrorTrees(tree, tree1))
        cout << "YES\n";
    else cout << "NO\n";
}
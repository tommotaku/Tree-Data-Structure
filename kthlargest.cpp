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

void inorder(Node* root, int& count, int k){
    if(root && count < k){
        inorder(root->right, count, k);
        count++;
        if(count == k){
            cout << root->val << endl;
            return;
        }
        inorder(root->left, count, k);
    }
}

void kthlargest(Node* root, int k){
    int count = 0; //if count = k then kth element is reached
    //use reverse inorder traversal
    inorder(root, count, k);
}

int main(){
    Node* tree;
    tree = new Node(5);
    tree->left = new Node(2);
    tree->right = new Node(8);
    tree->left->left = new Node(1);
    tree->left->right = new Node(4);
    tree->right->right = new Node(10);
    kthlargest(tree, 3);
}
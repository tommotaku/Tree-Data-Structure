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
bool isBSTUtil(Node* root, int min, int max){
    if(root == NULL) return true;
    if(root->val < min || root->val > max)
        return false;
    return isBSTUtil(root->left, min, root->val-1) && isBSTUtil(root->right, root->val-1, max);
}

bool isBST(Node* root){
    //we check each vale with a max and min value
    //initially they are INT_MAX and INT_MIN
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node* tree;
    tree = new Node(5);
    tree->left = new Node(2);
    tree->right = new Node(8);
    tree->left->left = new Node(1);
    tree->left->right = new Node(4);
    tree->right->right = new Node(10);
    if(isBST(tree)) cout << "YES";
    else cout << "No";
}
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

bool hasPathSum(Node* node, int sum){
    if(node == NULL) return false; // sum >= 1
    if(node->left == NULL && node->right == NULL)//leaf node
        if(sum == node->data) //remaining sum after getting subtracted is equal to the leaf node
            return true;
    int remSum = sum - node->data;
    return hasPathSum(node->left, remSum) || hasPathSum(node->right, remSum);
 }

int main() {
    Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    if(hasPathSum(node, 6)) cout << "Yes";
    else cout << "No";
}
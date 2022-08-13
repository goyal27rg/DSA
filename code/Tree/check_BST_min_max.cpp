/* Check if the given Binary Tree is a BST or not using min, max boundary
time: O(n), every node visited once
BST follows this property:
    1. All the nodes in the left subtree of a node will be lesser in 
       value (assuming all nodes distinct)
    2. All the nodes in the right subtree of a node will be greater 
       in value

Based on this, we can put boundaries on each node in the tree (except root node)
We check recursively if the values are in the boundary for each node.

If for any node, the value is not in boundary, we can return false and the
subsequent return values will be false (including the first call) 

We will visit the nodes from leaf to root in this case
*/


#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void bst_print(Node* root);
bool check_BST(Node* root, int, int);
Node* insert(Node* root, int data);

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 50);
    root = insert(root, 7);

    bst_print(root);
    cout << endl;

    cout << check_BST(root, INT_MIN, INT_MAX);
    cout << endl;
}


bool check_BST(Node* root, int min, int max) {

    if (root == NULL)
        return true;

    if (check_BST(root->left, min, root->data)
        && check_BST(root->right, root->data, max)
        && min < root->data && root->data < max)
        return true;
    else
        return false;
}


Node * insert(Node * root, int data) {
    if (root == NULL){
        root = (Node*) malloc(sizeof(Node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}


void bst_print(Node* root) {
    if (root != NULL){
        bst_print(root->left);
        cout << root->data << " ";
        bst_print(root->right);
    }
}
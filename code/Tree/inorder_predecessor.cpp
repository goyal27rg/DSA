/* INORDER PREDECESSOR OF BST
Find the reference to the (given) node whose predecessor is to be found
Case1: If this node has a left ST, then the right most value in left ST is predecessor
Case2: If there is no left ST then it means that it is the minimum node in the subtree of node "X"
       "X" is the first ancestor of this node in whose ST, the given node resides
                                            OR
        The predecessor is the deepest ancestor (closest to the node) which has a right ST
*/

#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void bst_print(Node* root);
Node* find(Node* root, int value);
Node* inorder_predecessor(Node* root, int value);
Node* insert(Node* root, int data);

int main() {
    Node* root = NULL;
    int arr[11] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    
    for (int i=0; i<11; i++) {
        root = insert(root, arr[i]);
    }
    bst_print(root);
    cout << endl;

    // cout<<(inorder_predecessor(root, 12)->data) << endl;

    for (int i=0; i<11; i++) {
        Node* predecessor = inorder_predecessor(root, arr[i]);
        cout << "Predecessor of " << arr[i] << " is: ";
        if (predecessor != NULL)
            cout << predecessor->data << endl;
        else
            cout << "DNE" << endl; //Does Not Exist
    }
}

Node* find(Node* root, int data) {
    if (root == NULL)
        return root;
    
    if (data < root->data){
        return(find(root->left, data));
    }
    else if (data > root->data){
        return(find(root->right, data));
    }
    else {
        return root;
    }

}

Node* inorder_predecessor(Node* root, int value) {
    Node* current = find(root, value); // find returns a pointer to the node
    // Case 1: If "current" has a left ST
    if (current->left) {
        Node* left = current->left;
        while(left->right != NULL)
            left = left->right;
        return left;
    }
    // Case 2: Current has no left ST. Try to find deepest ancestor with a right child
    Node* predecessor=NULL, *ancestor = root;

    while(ancestor != current){ //start walking the tree
        if (current->data < ancestor->data)
            ancestor = ancestor->left;
        else {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
    }
    return predecessor;

}

Node* insert(Node * root, int data) {
    if (root == NULL){
        root = (Node*) malloc(sizeof(Node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
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
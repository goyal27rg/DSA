#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void bst_print(Node* root);
bool bst_search(Node* root, int data);
Node* insert(Node* root, int data);

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 50);
    root = insert(root, 50);
    root = insert(root, 7);

    bst_print(root);
    cout << endl;

    cout << bst_search(root, 7);
}


bool bst_search(Node* root, int data) {
    if(root==NULL)
        return false;
    else if (root->data == data)
        return true;
        
    if (data < root->data)
        return bst_search(root->left, data);
    else
        return bst_search(root->right, data);
}


Node * insert(Node * root, int data) {
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
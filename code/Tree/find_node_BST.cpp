/* Find the address of a node with a given value in BST */


#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void bst_print(Node* root);
Node* find_node(Node* root, int);
Node* insert(Node* root, int data);

int main() {
    Node* root = NULL;
    int insert_vals [10] = {5, 7, 3, 10, 1, 6, 2, 8, 9, 4};

    for (int i=0; i<10; i++){
        root = insert(root, insert_vals[i]);
    }

    bst_print(root);
    cout << endl;

    Node* n1 = find_node(root, 1);
    cout << "Address: " << n1;
    if (n1)
        cout << "\nValue: " << (*n1).data;
    else
        cout << "\nValue not in tree";
    cout << endl;
}


Node* find_node(Node* root, int value) {

    if (root == NULL)
        return NULL;
    else if (root->data == value)
        return root;

    Node* left = find_node(root->left, value);
    if (left != NULL)
        return left;
    else 
        return(find_node(root->right, value));
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
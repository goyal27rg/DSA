#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void bst_print(Node* root);
Node * insert(Node * root, int data);
int height(Node* root);
int max (int a, int b){
    if (a > b)
        return a;
    return b;
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, -10);
    root = insert(root, -20);
    root = insert(root, -25);
    root = insert(root, -24);

    bst_print(root);
    cout << endl;

    cout << height(root);
    cout << endl;
}


int height(Node* root) {
    // Height of leaf node is 0
    // Find the height of a node as max(h_left, h_right)
    // Keep recusring upto leaf nodes and back to root node

    if (root == NULL)
        return -1;

    int h_left = 0, h_right = 0;
    h_left = height(root->left) + 1;
    h_right = height(root->right) + 1;

    return max(h_left, h_right);
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
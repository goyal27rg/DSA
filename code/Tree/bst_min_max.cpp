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
bool bst_search(Node* root, int data);
void bst_min(Node* root);
void bst_min_max_iter(Node *root);
Node* insert(Node* root, int data);

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, -10);
    root = insert(root, -20);
    root = insert(root, -5);
    root = insert(root, 7);

    bst_print(root);
    cout << endl;

    bst_min(root);
}


void bst_min(Node* root) {
    if(root == NULL){
        cout << "Tree is empty" << endl;
    }
    else if (root->left == NULL) {
        cout << "Min: " << root->data << endl;
        return;
    }
    bst_min(root->left);
}

void bst_min_max_iter(Node* root) {
    //min: go as left as possible
    //max: go as right as possible

    if (root == NULL)
        cout << "Tree is empty" << endl;

    Node* ptr = root;
    while(ptr->left != NULL){
        ptr = ptr->left;
    }
    cout << "Min: " << ptr->data << endl;

    ptr = root;
    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    cout << "Max: " << ptr->data << endl;
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
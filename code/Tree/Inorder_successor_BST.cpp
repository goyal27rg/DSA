#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void bst_print(Node* root);
Node* find(Node* root, int value);
Node* inorder_successor(Node* root, int value);
Node* insert(Node* root, int data);

int main() {
    Node* root = NULL;
    int arr[11] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    
    for (int i=0; i<11; i++) {
        root = insert(root, arr[i]);
    }
    bst_print(root);
    cout << endl;

    // cout<<(inorder_successor(root, 12)->data) << endl;

    for (int i=0; i<11; i++) {
        Node* successor = inorder_successor(root, arr[i]);
        cout << "successor of " << arr[i] << " is: ";
        if (successor != NULL)
            cout << successor->data << endl;
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

Node* inorder_successor(Node* root, int value) {
    Node* current = find(root, value); // find returns a pointer to the node
    // Case 1: Right ST exists: leftmost of right ST is successor (i.e. min of right ST)
    if (current->right) {
        Node* ptr = current->right;
        while(ptr->left != NULL) {
            ptr = ptr->left;
        }
        return ptr;
    }
    
    Node* ancestor = root, *successor = NULL;
    /*
    Case 2: Right ST is not there. Successor will be the first ancestor which itself is a left child
    --> Point 1: For a given Node, any node in it's left ST won't have a successor beyond the given Node.
    We have the pointer to the given Node as "current"
    We need to traverse the tree to reach "current", which will be done using "ancestor"
    Idea is that we will capture "ancestor" only when it is about to move left and save this pointer in "successor".
    The ancestor moved left which means the fresh successor has a left ST.
    The current node is in this left ST, which means that it's successor cannot be higher than the "successor" (point 1.)
    */

    while(ancestor != current) {
        if(current->data < ancestor->data) {
            //record left moves of ancestor in successor
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
            ancestor = ancestor->right;
    }
    return successor;
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
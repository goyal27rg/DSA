#include<iostream>

using namespace std;

/*  using STL queue
    void levelOrder(Node * root) {
        if (root==NULL)
            return;
        
        queue<Node*> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            Node* ptr = Q.front();
            Q.pop();
            if (ptr->left)
                Q.push(ptr->left);
            if (ptr->right)
                Q.push(ptr->right);
            cout << ptr->data << " ";         
        }

    } */


class queue {
    public:
        Node** front, **rear;
        queue(){
            front = rear = NULL;
        }
        void push (Node* ptr) {

        }
};

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
void level_order(Node* root);

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


void level_order(Node* root) {
    queue<Nod
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
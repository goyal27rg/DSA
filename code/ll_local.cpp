#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

void insert_node(Node** PointerHEAD, int data);
void insert_beg(Node** PointerHEAD, int data);
void print_ll(Node** PointerHEAD);

int main() {

    Node* head = NULL; //(Node*) malloc(sizeof(Node)); 
    insert_node(&head, 10);     insert_node(&head, 20);//     insert_node(30);     insert_node(40);
    
    print_ll(&head);

    insert_beg(&head, -1);     insert_beg(&head, -2);     insert_beg(&head, -3);

    print_ll(&head);

    cout<<" <<<<<<<<< done >>>>>>>>>> "<<endl;
}

void insert_node(Node** PointerHEAD, int data) {
    Node *temp = *PointerHEAD;
    if (*PointerHEAD==NULL){
        *PointerHEAD = new Node();
        (*PointerHEAD)->next = NULL;
        (*PointerHEAD)->data = data;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    // now temp is at the last node
    temp->next = new(Node); // add a new node at the end
    temp = temp->next; // temp points to the new node added at the end
    temp->next = NULL; // make temp->next NULL as it is the last node
    temp->data = data; // assign the data to the last node's data
}

void insert_beg(Node** PointerHEAD, int data){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = *PointerHEAD;
    *PointerHEAD = temp;
}

void print_ll(Node** PointerHEAD){
    if (*PointerHEAD==NULL){
        cout<<"\n\nLIST IS EMPTY\n\n";
        return;
    }
    cout<<endl;
    Node* temp = *PointerHEAD;
    do{
        cout<<temp->data<<", ";
        temp = temp->next;
    }while(temp!=NULL);
    cout<<endl;
}
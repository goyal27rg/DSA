#include<iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

void insert_node(int data);
void insert_beg(int data);
void reverse_ll();
void print_ll();

Node *start = NULL;

int main() {

    insert_node(10);     insert_node(20);     insert_node(30);     insert_node(40);
    print_ll();

    insert_beg(-1);     insert_beg(-2);     insert_beg(-3);
    print_ll();
    
    reverse_ll();
    print_ll();

    cout<<" <<<<<<<<< done >>>>>>>>>> "<<endl;
}

void insert_node(int data) {
    Node *temp = start;
    if (start==NULL){
        start = new Node();
        start->next = NULL;
        start->data = data;
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

void insert_beg(int data){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = start;
    start = temp;
}

void print_ll(){
    if (start==NULL){
        cout<<"\n\nLIST IS EMPTY\n\n";
        return;
    }
    cout<<endl;
    Node* temp = start;
    do{
        cout<<temp->data<<", ";
        temp = temp->next;
    }while(temp!=NULL);
    cout<<endl;
}

void reverse_ll() {
    
    Node *temp = start;
    Node *last = NULL;

    while(temp->next!=NULL) {temp = temp->next;}
    Node *end = last = temp; //end points to the last node, save it, later need to make it "start"

    /*
        Algorithm:
        1. Save the last node addr in "end" and "last".
        2. Traverse to the node just before the node pointed to by "last"
        3. Make the "last" node point to the current node
        4. Mark the current node as "last"
    */
    temp = start;
    while(last!=start) {
        while(temp->next!=last) {temp=temp->next;}
        (temp->next)->next = temp;
        last=temp;
        temp=start;
    }
    start=end;
    last->next=NULL;

}
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

void insert_node(int data);
void insert_beg(int data);
void del_node(int pos);
void print_ll();

Node *start = NULL;

int main() {

    insert_node(10);     insert_node(20);     insert_node(30);     insert_node(40);
    print_ll();

    insert_beg(-1);     insert_beg(-2);     insert_beg(-3);
    print_ll();
    char ch = 'y';
    int pos;
    while(ch=='y') {
        cout<<"Enter node to delete: ";
        cin >> pos;
        del_node(pos);
        print_ll();
        cout<<"Continue? ";
        cin>>ch;
    }

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

void del_node(int pos) {
    if (pos<1) {
        cout<<"INVALID POSITION TO DELETE:" <<pos <<endl;
        return;
    }
    Node *temp = start;
    if (pos==1) {
        start = start->next;
        free(temp);
        return;
    }
    int idx = 0;
    int flag=0;
    while(temp->next!=NULL) {
        if(idx==pos-2) {
            flag=1;
            break;
        }
        idx++;
        temp = temp->next;
    }
    if (flag==0) {
        cout<<"Position:" << pos <<" not found." << endl;
        return;
    }
    Node *temp1 = temp->next; // to free it later
    temp->next = temp1->next; // node removed from LL
    free(temp1);
}
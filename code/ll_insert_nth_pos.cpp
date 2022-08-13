#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

void insert_node(int data, int pos=-1);
void insert_beg(int data);
void print_ll();

Node *start = NULL;

int main() {

    insert_node(10);     insert_node(20);     insert_node(30);     insert_node(40);
    print_ll();

    insert_node(100, 5);
    print_ll();

    //insert_node(800, 0);
    //print_ll();

    // insert_beg(-1);     insert_beg(-2);     insert_beg(-3);

    // print_ll();

    cout<<" <<<<<<<<< done >>>>>>>>>> "<<endl;
}

void insert_node(int data, int pos) {
   // insert a new node at index=pos-1
   Node* new_node = new Node();
   new_node->data = data;
   new_node->next = NULL;

   // this node is to be inserted between n-2 and n-1 index no.
    if (start==NULL or pos==1){
        if (pos>1){
            cout<<"Empty list. Can't insert at position:"<<pos<<endl;
        }
        if (start==NULL) { start=new_node;}
        else{
            new_node->next=start;
            start=new_node;
        }
        return;
    }
    Node* temp = start;
    int idx = -1;
    while(temp->next!=NULL){
        idx++;
        if (idx==pos-2){
            break;
        }
        temp = temp->next;

    } // temp is at pos-2 now

    if (idx<pos-2 || pos==0) {
        cout<<"Invalid pos: "<<pos<<". List has "<<idx+1 <<" elements only"<<endl;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;

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
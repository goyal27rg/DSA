#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node *head = NULL;

void Insert_end(int data);
void print_ll();

int main() {
    Insert_end(10);
    Insert_end(20);
    Insert_end(30);

    print_ll();    

}

void Insert_end(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    if (head==NULL) {
        head=new_node;
        return;
    }
    // begin traversal
    Node* temp = head;
    while(temp->next !=NULL) {
        temp = temp->next;
    }

    // temp is at last node
    temp->next = new_node;
    (temp->next)->prev = temp;
}

void print_ll() {
    Node* temp = head;
    while(temp!=NULL) {
        cout << "data: " << temp->data << " prev: " <<temp->prev <<" next:" << temp->next << endl;
        temp = temp->next;
    }
}
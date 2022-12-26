#include <iostream>
#include <math.h>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;

    node(int val) {
        data=val;
        next = NULL;
    }
};

void insertit(node* &head, int val) {
    node* n=new node(val);
    node* temp=head;
    if(head==NULL) {
        head=n;
        return;
    }
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=n;
}



node* reverseit(node* &head) {
    node* prev=NULL;
    node* curr=head;
    node* next;

    while(curr!=NULL) {
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
        
    }
    return prev;

}

void display(node* head) {
    node* temp=head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
}

int main() {
    node* head=NULL;
    insertit(head,7);
    insertit(head,6);
    insertit(head,2);
    for (int i=0;i<10;i++) {
        insertit(head,pow(2,i));

    }

    display(head);

   node* newhead=reverseit(head);
   display(newhead);
    return 0;
}
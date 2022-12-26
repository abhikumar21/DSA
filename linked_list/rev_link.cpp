#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val) {
       data=val;
       next=NULL;
    }
};

void insert(node* &head, int val) {
    node* n=new node(val);

    if(head==NULL) {
        head=n;
        return;
    }

    node* temp=head; 
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=n;
}

node* reverse(node* &head) {
    node* prev=NULL;
    node* curr=head;
    node* next1=curr->next;

        if(head==NULL) {
            return head;
        }
    while(curr!=NULL) {
        curr->next=prev;
        prev=curr;
        curr=next1;
        if(curr==NULL) {
            head=prev;
            // return head;
            break;
        }
        next1=next1->next;

    }
 return head;
}

// node* reverse(node* &head) {
//     node* prev=NULL;
//     node* curr=head;
//     node* next1;

       
//     while(curr!=NULL) {
//        next1=curr->next;

//        curr->next=prev;
//        prev=curr;
//        curr=next1;
//     }
//     return prev;
// }

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
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    
    display(head);
   node* newhead= reverse(head);
    display(newhead);

return 0;
}
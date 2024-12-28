#include <iostream>
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



//when data is to be modified
void insertAtTail(node* &head, int val) {
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

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->next=head;
    head=n;
    
}

void deleteit(node* &head, int num) {
    node* temp=head;

    if(head->data==num) {
        head=head->next;
        return;
    }
while(temp->next->data!=num) {
 temp=temp->next;
}
node* todelete=temp->next;
temp->next=temp->next->next;
delete todelete;
}


//when data is not to be modified
void display(node* head) {
node* temp=head;
while(temp!=NULL) {
    cout<<temp->data<<" ";
temp=temp->next;
}
cout<<endl;
}


// create linked list from array 
// ListNode* createList(vector<int>& arr) {
//     if(arr.empty()) return NULL;

//     ListNode* head = new ListNode(arr[0]);
//     ListNode* temp = head;

//     for(int i=1;i<arr.size();i++) {
//         temp->next = new ListNode(arr[i]);
//         temp=temp->next;
//     }

//     return head;
// }


int main() {
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);


    deleteit(head,1);
    insertAtHead(head, 5);
    display(head);
    return 0;
}































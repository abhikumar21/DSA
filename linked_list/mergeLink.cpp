class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        
        Node* temp=NULL;
        Node* tempHead=NULL;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        if(head1->data <= head2->data) {
            temp = temp1;
            tempHead = temp;
            temp1=temp1->next;
        }
        else{
            temp = head2;
            tempHead = temp;
            temp2=temp2->next;
        }
        
        
        while(temp1!=NULL && temp2!=NULL) {
            
            if(temp1==NULL) {
                temp->next=temp2;
                  temp->next=temp2;
                temp2=temp2->next;
            }
            else if(temp2==NULL) {
                temp->next=temp1;
                temp1=temp1->next;
            }
            
            else if(temp1->data <= temp2->data) {
                temp->next = temp1;
                temp1=temp1->next;
            }
            else if(temp1->data > temp2->data) {
                temp->next = temp2;
                temp2=temp2->next;
            }
            temp=temp->next;
            
        }
        temp->next = NULL;
       
       return tempHead;
    }
};
class Solution{
    
public:
    
    void insertNode(int q, Node* &Head){
        node* n=new node(data);
        if(Head==NULL) {
            head=n;
            return;
        }
        node* temp=Head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=n;
       
    }
    
    
    
    Node* sortList(Node* head)
    {
        priority_queue<int> q;
      
        while(temp!=NULL) {
           q.push(temp->data);
           temp=temp->next;
        }
        Node* Head=NULL;
        while(!q.empty()) {
            insert(q.front(), Head);
        }
        return Head;
    }
};
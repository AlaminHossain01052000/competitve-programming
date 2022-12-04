if(head==NULL){
        return;
    }
    Node* one=NULL;
    Node* two=head;
    
    while(two->next!=NULL){
       Node* temp=two->next;

       two->next=one;
       if(two->next==NULL){
        tail=two;
       }
        one=two;
        two=temp;
    }
    head=two;
    two->next=one;
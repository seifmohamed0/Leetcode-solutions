class MyLinkedList{

private:
        struct Node{
            
        int val;
        Node * next,*prev;
        Node(int x): val(x),next(NULL),prev(NULL) {}
    };
    Node * head;
    
public:
    
    MyLinkedList() {
        
        head=NULL;
        
    }
    
    int get(int index) {
        
        Node * current=head;
        int count=0;
        if(current==NULL)
            return -1;
        if(index<0)
            return -1;
        while(current!=NULL)
        {
            count++; 
            current=current->next;
              
        }
        
        if(index>=count)
        {
            return -1;
        }
        current=head;
        for(int i=0;i<index;++i)
            current=current->next;
        return current->val;
        
        
    }
    
    void addAtHead(int val) {
        
        Node * node=new Node(val);
        if(head==NULL)
        {
            head=node;
            return;
        }
        else{
            node->next=head;
            head->prev=node;
            head=node;
            
        }
       
        
    }
    
    void addAtTail(int val) {
        
        Node * node=new Node(val),*curr=head;
        if(head==NULL)
        {
            head=node;
            return;
            
        }
        else{
           while(curr->next!=NULL)
               curr=curr->next;
        }
        curr->next=node;
        node->prev=curr;
        curr=node;
        
        
    }
    
    void addAtIndex(int index, int val) {
        
        Node * current=head;
        Node * node=new Node(val);
        int count=0;
        if(index==0)
            addAtHead(val);
        
        else
        {
            while(current!=NULL)
            {
                count++;
                current=current->next;
            
            }
            current=head;
            if(index==count)
                addAtTail(val);
            else if(index>count)
                return;
            else
            {
                current=head;
                for(int i=0;i<index-1;++i)
                    current=current->next;
                
                node->next=current->next;
                current->next->prev=node;
                current->next=node;
                node->prev=current;

            }
            
        }
        
        
    }
    
    void deleteAtIndex(int index) {
        
        Node * current=head,*temp;
        int count=0;
        if(head==NULL)
            return;
        
        if(index<0)
            return ;
        else{
            while(current!=NULL)
            {
                count++;
                current=current->next;
            
            }
            current=head;
            if(index>=count)
                return ;
            else if(index==0)
            {
                head=head->next;
            }
            else{
                for(int i=0;i<index-1;++i)
                    current=current->next;
                temp=current->next;
                current->next=temp->next; 
                
                
            }
        }
        
        
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
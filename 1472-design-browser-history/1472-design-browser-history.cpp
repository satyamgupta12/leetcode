class BrowserHistory {
public:
 class Node{
      public:
      string ss;
      Node*next=NULL;
      Node*prev=NULL;
      
      Node(string val){
          ss=val;
      }
  };
    Node *head=NULL,*head1=NULL;
    string homepage;
    int counter=0;
    BrowserHistory(string homepage) {
        //this->homepage=homepage;
        Node* temp = new Node (homepage);
        head=temp;
        head1=temp;
        counter++;
    }
    
    
    void visit(string url) {
        Node* temp = new Node (url);
        head1->next=temp;
        temp->prev=head1;
        head1=head1->next;
    }
    
    string back(int steps) {
       while(head1->prev!=NULL && steps!=0){
        head1=head1->prev;
        steps--;
       } 
       return head1->ss;
    }
    
    string forward(int steps) {
        while(head1->next!=NULL && steps!=0){
            head1=head1->next;
            steps--;
        }
        return head1->ss;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
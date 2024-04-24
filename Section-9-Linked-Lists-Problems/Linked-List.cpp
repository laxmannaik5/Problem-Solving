#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            next = NULL;
        }
};

//-----------------Linked List------------------//

void insertAtHead(node* &head, int data){   //passing by refference
    if(head==NULL){
        head = new node(data);
        return;
    }
    //otherwise
    node* n = new node(data);
    n->next = head;
    head = n;
}

void insertInMiddle(node* &head, int data, int pos){
    if(pos==0){
        insertAtHead(head,data);
    }else{
        node* temp = head;
        for(int jump=1;jump<=pos-1;jump++){
            temp=temp->next;
        }
        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}
node* recReverse(node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node* sHead = recReverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return sHead;
}

void reverse(node* &head){
    node* prev = NULL;
    node* current = head;
    node* temp;
    while(current!=NULL){
        //store next
        temp = current->next;
        //update the current
        current->next=prev;
        //prev and current
        prev = current;
        current=temp;
    }
    head=prev;
    return;
}

node* kReverse(node* head, int k){
    if(head==NULL){
        return NULL;
    }
    node* prev = NULL;
    node* current = head;
    node* temp;
    int cnt=1;
    while(current!=NULL and cnt<=k){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
        cnt++;
    }
    if(temp!=NULL){
        head->next = kReverse(temp,k);
    }
    return prev;
}

node* merge(node* a, node* b){
    //base case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    //rec case
    node* c;
    if(a->data < b->data){
        c=a;
        c->next = merge(a->next,b);
    }else{
        c=b;
        c->next = merge(a,b->next);
    }
    return c;
}

void printLL(node* head){ //passing by value
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}

int main(){

    node* a = NULL;
    insertAtHead(a,10);
    insertAtHead(a,7);
    insertAtHead(a,5);
    insertAtHead(a,1);

    node* b = NULL;
    insertAtHead(b,6);
    insertAtHead(b,3);
    insertAtHead(b,2);

    node* head = merge(a,b);
    printLL(head);

    // node* head = NULL;

    // insertAtHead(head,4);
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,0);
    // //insertInMiddle(head,100,3);
    // printLL(head);
    // //head = recReverse(head);
    // //reverse(head);
    // head = kReverse(head,3);
    // printLL(head);

    return 0;
}
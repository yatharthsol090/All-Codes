#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node *takeinput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newnode = new Node(data);
        if(head ==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail=tail->next;            
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node * deleteEveryNNodes(Node * head, int m , int n){
    if(m==0)
    return NULL;
    else{
    int c1 = 1, c2 = 1;
    Node * t1 = head;
    while(t1!= NULL){
    while(c1!=m){
        if(t1==NULL)
        break;
        t1 = t1->next;
        c1++;
    }
    Node * t2 = t1->next;
    while(c2!=n){
        if(t2==NULL)
        break;
        t2 = t2->next;
        c2++;
    }
    if(t2==NULL){
        t1->next = NULL;
        t1 = t1->next;
    }
    else{
    t2 = t2->next;
    t1->next = t2;
    t1= t2;}
    c1 = 1;
    c2 = 1;
    }
    return head;
    }
}

int main(){
    Node *head = takeinput();
    int m,n;
    cin>>m>>n;
    Node * h = deleteEveryNNodes(head,m,n);
    print(h);
    
}
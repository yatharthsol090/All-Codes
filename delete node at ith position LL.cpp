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

Node * deleteAt(Node *head, int i){
    int c=0;
    Node *temp = head;
    if(i==0){
        head = head->next;
        return head;
    }
    while(temp !=NULL && c<i-1){
        temp = temp->next;
        c++;
    }
    if(temp!=NULL){
    Node * a = temp->next;
    Node * b = a->next;
    temp -> next = b;
    delete a;
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

int main(){
    Node *head = takeinput();
    print(head);
    int i;
    cin>>i;
    Node *h = deleteAt(head,i);
    print(h);
}
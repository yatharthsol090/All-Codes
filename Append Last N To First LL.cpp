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

int length(Node *head){
    Node *temp = head;
    if(temp->next==NULL){
        return 1;
    }
    temp = temp->next;
    return 1+ length(temp);
}
void print(Node *head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *appendLastn(Node *head, int n){
    int c = length(head)-n;
    int i=0;
    Node * temp = head;
    while(i<c-1){
        temp = temp ->next;
        i++;
    }
    Node *h2 = temp->next;
    Node *tail = h2;
    temp->next = NULL;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = head;
    return h2;
}

int main(){
    Node *head = takeinput();
    int n;
    cin>>n;
    Node *h = appendLastn(head, n);
    print(h);
}
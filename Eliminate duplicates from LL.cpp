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

Node * eliminateDups(Node *head){
    Node *t1 = head;
    Node *t2 = head->next;
    if(head==NULL || head->next ==NULL){
        return head;
    }
    while(t2 != NULL){
        if(t1->data != t2->data){
            t1->next = t2;
            t1 = t2;
            t2 = t2->next;
        }
        else
            t2 = t2->next;

    }
    t1->next = t2;
    return head;
}



int main(){
    Node *head = takeinput();
    Node *h = eliminateDups(head);
    print(h);
}

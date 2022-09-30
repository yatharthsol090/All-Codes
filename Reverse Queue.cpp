#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q){
    if(q.size()==0 || q.size()==1)
    return;
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main() {
    int c;
    cin>>c;
    int i=0;
    int data;
    queue<int> q;
    while(i<c){
            cin>>data;
            q.push(data);
            i++;
    }
    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

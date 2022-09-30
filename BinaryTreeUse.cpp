#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

class Pair{
    public:
int height;
bool isBalanced;
};

class Node{
public:
    int data;
    Node * next;
    Node(int data){
    this->data = data;
    this->next = NULL;
    }

};

BinaryTreeNode * takeInputLevelWise(){
int rootdata;
cout<<"Enter root data :"<<endl;
cin>>rootdata;
BinaryTreeNode * root = new BinaryTreeNode(rootdata);
queue<BinaryTreeNode *> q;
q.push(root);
while(!q.empty()){
    BinaryTreeNode * c1 = q.front();
    q.pop();


    cout<<"Enter left child of "<<c1->data<<endl;
    int leftChild;
    cin>>leftChild;
    if(leftChild!=-1){
    BinaryTreeNode *lChild = new BinaryTreeNode(leftChild);
    c1->left = lChild;
    q.push(lChild);}
    cout<<"Enter right child of "<<c1->data<<endl;
    int rightChild;
    cin>>rightChild;
    if(rightChild!=-1){
    BinaryTreeNode *rChild = new BinaryTreeNode(rightChild);
    c1->right = rChild;
    q.push(rChild);}


}
return root;


}

void printTreeLevelWise(BinaryTreeNode * root){
queue<BinaryTreeNode *> q;
q.push(root);

while(!q.empty()){
    BinaryTreeNode * c1 = q.front();
    cout<<c1->data<<":";
    q.pop();
    if(c1->left!=NULL){
        BinaryTreeNode * c1left = c1->left;
        cout<<"L"<<c1left->data;
        q.push(c1left);

    }
    if(c1->right!=NULL){
        BinaryTreeNode * c1right = c1->right;
        cout<<"R"<<c1right->data;
        q.push(c1right);

    }
    cout<<endl;
}

}


bool nodePresentOrNot(BinaryTreeNode * root, int x){
if(root==NULL){
    return false;
}
if(root->data == x){
    return true;
}
bool ans1,ans2;
ans1 = nodePresentOrNot(root->left,x);
ans2 = nodePresentOrNot(root->right,x);

return (ans1 || ans2);
}

int heightOfBT(BinaryTreeNode * root){
if(root==NULL)
    return 0;
int x, y;
 x = heightOfBT(root->left);
 y = heightOfBT(root->right);
 if(x>y)
    return 1+x;
 else
    return 1+y;

}

BinaryTreeNode * mirrorTree(BinaryTreeNode *root){
if(root==NULL)
    return NULL;
    BinaryTreeNode * rLeft = root->left;
root->left = mirrorTree(root->right);
root->right = mirrorTree(rLeft);
return root;
}

void preOrder(BinaryTreeNode * root){
if(root==NULL)
    return;
cout<<root->data<<" ";
preOrder(root->left);
preOrder(root->right);

}

void postOrder(BinaryTreeNode * root){
if(root==NULL){
    return ;
}
postOrder(root->left);
postOrder(root->right);
cout<<root->data<<" ";
}

BinaryTreeNode * constructTree(int pre[],int in[],int inS,int inE,int preS,int preE){
    if (inS > inE) {
		return NULL;
	}


int rootData = pre[preS];
int linS = inS;
int rootIndex = -1;
for(int i=inS; i<= inE ; i++){

    if(in[i]==rootData)
    {
        rootIndex = i;
        break;
    }
}

int linE = rootIndex - 1;
int lpreS = preS + 1;
int lpreE = linE + lpreS - linS;

int rinS = rootIndex + 1;
int rinE = inE;
int rpreS = lpreE + 1;
int rpreE = preE;

BinaryTreeNode * root = new BinaryTreeNode(rootData);
root->left = constructTree(pre,in,linS,linE,lpreS,lpreE);
root->right = constructTree(pre,in,rinS,rinE,rpreS,rpreE);
return root;
}

BinaryTreeNode * makeTreeWithPostIn(int post[],int in[],int postS, int postE, int inS, int inE){
    if(inS>inE)
        return NULL;


int rootData = post[postE];
int lpostS = postS;
int linS = inS;
int rootIndex = -1;
for(int i=inS;i<=inE;i++){

    if(in[i]==rootData)
    {
        rootIndex = i;
        break;
    }
}

int linE = rootIndex-1;
int lpostE = linE - linS + lpostS;

int rpostS = lpostE + 1;
int rpostE = postE - 1;
int rinS = rootIndex + 1;
int rinE = inE;

BinaryTreeNode * root = new BinaryTreeNode(rootData);
root->left = makeTreeWithPostIn(post,in,lpostS,lpostE,linS,linE);
root->right = makeTreeWithPostIn(post,in,rpostS,rpostE,rinS,rinE);
return root;
}


pair<int,int> minMaxNode(BinaryTreeNode * root){
if(root==NULL){
    pair<int,int> p;
    p.first = NULL;
    p.second = NULL;
    return p;

}
    pair<int,int> leftAns = minMaxNode(root->left);
    pair<int,int> rightAns = minMaxNode(root->right);
    pair<int,int> p;
    int temp1 = max(leftAns.first , rightAns.first);
    if(root->data > temp1)
        p.first = root->data;
    else
        p.first = temp1;

    int temp2;
    if(leftAns.second == NULL && rightAns.second == NULL){
        temp2 = root->data;
    }
    else if(leftAns.second == NULL)
        {
            temp2 = rightAns.second;
        }
    else if(rightAns.second == NULL)
        {
            temp2 = leftAns.second;
        }
    else
        {
            temp2 = min(leftAns.second,rightAns.second);
        }


if(root->data < temp2)
    p.second = root->data;
else
    p.second = temp2;

    return p;

}

int sumOfAllNodes(BinaryTreeNode * root){
if(root==NULL){
    return 0;
}
return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}

Pair checkBalancedTree(BinaryTreeNode * root){
if(root==NULL){
    Pair p;
    p.height = 0;
    p.isBalanced = true;
    return p;
}

Pair leftAns = checkBalancedTree(root->left);
Pair rightAns = checkBalancedTree(root->right);

Pair ans;
if(leftAns.isBalanced==false || rightAns.isBalanced==false){
    ans.isBalanced = false;
    ans.height = 1 + max(leftAns.height , rightAns.height);
}
else{
    if(abs(leftAns.height - rightAns.height)<=1){
        ans.isBalanced = true;
    }
    else
        ans.isBalanced = false;
    ans.height = 1 + max(leftAns.height , rightAns.height);
}
return ans;
}

void printLevelOrderTraersal(BinaryTreeNode * root){
if(root==NULL)
    return ;
queue<BinaryTreeNode *> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    BinaryTreeNode * c1 = q.front();
    q.pop();
    if(c1 == NULL){
            if(q.empty())
            break;
    cout<<endl;
    q.push(NULL);

    }
    else{
        cout<<c1->data<<" ";
        if(c1->left!=NULL)
            q.push(c1->left);
        if(c1->right!=NULL)
            q.push(c1->right);
    }

}

}

BinaryTreeNode * removeLeafNodes(BinaryTreeNode * root){
if(root==NULL){
    return NULL;
}
if(root->left==NULL && root->right==NULL){
    return NULL;
}
BinaryTreeNode * leftAns = removeLeafNodes(root->left);
BinaryTreeNode * rightAns = removeLeafNodes(root->right);
root->left = leftAns;
root->right = rightAns;
return root;
}


vector<Node *> levelWiseLinkedList(BinaryTreeNode * root){
    vector<Node *> output;
if(root==NULL)
    {
       output.push_back(NULL);
       return output;

    }
queue<BinaryTreeNode *> q;
q.push(root);
q.push(NULL);
Node * head = NULL;
Node * tail = NULL;
while(!q.empty()){
    BinaryTreeNode * c1 = q.front();
    q.pop();
    if(c1==NULL){
            if(q.empty())
            break;
    head = NULL;
    tail = NULL;
    q.push(NULL);
    }
    else{
        Node * newNode = new Node(c1->data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            output.push_back(head);
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        if(c1->left!=NULL){
            q.push(c1->left);
        }
        if(c1->right!=NULL)
            q.push(c1->right);

    }


}
return output;

}

void printLL(Node * head){
  Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void zigZagTree(BinaryTreeNode * root){
if(root==NULL)
    return;
stack<BinaryTreeNode *> s1;
stack<BinaryTreeNode *> s2;
s1.push(root);
while(s1.size()!=0){
while(!s1.empty()){
    BinaryTreeNode * c1 = s1.top();
    cout<<c1->data<<" ";
    if(c1->left != NULL)
        s2.push(c1->left);
    if(c1->right != NULL){
        s2.push(c1->right);
    }
    s1.pop();

}
cout<<endl;
while(!s2.empty()){
    BinaryTreeNode * c2 = s2.top();
    cout<<c2->data<<" ";
    if(c2->right != NULL){
        s1.push(c2->right);
    }
    if(c2->left != NULL)
    {
        s1.push(c2->left);
    }
     s2.pop();

}
cout<<endl;
}


}

void nodeWithoutSibling(BinaryTreeNode * root){
if(root==NULL)
    return ;
if(root!=NULL){
    if(root->left!=NULL && root->right==NULL)
        cout<<root->left->data<<endl;
    if(root->left==NULL && root->right!=NULL)
        cout<<root->right->data<<endl;
}

nodeWithoutSibling(root->left);
nodeWithoutSibling(root->right);

}

BinaryTreeNode * insertDupsLeft(BinaryTreeNode * root){
if(root==NULL)
    return NULL;
if(root->left!=NULL){
BinaryTreeNode * newNode = new BinaryTreeNode(root->data);
BinaryTreeNode * lc = root->left;
root->left = newNode;
newNode->left = lc;}
else{
    BinaryTreeNode * newNode = new BinaryTreeNode(root->data);
    root->left = newNode;
}

insertDupsLeft(root->left->left);
insertDupsLeft(root->right);
return root;

}

int k=0;
void convertToArr(BinaryTreeNode *root,int arr[]){
if(root==NULL)
    return ;
arr[k]=root->data;
k++;
convertToArr(root->left,arr);
convertToArr(root->right,arr);
}

void pairSum(BinaryTreeNode * root, int s){
if(root==NULL)
    return ;
int arr[1001];
convertToArr(root,arr);
sort(arr,arr+k);
int i=0,j=k-1;
while(i<j){
    if(arr[i]+arr[j]>s){
        j--;
    }
    else if(arr[i]+arr[j]<s)
    {
        i++;
    }
    else{
        cout<<arr[i]<<" "<<arr[j]<<endl;
        i++;
        j--;
    }


}

}

BinaryTreeNode * lcaOfBT(BinaryTreeNode * root,int n1,int n2){
if(root==NULL)
    return NULL;
if(root->data == n1 || root->data == n2)
    return root;

BinaryTreeNode * a = lcaOfBT(root->left,n1,n2);
BinaryTreeNode * b = lcaOfBT(root->right,n1,n2);

if(a!=NULL && b!=NULL)
    return root;
else if(a!=NULL && b==NULL)
    return a;
else if(a==NULL && b!=NULL)
    return b;
else
    return NULL;
}


int main() {
	BinaryTreeNode * root = takeInputLevelWise();
	/*int x;
	cin>>x;
	cout<<nodePresentOrNot(root,x);
	//printTreeLevelWise(root);

	printTreeLevelWise(root);
	BinaryTreeNode * r = mirrorTree(root);
	cout<<"After mirror tree is :"<<endl;
	printTreeLevelWise(r);
        preOrder(root);
        cout<<endl<<"Postorder printing is: "<<endl;
        postOrder(root);*/

  /*   int n;
     cin>>n;
     int pre[n],in[n];
     for(int i=0;i<n;i++){
        cin>>pre[i];
     }
     for(int i=0;i<n;i++){
        cin>>in[i];
     }

    BinaryTreeNode * r = constructTree(pre,in,0,n-1,0,n-1);
    printTreeLevelWise(r);


int n;
cin>>n;
int post[n],in[n];
for(int i=0;i<n;i++){
    cin>>post[i];
}
for(int i=0;i<n;i++){
    cin>>in[i];
}

BinaryTreeNode * root = makeTreeWithPostIn(post,in,0,n-1,0,n-1);
printTreeLevelWise(root);
*/
//pair<int,int> p = minMaxNode(root);
//cout<<p.first<<" "<<p.second<<endl;
//cout<<sumOfAllNodes(root);
//Pair ans = checkBalancedTree(root);
//cout<<ans.isBalanced<<endl;

//BinaryTreeNode * r = removeLeafNodes(root);
//printLevelOrderTraersal(r);
/*vector<Node *> v;
v = levelWiseLinkedList(root);
for(int i=0;i<v.size();i++){
    printLL(v[i]);
}*/

//zigZagTree(root);
//nodeWithoutSibling(root);
//BinaryTreeNode * r = insertDupsLeft(root);
//printLevelOrderTraersal(r);

/*int s;
cin>>s;

pairSum(root,s);*/

int n1,n2;
cin>>n1>>n2;
BinaryTreeNode * ans = lcaOfBT(root,n1,n2);
if(ans==NULL)
    cout<<-1<<endl;
else
cout<<ans->data<<endl;



}


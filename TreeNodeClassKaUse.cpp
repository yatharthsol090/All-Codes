#include<bits/stdc++.h>
#include "TreeNodeClass.h"
using namespace std;

class Pair{
    public:
TreeNodeClass * root;
int sum;
};

/*class Pair2{
    public:
TreeNodeClass * max1;
TreeNodeClass * smax1;

};*/


TreeNodeClass * takeInputFromLevel(){
int rootData;
cout<<"Enter Root DATA : "<<endl;
cin>>rootData;
TreeNodeClass * root = new TreeNodeClass(rootData);
queue<TreeNodeClass *> q;
q.push(root);
while(!q.empty()){
    TreeNodeClass * c1 = q.front();
    q.pop();
    int n;
    cout<<"Enter num of children of : "<<c1->data<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int childData;
        cout<<"Enter "<<i<<"th children data of "<<c1->data<<endl;
        cin>>childData;
        TreeNodeClass * child = new TreeNodeClass(childData);
        c1->children.push_back(child);
        q.push(child);
    }

}

return root;

}


TreeNodeClass * takeInput(){

int rootData;
cout<<"Enter data : "<<endl;
cin>>rootData;
TreeNodeClass * root = new TreeNodeClass(rootData);
int n;
cout<<"Enter the num of children : "<<endl;
cin>>n;
for(int i= 0;i<n;i++){
    TreeNodeClass *child = takeInput();
    root->children.push_back(child);

}

return root;
}


void print(TreeNodeClass * root){
cout<<root->data<<":";
for(int i= 0;i<root->children.size();i++){
    cout<<root->children[i]->data<<",";
}
cout<<endl;
for(int i = 0;i<root->children.size();i++)
{
    print(root->children[i]);

}

}


void printLevelWise(TreeNodeClass *root){
queue<TreeNodeClass *>q;
q.push(root);
while(!q.empty()){
    TreeNodeClass *c1 = q.front();
    cout<<c1->data<<":";
    q.pop();
    for(int i = 0;i<c1->children.size();i++){
        cout<<c1->children[i]->data<<",";
        q.push(c1->children[i]);

    }
    cout<<endl;

}

}

int sumOfNodes(TreeNodeClass *root){
int ans = root->data;
for(int i=0;i<root->children.size();i++){
    ans = ans + sumOfNodes(root->children[i]);
}
return ans;
}

TreeNodeClass * maxNodeFinder(TreeNodeClass *root){
TreeNodeClass * maxNode = root;
for(int i=0;i<root->children.size();i++){
    TreeNodeClass * small = maxNodeFinder(root->children[i]);
    if(maxNode->data < small->data)
        maxNode = small;

}
return maxNode;
}

int numOfNodes(TreeNodeClass * root){
int ans = 1;
for(int i = 0;i<root->children.size();i++)
{

    ans += numOfNodes(root->children[i]);
}
return ans;
}

int findHeight(TreeNodeClass * root){
int h = 0;
for(int i=0;i<root->children.size();i++){
    int x = findHeight(root->children[i]);
    if(h<x)
    {
        h = x;
    }
}
return h+1;
}

int totalLeafNodes(TreeNodeClass * root){
    if(root->children.size()== 0)
        return 1;
    int x = 0;
    for(int i=0;i<root->children.size();i++)
    {
        int y = totalLeafNodes(root->children[i]);
        x+=y;
    }
    return x;
}

void postOrder(TreeNodeClass * root){
for(int i=0;i<root->children.size();i++)
    postOrder(root->children[i]);
cout<<root->data<<" ";
}

bool xPresentOrNot(TreeNodeClass * root, int x){
queue<TreeNodeClass *> q;
q.push(root);
while(!q.empty()){
    TreeNodeClass * c1 = q.front();
    q.pop();

    if(c1->data == x)
        return true;
    for(int i=0;i<c1->children.size();i++)
    {

        q.push(c1->children[i]);
    }
}
return false;
}

int nodeGreaterThanX(TreeNodeClass *root,int x){
queue<TreeNodeClass *>q;
q.push(root);
int c =0;
while(!q.empty()){
    TreeNodeClass * c1 = q.front();
    q.pop();
    if(c1->data > x)
        c++;

    for(int i=0;i<c1->children.size();i++){
        q.push(c1->children[i]);
    }


}

return c;
}

TreeNodeClass * maxChildSum(TreeNodeClass * root){
TreeNodeClass * ans = root;
int sum = root->data;
for(int i=0;i<root->children.size();i++){
    sum += root->children[i]->data;
}
for(int i=0;i<root->children.size();i++){
    TreeNodeClass * x = maxChildSum(root->children[i]);
    int xsum = x->data;
    for(int i=0;i<x->children.size();i++){
        xsum += x->children[i]->data;
    }

    if(sum<xsum){
        ans = x;
        sum = xsum;
    }
}
return ans;
}


//maximum Child Sum Node using Pair class
Pair maximumChildSum(TreeNodeClass * root){
Pair ans;
int sum = root->data;
for(int i=0;i<root->children.size();i++){
    sum += root->children[i]->data;
}
ans.root = root;
ans.sum = sum;

for(int i=0;i<root->children.size();i++){
    Pair x = maximumChildSum(root->children[i]);
    if(x.sum > ans.sum){
        ans.sum = x.sum;
        ans.root = x.root;
    }
}

return ans;
}

bool identicalTwoTrees(TreeNodeClass *root1, TreeNodeClass *root2){
    if(root1==NULL || root2==NULL){
        return false;
    }
if(root1->data != root2->data)
    return false;
if(root1->data == root2->data ){
    if(root1->children.size() == root2->children.size()){
    if(root1->children.size()==0)
    return true;
    else{
    for(int i=0;i<root1->children.size();i++){
        if(root1->children[i]->data != root2->children[i]->data)
            return false;
    }
    return true;}
    }
    else
        return false;
}
bool ans;
for(int i=0;i<root1->children.size();i++){

    ans = identicalTwoTrees(root1->children[i],root2->children[i]);
}

return ans;
}

TreeNodeClass * nextLarger(TreeNodeClass *root, int x){
    if(root==NULL)
    return NULL;
TreeNodeClass * ans = NULL;
if(root->data > x){
    ans = root;
}

for(int i=0;i<root->children.size();i++){
    TreeNodeClass * temp = nextLarger(root->children[i],x);
     if(temp==NULL){
            continue;
        }
        else{
    if(ans == NULL)
        ans = temp;
    if(temp->data < ans->data){
        ans = temp;
    }}
}
return ans;
}

TreeNodeClass * replaceWithDepth(TreeNodeClass * root, int d){
root->data = d;
for(int i = 0;i<root->children.size();i++){
    replaceWithDepth(root->children[i],d+1);

}
return root;
}

/*Pair2 secondLargestElement(TreeNodeClass * root){
    if(root==NULL){
            Pair2 ans;
            ans.max1 = NULL;
            ans.smax1 = NULL;
    return ans;
       }
Pair2 ans;
ans.max1 = root;
ans.smax1 = NULL;


for(int i=0;i<root->children.size();i++){

    Pair2 temp = secondLargestElement(root->children[i]);
    if(ans.smax1==NULL && temp.smax1==NULL){
    if(ans.max1->data < temp.max1->data){
        int x = ans.max1->data;
        ans.max1->data = temp.max1->data;
        ans.smax1->data = ans.max1->data;
    }else{
        ans.smax1->data = temp.max1->data;
    }
    }else if(ans.smax1==NULL && temp.smax1!=NULL){
    if(ans.max1->data < temp.max1->data){
        int x = ans.max1->data;
        ans.max1->data = temp.max1->data;
        if(x>temp.smax1->data)
            ans.smax1->data = x;
        else
            ans.smax1->data = temp.smax1->data;
    }else{
        ans.smax1->data = temp.max1->data;
    }

    }
    else if(ans.smax1!=NULL && temp.smax1==NULL){
        if(ans.max1->data < temp.max1->data){
        int x = ans.max1->data;
        ans.max1->data = temp.max1->data;
        ans.smax1->data = x;
    }else{
        if(ans.smax1->data < temp.max1->data){
            ans.smax1->data = temp.max1->data;
        }
    }
    }else{
    if(ans.max1->data > temp.max1->data){
        if(ans.smax1->data < temp.max1->data)
            ans.smax1->data = temp.max1->data;
    }
    else{
        int x = ans.max1->data;
        ans.max1->data = temp.max1->data;
        ans.smax1->data = x;
    }



    }




}

return ans;

}*/

int main(){
/*TreeNodeClass * root = new TreeNodeClass(1);
TreeNodeClass * c1 = new TreeNodeClass(2);
TreeNodeClass *c2 = new TreeNodeClass(3);

root->children.push_back(c1);
root->children.push_back(c2);
*/
TreeNodeClass * root = takeInputFromLevel();
//TreeNodeClass * root2 = takeInputFromLevel();
//cout<<maxChildSum(root)->data;

//Pair ans = maximumChildSum(root);
//cout<<ans.root->data;
//Pair2 ans = secondLargestElement(root);
//cout<<ans.smax1->data;

}

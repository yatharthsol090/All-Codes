#include<iostream>
using namespace std;
int main(){

    int m,n;
    cin>>m>>n;
    //Creating 2d Array Dynamically
int ** p = new int * [m];
for(int i = 0;i<m;i++)
{
    p[i]  = new int[n];
    for(int j = 0;j<n;j++)
    {

        cin>>p[i][j];
    }
}

cout<<"Your Final 2d Array is :";
for(int i =0;i<m;i++)
{
    cout<<endl;
    for(int j = 0;j<n;j++)
    {

        cout<<p[i][j]<<" ";
    }
}

for(int i = 0;i<m;i++)
    delete [] p[i];

    delete [] p;

}

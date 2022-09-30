#include<iostream>
using namespace std;


int present(int a[],int size , int x){
if(size == 0)
    return -1;
if(a[0]==x)
    return 0;
int ans = present(a+1,size-1,x);
if(ans == -1)
    return -1;
else
    return (ans+1) ;

}

int main(){
int n;
cin>>n;
int * a = new int[n];
for(int i = 0;i<n;i++)
    cin>>a[i];
int x;
cin>>x;
cout<<present(a,n,x);
delete [] a;
}

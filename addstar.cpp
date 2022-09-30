#include <bits/stdc++.h>
using namespace std;

void addstar(char s[],int l){
if(s[l]=='\0')
return ;
addstar(s,l+1);
if(s[l]==s[l+1]){

    s[strlen(s)+1]='\0';
    for(int i = strlen(s)-1;i>=l+1;i--)
    s[i+1]=s[i];
    s[l+1]='*';
}


}

int main() {
    char s[1000];
    cin>>s;
    addstar(s,0);
    cout<<s;
    return 0;
}


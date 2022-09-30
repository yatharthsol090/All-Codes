#include <bits/stdc++.h>
using namespace std;

bool redundantBraces(string str){
stack<char> s;
int i=0, c=0;
while(i<str.length()){
    if(str[i]!=')'){
        s.push(str[i]);
        i++;
    }
    if(str[i]==')'){
        while(s.top()!='('){
            s.pop();
            c++;
        }
    if(c==0 || c==1)
    return true;
    if(c>0)
     {
         s.pop();
         i++;
     }
    }
    c=0;
}
return false;
}

int main() {
    string str;
    getline(cin,str);
    cout<<redundantBraces(str)<<endl;
}

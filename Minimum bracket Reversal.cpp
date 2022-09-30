#include <bits/stdc++.h>
using namespace std;

void minBracReverse(string str){
    stack<char> s;
    int c= 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='{')
        s.push(str[i]);
        if(str[i]=='}'){
            if(s.empty())
            s.push(str[i]);
            else if(!s.empty() && s.top()=='{')
            s.pop();
            else
            s.push(str[i]);
        }
    }
    while(!s.empty()){
                char c1 = s.top();
                s.pop();
                char c2 = s.top();
                s.pop();
                if(c1==c2)
                c++;
                else
                c = c+2;
    }
    cout<<c<<endl;
}

int main() {
   string str;
   cin>>str;
   if(str.length()%2 != 0)
   cout<<-1;
   else
   minBracReverse(str);
}

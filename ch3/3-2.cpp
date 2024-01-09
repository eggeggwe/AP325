#include <bits/stdc++.h>
using namespace std;
bool solve(string s){
    stack<int> a;
    for(int i=0;i<s.size();i++){
        int tmp;
        if(s[i]=='('){
            a.push(0);
        }else if(s[i]=='['){
            a.push(1);
        }else if(s[i]=='{'){
            a.push(2);
        }else if(s[i]=='}'){
            if(a.empty())return false;
            if(a.top()+3==5){
                a.pop();
            }else{
                return false;
            }
        }else if(s[i]==']'){
            if(a.empty())return false;
            if(a.top()+4==5){
                a.pop();
            }else{
                return false;
            }
        }else if(s[i]==')'){
            if(a.empty())return false;
            if(a.top()+5==5){
                a.pop();
            }else{
                return false;
            }
        }
    }
    return a.empty();
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    while(getline(cin,s)){
        if(solve(s)){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}
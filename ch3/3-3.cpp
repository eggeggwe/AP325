#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    stack<long long int> a;
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a.push(s[i]-'0');
        }else if(s[i]=='+'){
            a.push(-1);
        }else if(s[i]=='-'){
            a.push(-2);
        }else{
            if(s[i]=='*'){
                i++;
                long long int tmp=s[i]-'0';
                tmp*=a.top();
                a.pop();
                a.push(tmp);
            }else if(s[i]=='/'){
                i++;
                long long int tmp=s[i]-'0';
                tmp=a.top()/tmp;
                a.pop();
                a.push(tmp);
            }
        }
    }
    stack<long long int> b;
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
    while(b.size()>1){
        long long int tmp=b.top();
        b.pop();
        int tmp2=b.top();
        b.pop();
        if(tmp2==-1){
            tmp=tmp+b.top();
            b.pop();
            b.push(tmp);
        }else if(tmp2==-2){
            tmp=tmp-b.top();
            b.pop();
            b.push(tmp);
        }
    }
    cout<<b.top();
    return 0;
}
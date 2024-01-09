#include <bits/stdc++.h>
using namespace std;
long long int f();
long long int g();
long long int f(){
    string s;
    cin>>s;
    if(s[0]=='f'){
        return 2*f()-1;
    }else if(s[0]=='g'){
        return 2*g()-1;
    }else{
        stringstream ss;
        ss<<s;
        long long int a;
        ss>>a;
        return 2*a-1;
    }
}
long long int g(){
    string s1,s2;
    cin>>s1;
    long long int a,b;
    if(s1[0]=='f'){
        a=f();
    }else if(s1[0]=='g'){
        a=g();
    }else{
        stringstream ss;
        ss<<s1;
        ss>>a;
    }
    cin>>s2;
    if(s2[0]=='f'){
        b=f();
    }else if(s2[0]=='g'){
        b=g();
    }else{
        stringstream ss;
        ss<<s2;
        ss>>b;
    }
    return a+2*b-3;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    if(s[0]=='f'){
        cout<<f();
    }else{
        cout<<g();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int f();
long long int g();
long long int h();
long long int f(){
    string s;
    cin>>s;
    if(s[0]=='f'){
        return 2*f()-3;
    }else if(s[0]=='g'){
        return 2*g()-3;
    }else if(s[0]=='h'){
        return 2*h()-3;
    }else{
        stringstream ss;
        ss<<s;
        long long int a;
        ss>>a;
        return 2*a-3;
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
    }else if(s1[0]=='h'){
        a=h();
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
    }else if(s2[0]=='h'){
        b=h();
    }else{
        stringstream ss;
        ss<<s2;
        ss>>b;
    }
    return 2*a+b-7;
}
long long int h(){
    string s1,s2,s3;
    cin>>s1;
    long long int a,b,c;
    if(s1[0]=='f'){
        a=f();
    }else if(s1[0]=='g'){
        a=g();
    }else if(s1[0]=='h'){
        a=h();
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
    }else if(s2[0]=='h'){
        b=h();
    }else{
        stringstream ss;
        ss<<s2;
        ss>>b;
    }
    cin>>s3;
    if(s3[0]=='f'){
        c=f();
    }else if(s3[0]=='g'){
        c=g();
    }else if(s3[0]=='h'){
        c=h();
    }else{
        stringstream ss;
        ss<<s3;
        ss>>c;
    }
    return 3*a-2*b+c;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    if(s[0]=='f'){
        cout<<f();
    }else if(s[0]=='g'){
        cout<<g();
    }else{
        cout<<h();
    }
    return 0;
}
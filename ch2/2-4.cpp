#include <bits/stdc++.h>
using namespace std;
long long int exp(long long int x,long long int y,long long int p){
    if(y==1)return x;
    if(y%2==0){
        long long int tmp=exp(x,y/2,p);
        return (tmp*tmp)%p;
    }
    return (x*exp(x,y-1,p))%p;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    long long int x=0,y,p;
    cin>>s>>y>>p;
    for(int i=0;i<s.size();i++){
        x=(x*10+(s[i]-'0'))%p;
    }
    cout<<exp(x,y,p);
    return 0;
}
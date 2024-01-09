#include <bits/stdc++.h>
using namespace std;
long long int exp(long long int x,long long int y,long long int p){
    if(y==1)return x;
    if(y%2==0){
        long long int tmp=exp(x,y/2,p);
        return (tmp*tmp)%p;
    }else{
        return (x*exp(x,y-1,p))%p;
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int x,y,p;
    cin>>x>>y>>p;
    cout<<exp(x,y,p);
    return 0;
}
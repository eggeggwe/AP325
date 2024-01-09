#include <bits/stdc++.h>
using namespace std;
const long long int P=1e9+9;
pair<long long int,long long int> exp(long long int x,long long int y,long long int n){
    if(n==1)return make_pair(x,y);
    else if(n%2==0){
        pair<long long int,long long int> tmp=exp(x,y,n/2);
        long long int Tmp=((tmp.first*tmp.first)%P+(((tmp.second*tmp.second)%P)*2)%P)%P;
        long long int Tmp2=(2*(tmp.first*tmp.second)%P)%P;
        return make_pair(Tmp,Tmp2);
    }else{
        pair<long long int,long long int> tmp=exp(x,y,n-1);
        long long int Tmp=((x*tmp.first)%P+(((y*tmp.second)%P)*2)%P)%P;
        long long int Tmp2=((x*tmp.second)%P+(y*tmp.first)%P)%P;
        return make_pair(Tmp,Tmp2);
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int x,y,n;
    cin>>x>>y>>n;
    pair<long long int,long long int> tmp=exp(x%P,y%P,n);
    cout<<tmp.first<<" "<<tmp.second;
    return 0;
}
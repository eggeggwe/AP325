#include <bits/stdc++.h>
using namespace std;
long long int exp(long long int a,long long int b,long long int p){
    if(b==1)return a;
    if(b%2==0){
        long long int tmp=exp(a,b/2,p);
        return (tmp*tmp)%p;
    }else{
        return (a*exp(a,b-1,p))%p;
    }
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        int tmp;
        cin>>tmp;
        cout<<exp(tmp,p-2,p);
    }
    return 0;
}
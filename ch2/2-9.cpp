#include <bits/stdc++.h>
using namespace std;
int a[40];
unordered_map<int,long long int> record;
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
        cin>>a[i];
    }
    for(int i=1;i<(1<<(n/2));i++){
        long long int tmp=1;
        for(int j=0;j<n/2;j++){
            if(i&(1<<j)){
                tmp=(tmp*a[j])%p;
            }
        }
        record[tmp]++;
    }
    long long int answer=0;
    for(int i=0;i<(1<<(n-n/2));i++){
        long long int tmp=1;
        for(int j=0;j<n-n/2;j++){
            if(i&(1<<j)){
                tmp=(tmp*a[n/2+j])%p;
            }
        }
        answer+=record[exp(tmp,p-2,p)];
        if(tmp%p==1 && i!=0)answer++;
    }
    cout<<answer;
    return 0;
}
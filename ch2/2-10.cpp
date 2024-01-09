#include <bits/stdc++.h>
using namespace std;
long long int a[40];
set<long long int> record;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,p;
    long long int answer=0;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<(n/2));i++){
        long long int tmp=0;
        for(int j=0;j<n/2;j++){
            if(i&(1<<j)){
                tmp+=a[j];
            }
        }
        record.insert(tmp);
    }
    for(int i=0;i<(1<<(n-(n/2)));i++){
        long long int tmp=0;
        for(int j=0;j<n-(n/2);j++){
            if(i&(1<<j)){
                tmp+=a[n/2+j];
            }
        }
        if(tmp<=p)answer=max(answer,tmp+*(--record.upper_bound(p-tmp)));
    }
    cout<<answer;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[50010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>m>>n;
    cin.get();
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        bitset<30> test;
        test.reset();
        string A;
        getline(cin,A);
        for(int j=0;j<A.size();j++){
            if(!test[A[j]-'A']){
                a[i]+=(1<<A[j]-'A');
                test[A[j]-'A']=1;
            }
        }
    }
    sort(a,a+n);
    int answer=0;
    int k=(1<<m)-1;
    for(int i=0;i<n;i++){
        answer+=upper_bound(a+i,a+n,k-a[i])-lower_bound(a+i,a+n,k-a[i]);
    }
    cout<<answer;
    return 0;
}
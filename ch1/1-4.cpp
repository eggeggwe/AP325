#include <bits/stdc++.h>
using namespace std;
int a[50010];
long long int answer=0;
int n,k;
void dfs(int s,int e,int K){
    if(e-s<=1)return;
    if(K==k)return;
    long long int tmp=0;
    long long int Back=0;
    for(int i=e;i>=s+1;i--){
        tmp+=a[i];
        Back+=tmp;
    }
    int index;
    long long int value=1e14;
    long long int tmp2=0;
    long long int Pre=0;
    Back-=tmp;
    index=s+1;
    tmp-=a[s+1];
    tmp2+=a[s];
    Pre+=tmp2;
    value=abs(Back-Pre);
    for(int i=s+2;i<=e-1;i++){
        Back-=tmp;
        tmp-=a[i];
        tmp2+=a[i-1];
        Pre+=tmp2;
        if(value>abs(Back-Pre)){
            index=i;
            value=abs(Back-Pre);
        }
    }
    answer+=a[index];
    dfs(s,index-1,K+1);
    dfs(index+1,e,K+1);
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,n-1,0);
    cout<<answer;
    return 0;
}
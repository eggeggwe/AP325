#include <bits/stdc++.h>
using namespace std;
int n,d;
int a[100010];
bool test(int num){
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<num;i++){
        pq.push(0);
    }
    for(int i=0;i<n;i++){
        int tmp=pq.top();
        pq.pop();
        tmp+=a[i];
        if(tmp>d)return false;
        pq.push(tmp);
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=-1,r=100010;
    while(l+1<r){
        int mid=l+(r-l)/2;
        if(test(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r;
    return 0;
}
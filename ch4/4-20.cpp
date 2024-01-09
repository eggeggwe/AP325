#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
bool cmp(pair<int,int> A,pair<int,int> B){
    if(A.second!=B.second)return A.second>B.second;
    return A.first<B.first;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,cmp);
    if(a[0].second<y){
        cout<<-1;
        return 0;
    }
    int answer=0;
    int r,l;
    r=1e9;
    l=y;
    for(int i=0;i<n;i++){
        if(a[i].second<x)break;
        if(a[i].second<l){
            if(a[i].second<r){
                cout<<-1;
                return 0;
            }
            answer++;
            l=r;
        }
        r=min(r,a[i].first);   
    }
    if(r<=x)cout<<answer+(l>x);
    else cout<<-1;
    return 0;
}
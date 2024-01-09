#include <bits/stdc++.h>
using namespace std;
map<int,int> Index;
int a[100010];
int b[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    int j=0;
    Index[a[0]]=0;
    int tmp=a[0];
    j++;
    for(int i=1;i<n;i++){
        if(a[i]!=tmp){
            tmp=a[i];
            Index[a[i]]=j;
            j++;
        }
    }
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<Index[b[i]];
    }
    return 0;
}
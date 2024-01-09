#include <bits/stdc++.h>
using namespace std;
int a[200010];
unordered_map<int,bool> test;
unordered_map<int,int> use;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int color=0;
    for(int i=0;i<n;i++){
        if(test[a[i]]==0){
            color++;
            test[a[i]]=1;
        }
    }
    int i=0,j=0;
    int answer=200010;
    int tmp=0;
    while(i<n && j<n){
        if(tmp<color){
            if(use[a[j]]==0){
                tmp++;   
            }
            use[a[j]]++;
            j++;
        }else{
            answer=min(answer,j-i);
            if(use[a[i]]==1){
                tmp--;
            }
            use[a[i]]--;
            i++;
        }
    }
    cout<<answer;
    return 0;
}
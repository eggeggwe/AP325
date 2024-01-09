#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> use;
int a[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int j=0;
    int tmp=0;
    int twice=0;
    int answer=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(use[a[i]]==0){
            tmp++;
            use[a[i]]++;
        }else if(use[a[i]]==1){
            twice++;
            use[a[i]]++;
        }
        if(twice==0){
            answer=max(answer,i-j+1);
        }
        while(twice>0){
            if(use[a[j]]==2){
                twice--;
            }
            use[a[j]]--;
            j++;
        }
    }
    cout<<answer;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[100010];
vector<int> answer;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    answer.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(answer.back()!=a[i]){
            answer.push_back(a[i]);
        }
    }
    cout<<answer.size()<<'\n';
    for(int i=0;i<answer.size();i++){
        if(i)cout<<" ";
        cout<<answer[i];
    }
    return 0;
}
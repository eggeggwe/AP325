#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    priority_queue<long long int,vector<long long int>,greater<long long int> > a;
    for(int i=0;i<m;i++){
        a.push(0);
    }
    long long int answer=0;
    for(int i=0;i<n;i++){
        long long int tmp=a.top();
        a.pop();
        long long int tmp2;
        cin>>tmp2;
        tmp+=tmp2;
        a.push(tmp);
    }
    while(a.size()>0){
        answer=max(answer,a.top());
        a.pop();
    }
    cout<<answer;
    return 0;
}
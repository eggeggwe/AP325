#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    priority_queue<int> a,b;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        b.push(tmp);
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push(tmp);
    }
    long long int answer=0;
    for(int i=0;i<n;i++){
        int tmp=a.top();
        a.pop();
        while(!b.empty() && b.top()>=tmp){
            b.pop();
        }
        if(!b.empty() && b.top()<tmp){
            answer++;
            b.pop();
        }
    }
    cout<<answer;
    return 0;
}
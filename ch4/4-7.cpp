#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    priority_queue<long long int,vector<long long int>,greater<long long int> > a;
    int n;
    cin>>n;
    long long int sum=0;
    long long int answer=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push(tmp);
        sum+=tmp;
    }
    while(a.size()>1){
        long long int tmp=a.top();
        a.pop();
        long long int tmp2=a.top();
        a.pop();
        answer+=tmp+tmp2;
        a.push(tmp+tmp2);
    }
    cout<<sum<<'\n'<<answer;
    return 0;
}
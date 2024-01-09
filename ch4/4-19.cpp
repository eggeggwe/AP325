#include <bits/stdc++.h>
using namespace std;
tuple<int,int,int> a[100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp,tmp2,tmp3;
        cin>>tmp>>tmp2>>tmp3;
        a[i]=tie(tmp2,tmp3,tmp);
    }
    sort(a,a+n);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > use;
    int tmp=0;
    int answer=0;
    for(int i=0;i<n;i++){
        while(!use.empty() && use.top().first<get<0>(a[i])){
            tmp-=use.top().second;
            use.pop();
        }
        tmp+=get<2>(a[i]);
        use.push(make_pair(get<1>(a[i]),get<2>(a[i])));
        answer=max(answer,tmp);
    }
    cout<<answer;
    return 0;
}
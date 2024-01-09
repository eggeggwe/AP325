#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    multimap<long long int,long long int> use;
    use.insert(make_pair(a[0].second,a[0].first));
    long long int L1=1e9;
    for(int i=1;i<n;i++){
        pair<long long int,long long int> b=a[i];
        auto it=use.lower_bound(b.second-L1);
        while((*it).first<b.second+L1 && it!=use.end()){
            pair<int,int> tmp=*it;
            if(tmp.second<=b.first-L1){
                it=use.erase(it);
                continue;
            }
            L1=min(L1,abs(b.first-tmp.second)+abs(b.second-tmp.first));
            it++;
        }
        use.insert(make_pair(a[i].second,a[i].first));
    }
    cout<<L1;
    return 0;
}
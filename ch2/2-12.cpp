#include <bits/stdc++.h>
using namespace std;
/*
long long int a[60][300010];
long long int Pre[60][300010];
*/
vector<long long int> a[60],Pre[60];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    long long int k;
    cin>>k;
    int n,m;
    cin>>m>>n;
    for(int i=0;i<=n;i++){
        Pre[0].push_back(0);
        a[0].push_back(0);
    }
    for(int i=1;i<=m;i++){
        Pre[i].push_back(0);
        a[i].push_back(0);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            long long int tmp;
            cin>>tmp;
            a[i].push_back(tmp);
            Pre[i].push_back(a[i][j]+Pre[i][j-1]+Pre[i-1][j]-Pre[i-1][j-1]);
        }
    }
    long long int answer=0;
    for(int i=0;i<=m;i++){
        for(int b=0;b<=i;b++){
            set<long long int> record;
            for(int j=0;j<=n;j++){
                record.insert(Pre[b][j]-Pre[i][j]);
                auto it=record.upper_bound(k-Pre[i][j]+Pre[b][j]);
                if(it!=record.begin()){
                    it=prev(it,1);
                    answer=max(answer,*it+Pre[i][j]-Pre[b][j]);
                }
            }
        }
    }
    cout<<answer;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int dis[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    stack<pair<int,int> > a;
    long long int answer=0;
    for(int i=1;i<=n;i++){
        int tmp;
        long long int sum=1;
        cin>>tmp;
        while(!a.empty()){
            if(a.top().first<=tmp){
                sum+=dis[a.top().second];
                a.pop();
            }else{
                break;
            }
        }
        a.push(make_pair(tmp,i));
        if(!a.empty())dis[i]=sum;
        else dis[i]=i;
        answer+=dis[i];
    }
    cout<<answer;
    return 0;
}
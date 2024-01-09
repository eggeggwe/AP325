#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100010];
int level[100010];
int in[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    queue<int> q;
    memset(level,0,sizeof(level));
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(t==0)q.push(i);
        in[i]=t;
        for(int j=0;j<t;j++){
            int tmp;
            cin>>tmp;
            graph[tmp].push_back(i);
        }
    }
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=0;i<graph[tmp].size();i++){
            in[graph[tmp][i]]--;
            if(level[tmp]+1>level[graph[tmp][i]]){
                
                level[graph[tmp][i]]=level[tmp]+1;
            }
            if(in[graph[tmp][i]]==0)q.push(graph[tmp][i]);
        }
    }
    long long int sum=0;
    int index=0;
    int Max=0;
    for(int i=1;i<=n;i++){
        if(level[i]>Max){
            Max=level[i];
            index=i;
        }
        sum+=level[i];
    }
    cout<<index<<'\n'<<sum;
    return 0;
}
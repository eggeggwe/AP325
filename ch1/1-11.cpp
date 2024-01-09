#include <bits/stdc++.h>
using namespace std;
int n,m;
bitset<20> graph[20];
int answer=100;
void cur(int r,int l,int u,int b,int sum){
    if(r>l)return;
    if(u>b)return;
    int one=0,zero=0;
    for(int i=r;i<=l;i++){
        if(graph[u][i]==1)one++;
        else zero++;
    }
    if(b-u>0)cur(r,l,u+1,b,sum+min(one,zero));
    else{
        answer=min(answer,sum);
    }
    one=0,zero=0;
    for(int i=r;i<=l;i++){
        if(graph[b][i]==1)one++;
        else zero++;
    }
    if(b-u>0)cur(r,l,u,b-1,sum+min(one,zero));
    else{
        answer=min(answer,sum);
    }
    one=0,zero=0;
    for(int i=u;i<=b;i++){
        if(graph[i][r]==1)one++;
        else zero++;
    }
    if(l-r>0)cur(r+1,l,u,b,sum+min(one,zero));
    else{
        answer=min(answer,sum);
    }
    one=0,zero=0;
    for(int i=u;i<=b;i++){
        if(graph[i][l]==1)one++;
        else zero++;
    }
    if(l-r>0)cur(r,l-1,u,b,sum+min(one,zero));
    else{
        answer=min(answer,sum);
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool tmp;
            cin>>tmp;
            graph[i][j]=tmp;
        }
    }
    cur(0,m-1,0,n-1,0);
    cout<<answer;
    return 0;
}
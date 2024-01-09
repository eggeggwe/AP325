#include <bits/stdc++.h>
using namespace std;
long long int a[200010];
long long int b[200010];
long long int sta[200110];
int in[200110];
int rear=200100;
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    long long int answer=0;
    for(long long int i=1;i<=n;i++){
        auto it=upper_bound(sta+rear,sta+200101,a[i]+b[i]);
        if(it!=sta+200101){
            answer+=i-in[it-sta]-1;
        }else{
            answer+=i-1;
        }
        while(rear<200100 && sta[rear+1]<a[i]){
            sta[rear+1]=0;
            in[rear+1]=0;
            rear++;
        }
        sta[rear]=a[i];
        in[rear--]=i;
    }
    cout<<answer;
    return 0;
}
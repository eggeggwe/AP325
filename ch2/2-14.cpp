#include <bits/stdc++.h>
using namespace std;
long long int a[100010];
pair<long long int,int> b[100010];
long long int answer[100010];
long long int n,in,w;
void cur(int l,int r,int in,long long int w,int index){
    if(r-l==1){
        answer[l]=w;
        return;
    }
    while(b[index].second<=l || b[index].second>=r){
        index++;
        if(index==n)return;
    }
    long long int h=b[index].first;
    if((r-l)*h<=w){
        for(int i=l;i<r;i++){
            answer[i]=w/(r-l);
        }
        return;
    }
    if(b[index].second>in){
        if((b[index].second-l)*h<w){
            for(int i=l;i<b[index].second;i++){
                answer[i]=h;
            }
            cur(b[index].second,r,b[index].second,w-(b[index].second-l)*h,index);
        }else{
            cur(l,b[index].second,in,w,index);
        }
    }else{
        if((r-b[index].second)*h<w){
            for(int i=b[index].second;i<r;i++){
                answer[i]=h;
            }
            cur(l,b[index].second,b[index].second-1,w-(r-b[index].second)*h,index);
        }else{
            cur(b[index].second,r,in,w,index);
        }
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(answer,0,sizeof(answer));   
    cin>>n>>in>>w;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i].first=a[i];
        b[i].second=i;
    }
    sort(b,b+n);
    reverse(b,b+n);
    cur(0,n-1,in,w,0);
    for(int i=0;i<n-1;i++){
        if(i)cout<<" ";
        cout<<answer[i];
    }
    return 0;
}
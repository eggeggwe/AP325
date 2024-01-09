#include <bits/stdc++.h>
using namespace std;
long long int Pre[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    long long int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        long long int tmp;
        cin>>tmp;
        Pre[i]=Pre[i-1]+tmp;
    }
    long long int Max=0;
    long long int num=0;
    int i=n,j=n;//i rear,j head
    while(i>=0 && j>=0){
        if(Pre[i]-Pre[j]<=k){
            if(Pre[i]-Pre[j]>Max){
                Max=Pre[i]-Pre[j];
                num=1;
            }else if(Pre[i]-Pre[j]==Max){
                num++;
            }
            j--;
        }else{
            while(Pre[i]-Pre[j]>k){
                i--;
            }
        }
    }
    cout<<Max<<'\n'<<num;
    return 0;
}
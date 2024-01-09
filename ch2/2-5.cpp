#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int> > muilt(vector<vector<long long int> > a,vector<vector<long long int> > b){
    vector<vector<long long int> > answer;
    for(int i=0;i<a.size();i++){
        vector<long long int> tmp;
        for(int j=0;j<b[i].size();j++){
            long long int tmp2=0;
            for(int k=0;k<a[i].size();k++){
                tmp2+=(a[i][k]*b[k][j])%1000000007;
            }
            tmp.push_back(tmp2);
        }
        answer.push_back(tmp);
    }
    return answer;
}
vector<vector<long long int> > exp(vector<vector<long long int> > a,long long int b,long long int p){
    if(b==1) return a;
    if(b%2==0){
        vector<vector<long long int> > A;
        A=exp(a,b/2,p);
        return muilt(A,A);
    }else{
        return muilt(a,exp(a,b-1,p));
    }
}
void solve(int n){
    vector<vector<long long int> > a;
    for(int i=0;i<2;i++){
        vector<long long int> tmp;
        for(int j=0;j<2;j++){
            tmp.push_back(1);
        }
        if(i==0)tmp[0]=0;
        a.push_back(tmp);
    }
    vector<vector<long long int> > tmp=exp(a,n-1,1000000007);
    cout<<(tmp[0][0]+tmp[0][1])%1000000007<<'\n';
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n){
        if(n==-1)break;
        solve(n);
    }
    return 0;
}
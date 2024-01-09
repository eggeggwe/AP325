#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> a[100010];
vector<pair<long long int,long long int> >A;//a1,b2,x
vector<pair<long long int,long long int> >B;
long long int b[50010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    a[n].first=1e9;
    a[n].second=1e9;
    sort(b,b+m);
    for(int i=0;i<n;i++){
        if(a[i].first!=a[i+1].first){
            A.push_back(a[i]);
        }
    }
    if(A.size()>=3){
        B.push_back(A[0]);
        B.push_back(A[1]);
        for(int i=2;i<A.size();i++){
            while(B.size()>=2){
                double a1=A[i].first,b1=A[i].second;
                double a2=B.back().first,b2=B.back().second;
                double a3=B[B.size()-2].first,b3=B[B.size()-2].second;
                if((b2-b1)/(a1-a2) < (b3-b1)/(a1-a3))B.pop_back();
                else break;
            }
            B.push_back(A[i]);
        }
    }else{
        B=A;
    }
    int j=0;
    long long int answer=0;
    for(int i=0;i<m;i++){
        while(j<B.size()-1 && B[j].first*b[i]+B[j].second<=B[j+1].first*b[i]+B[j+1].second){
            j++;
        }
        answer+=B[j].first*b[i]+B[j].second;
    }
    cout<<answer;
    return 0;
}
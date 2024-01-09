#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long int answer=0;
int i=0;
void dfs(int a){
    if(s[i]=='1'){
        answer+=a*a;
        i++;
        return;
    }
    if(s[i]=='0'){
        i++;
        return;
    }
    if(s[i]=='2'){
        i++;
        for(int j=0;j<4;j++){
            dfs(a/2);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    getline(cin,s);
    cin>>n;
    dfs(n);
    cout<<answer;
    return 0;
}
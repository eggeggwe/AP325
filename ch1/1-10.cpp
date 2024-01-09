#include <bits/stdc++.h>
using namespace std;
long long int graph[20][20];
bitset<20> record[20];
int n;
bitset<20> col;
long long int answer=0;
bool test(int row,int col){
    int i=row-1,j=col-1;
    while(i>=0 && j>=0){
        if(record[i][j])return false;
        i--;
        j--;
    }
    i=row+1,j=col-1;
    while(i<n && j>=0){
        if(record[i][j])return false;
        i++;
        j--;
    }
    i=row-1,j=col+1;
    while(i>=0 && j<n){
        if(record[i][j])return false;
        i--;
        j++;
    }
    i=row+1,j=col+1;
    while(i<n && j<n){
        if(record[i][j])return false;
        i++;
        j++;
    }
    return true;
}
void cur(int row,long long int sum){
    answer=max(answer,sum);
    if(row==n){
        return;
    }
    bool door=true;
    for(int i=0;i<n;i++){
        if(col[i] || !test(row,i)){
            if(door)cur(row+1,sum);
            door=false;
            continue;
        }
        record[row][i]=1;
        col[i]=1;
        if(sum+graph[row][i]>=sum)cur(row+1,sum+graph[row][i]);
        record[row][i]=0;
        col[i]=0;
    }
    return;
}
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    col.reset();
    record->reset();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cur(0,0);
    cout<<answer;
    return 0;
}
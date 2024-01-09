#include <bits/stdc++.h>
using namespace std;
pair<int,int> x[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>x[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>x[i].second;
    }
    sort(x,x+n);
    int i=0,j=0;
    deque<int> Max,Min;
    Max.push_back(x[i].second);
    Min.push_back(x[i].second);
    i++;
    int answer=0;
    while(i<n && j<n){
        while(!Max.empty() && Max.back()<x[i].second){
            Max.pop_back();
        }
        Max.push_back(x[i].second);
        while(!Min.empty() && Min.back()>x[i].second){
            Min.pop_back();
        }
        Min.push_back(x[i].second);
        while(x[i].first-x[j].first>l){
            if(!Max.empty() && Max.front()==x[j].second){
                Max.pop_front();
            }
            if(!Min.empty() && Min.front()==x[j].second){
                Min.pop_front();
            }
            j++;
        }
        if(i!=j)answer=max(answer,Max.front()-Min.front());
        i++;
    }
    cout<<answer;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int a[200010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deque<long long int> Max,Min;
    long long int answer=0;
    Max.push_back(a[0]);
    Min.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(i>=l){
            if(!Max.empty() && Max.front()==a[i-l]){
                //cerr<<"Max:"<<Max.front()<<endl;
                Max.pop_front();
            }
            if(!Min.empty() && Min.front()==a[i-l]){
                //cerr<<"Min:"<<Min.front()<<endl;
                Min.pop_front();
            }
        }
        while(!Max.empty() && Max.back()<a[i]){
            //cerr<<"Max:"<<Max.back()<<endl;
            Max.pop_back();
        }
        Max.push_back(a[i]);
        while(!Min.empty() && Min.back()>a[i]){
            //cerr<<"Min:"<<Min.back()<<endl;
            Min.pop_back();
        }
        Min.push_back(a[i]);
        answer=max(answer,Max.front()-Min.front());
    }
    cout<<answer;
    return 0;
}
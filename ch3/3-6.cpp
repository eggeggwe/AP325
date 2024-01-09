#include <bits/stdc++.h>
using namespace std;
int a[100010];
long long int b[100010];
int main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    long long int l;
    cin>>n>>l;
    stack<pair<long long int,long long int> > c;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int cnt=0;
    long long int height=0;
    for(int i=0;i<n;i++){
        if(c.empty()){
            if(a[i]-b[i]>=0){
                cnt++;
                height=max(height,b[i]);
                //cerr<<1<<" "<<a[i]<<endl;
            }else{
                c.push(make_pair(a[i],b[i]));
            }
        }else if(!c.empty()){
            if(a[i]-b[i]>=c.top().first){
                cnt++;
                height=max(height,b[i]);
                //cerr<<2<<" "<<a[i]<<endl;
            }else{
                bool door=true;
                if(c.top().first+c.top().second>a[i]){
                    c.push(make_pair(a[i],b[i]));
                    door=false;
                }
                
                while(c.top().first+c.top().second<=a[i]){
                    cnt++;
                    height=max(height,c.top().second);
                    //cerr<<3<<" "<<c.top().first<<endl;
                    c.pop();
                    if(c.empty()){
                        if(a[i]-b[i]>=0){
                            cnt++;
                            height=max(height,b[i]);
                            door=false;
                            //cerr<<4<<" "<<a[i]<<endl;
                            break;
                        }else{
                            c.push(make_pair(a[i],b[i]));
                            door=false;
                            break;
                        }
                    }
                    if(a[i]-b[i]>=c.top().first){
                        cnt++;
                        height=max(height,b[i]);
                        door=false;
                        //cerr<<5<<" "<<a[i]<<endl;
                        break;
                    }
                }
                if(door){
                    c.push(make_pair(a[i],b[i]));
                }
            }
        }
    }
    while(!c.empty()){
        if(c.top().first+c.top().second<=l){
            cnt++;
            height=max(height,c.top().second);
            //cerr<<6<<" "<<c.top().first<<endl;
            c.pop();
        }else{
            break;
        }
    }
    cout<<cnt<<"\n"<<height;
    return 0;
}
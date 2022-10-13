#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int d;
    cin>>d;
    int cnt=0;
    string s,t;
    cin>>s;
    t=s;
    sort(t.begin(),t.end());
 for(int i=0;i<s.length();i++){
     if(s[i]!=t[i]){
         cnt++;
     }
 }
 cout<<cnt<<endl;
}
    return 0;
}
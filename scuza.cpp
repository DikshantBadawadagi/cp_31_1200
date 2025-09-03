#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,q;
        cin>>n>>q;
        vector<long long>a(n);
        vector<long long>inc;
        for(long long i=0;i<n;i++){
            cin>>a[i];
            if(i == 0)inc.push_back(a[i]);
            else{
                if(a[i] <= inc.back())inc.push_back(inc.back());
                else inc.push_back(a[i]);
            }
        }
        vector<long long>prefix(n,0);
        for(long long i=0;i<n;i++){
            prefix[i] = a[i];
            if(i>0) prefix[i] += prefix[i-1];
        }
        for(long long i=0;i<q;i++){
            long long quer;
            cin>>quer;
            long long ind = upper_bound(inc.begin(),inc.end(),quer) - inc.begin();
            if(ind == 0)cout<<0<<" ";
            else cout<<prefix[ind-1]<<" ";
        }
        cout<<endl;
    }
}
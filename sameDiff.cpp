#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long  n;
        cin>>n;
        vector<long long>a(n);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        unordered_map<long long,long long>mpp;
        for(long long i=0;i<n;i++){
            mpp[a[i] - i + 1]++;
        }
        long long ans = 0;
        for(long long i=n-1;i>=0;i--){
            long long diff  = a[i] - i + 1;
            mpp[diff]--;
            ans+=mpp[diff];
        }
        cout<<ans<<endl;
    }
}
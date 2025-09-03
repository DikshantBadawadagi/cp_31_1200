#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>>arr(m, vector<long long>(n));
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                cin>>arr[j][i];
            }
        }
        for(auto &it :arr){
            sort(it.begin(), it.end());
        }
        long long ans = 0;
        //i, n-i-1
        for(auto &row : arr){
            for(long long i = 0; i < n; i++){
                ans += row[i] * i;
                ans -= row[i] * (n - i - 1);
            }
        }
        cout<<ans<<endl;
    }
}
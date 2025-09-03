#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int curr_min = 1,curr_max = n;
        int l =0,r=n-1;
        bool flag = false;

        while(l != r){
            if(arr[l] == curr_min){
                curr_min++;
                l++;
            }
            else if(arr[r] == curr_max){
                curr_max--;
                r--;
            }
            else if(arr[l] == curr_max){
                curr_max--;
                l++;
            }
            else if(arr[r] == curr_min){
                curr_min++;
                r--;
            }
            else{
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<l + 1<<" "<<r + 1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
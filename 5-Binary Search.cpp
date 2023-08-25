/*
  180 Daraga Training
  Session No : 5
  Session : Binary Search
  By : Ahmed Gamal
  On : 25/08/2023
*/
#include <bits/stdc++.h>

using namespace std;

int n, k, uHave[1003], uNeed[1003];


bool isOk(int x){ /// O(n)
    int tempK = k;
    for(int i=0;i<n;i++){
        if(uNeed[i]*x > uHave[i]){
            int diff = uNeed[i]*x - uHave[i];
            if (tempK < diff){
                return false;
            }else{
                tempK-=diff;
            }
        }
    }
    return true;
}

int main()
{
    cin>>n>>k;

    for(int i=0; i<n; ++i){
        cin>>uHave[i];
    }
    for(int i=0; i<n; ++i){
        cin>>uNeed[i];
    }
    /// Binary Search >> O(nlogn)
    int l=0, h=2e6+10;
    while(l<h){
        int mid = (l+h+1)/2; /// go near h
        //int mid = (l+h)/2; /// go near l
        if(isOk(mid))l=mid;
        else h=mid-1;
    }

    cout<<l;
    return 0;
}

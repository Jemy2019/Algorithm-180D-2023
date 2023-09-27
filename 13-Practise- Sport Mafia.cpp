/*
  180 Daraga Training
  Session No : 13
  Session : 180D-Practice
        B. Sport Mafia
    https://codeforces.com/problemset/problem/1195/B
  By : Ahmed Gamal
  On : 27/09/2023
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n, k, t;

ll haveFun(){
    ll l=0,h=n;
    while(l<=h){
        ll mid = (l+h)/2; /// mid => y
        ll ate = n - mid; /// ate => x
        ll sum = (mid * (mid + 1)) /2;

        if ((sum-ate) == k) return ate;
        if((sum-ate) > k) h = mid - 1;
        else l = mid + 1;
    }
    return 0;
}


int main()
{
    scanf("%lld%lld", &n, &k);
    cout<<haveFun()<<endl;
    return 0;
}
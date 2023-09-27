/*
  180 Daraga Training
  Session No : 13
  Session : 180D-Practice
        A. K-divisible Sum
    https://codeforces.com/problemset/problem/1476/A
  By : Ahmed Gamal
  On : 27/09/2023
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n, k, t;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        ll cf = (n + (k-1))/k;
        k *= cf;
        cout<<(k + (n-1))/n<<endl;
        /*
        if (n>=k){
            ///cout<<1<<endl;printf("1\n");
            if (n%k == 0) puts("1");
            else puts("2");
        } else {
            cout<<(k + (n-1))/n<<endl;
        }
        /// end comment
    }
    return 0;
}
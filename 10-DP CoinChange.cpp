/*
  180 Daraga Training
  Session No : 10
  Session : DP-ClassicalProblem-CoinChange
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include <bits/stdc++.h>

using namespace std;
const int N = (1<<20) , M = (1<<16), OO = 0x3f3f3f3f, MOD = 1e9+7;

int n;
int coins[] = {5, 10, 25, 50, 100};
int mem[5][N];

/// Combination
int CCC(int i=0, int rem=n){
    int &ret = mem[i][rem];
    ///BASECASE
    if (i==5) return rem == 0;
    if (~ret) return ret;
    /// OP1 >> take
    return ret = ((coins[i]<=rem)? CCC(i, rem - coins[i]): 0) + CCC(i+1, rem);
    /// OP2 >> leave
}

int dp[N];
int dpIt[N];
/// 0 >>> dp[0] = 0 >>>
/// 5 >>> dp[5] = 1 >>> 5
/// 10 >> dp[10] = 2 >>> 55 10
/// 15 >> dp[15] = 3 >>> 555 105 510
/// 20 >> dp[20] = 5 >>> 5555 5510 1055 1010 5105
/// 25 >> dp[25]

/// Permutation
int CCP(int rem=n){
    ///BASECASE
    if (rem == 0) return 1;
    if (rem < 0) return 0;
    int &ret = dp[rem];
    if (~ret) return ret;
    /// OP1 >> take
    int sum = 0;
    for(int i=0;i<5;i++){
        sum += CCP(rem-coins[i]);
    }
    return ret = sum;
}


int main()
{
    memset (mem, -1, sizeof mem);
    memset (dp, -1, sizeof dp);
    cin>>n;
    cout<<CCC()<<endl;
    cout<<CCP()<<endl;
    memset (dp, 0, sizeof dp);
    /// iterative
    dp[0]=1;
    for (int rem=1;rem<=n;rem++){

        for(int i=0;i<5;i++){

            if(coins[i]<= rem)
                dp[rem] += dp[rem - coins[i]]

        }
    }
    cout<<dpIt[n]<<endl;

    return 0;
}

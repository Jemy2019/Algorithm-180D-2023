/*
  180 Daraga Training
  Session No : 9
  Session : DP-ClassicalProblem-LIS
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include <bits/stdc++.h>
#define N (int)1e2+5
#define M (int)1e6+5

using namespace std;

const int OO = 0x3f3f3f3f;
int n, arr[N];
/// 0 <= Ai <= 1e6
/// 0 <= n <= 1e2
int mem[N][N];

int LIS(int i=0, int prev=n){ /// O(N*N)
    /// prev + 1 >> shifting index
    int &ret = mem[i][prev];
    /// BaseCase
    if (i==n) return 0;
    if (~ret)return ret;
    /// 10 5e5 6 2 4 3 >> 10 ..
    /// OP1: take
    int op1 = -OO;
    if (arr[i]>arr[prev])op1= LIS(i+1, i) + 1;
    /// OP2: leave
    int op2 = LIS(i+1, prev);

    return ret = max(op1, op2);
}

int main()
{
    memset(mem, -1, sizeof mem);
    cin>>n;
    //arr[n]=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<LIS();
    return 0;
}

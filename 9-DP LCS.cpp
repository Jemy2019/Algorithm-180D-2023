/*
  180 Daraga Training
  Session No : 9
  Session : DP-ClassicalProblem-LCS
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include <bits/stdc++.h>
#define N (int)1e2+5
#define M (int)1e6+5

using namespace std;

const int OO = 0x3f3f3f3f;
string s1,s2;
int n,m, arr[N];
/// 0 <= Ai <= 1e6
/// 0 <= n <= 1e2
int mem[N][N];

int LCS(int i=0, int j=0){
    int &ret = mem[i][j];
    /// BaseCase
    if (i==n || j==m) return 0;
    if (~ret)return ret;
    /// OP1: i == j >> i++ , j++
    if (s1[i] == s2[j]) ret = LCS(i+1, j+1) + 1;
    else ret = max(LCS(i+1, j), LCS(i, j+1));
    /// OP2: i != j >> i++
    /// OP3: i != j >> j++
    return ret;
}

int main()
{
    memset(mem, -1, sizeof mem);
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    cout<<LCS();
    return 0;
}

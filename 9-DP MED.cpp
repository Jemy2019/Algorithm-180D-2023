/*
  180 Daraga Training
  Session No : 9
  Session : DP-ClassicalProblem-MED
  By : Ahmed Gamal
  On : 27/09/2023
*/

#include <bits/stdc++.h>

using namespace std;
string s1,s2;
int n,m;
int mem[(int)1e2+1][(int)1e2+1];

int solve(int i=0, int j=0){
    int &ret = mem[i][j];
    /// baseCase
        if (i==n) return m-j;
        if (j==m) return n-i;
        if (~ret)return ret;
    /// OP1: ==
    if (s1[i]==s2[j]) return ret= solve(i+1, j+1);
    /// OP2, OP3 , OP4
    return ret = min(solve(i+1, j), min(solve(i, j+1), solve(i+1, j+1))) + 1;
}

int main()
{
    memset(mem, -1, sizeof mem);
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();
    cout<<solve()<<endl;
    return 0;
}

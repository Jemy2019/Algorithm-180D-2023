/*
  180 Daraga Training
  Session No : 13
  Session : 180D-Practice
        H.Merging Sorted Queues
    https://codeforces.com/group/gA8A93jony/contest/270592/problem/H
  By : Ahmed Gamal
  On : 27/09/2023
*/ 
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 15;
int n, m, A[N], B[N];
vector<int> v;
multiset<vector<int>> ans;

void haveFun(int i=0, int j=0){
    /// baseCase

    int take = 0;
    /// takeA
        if(v.empty() || (i < n && A[i]>v.back())){
            v.push_back(A[i]); /// do
            haveFun(i+1, j); ///recurse
            v.pop_back();/// undo
            take = 1;
        }
    /// takeB
        if(v.empty() || (j < m && B[j]>v.back())){
            v.push_back(B[j]);
            haveFun(i, j+1);
            v.pop_back();
            take = 1;
        }
    /// print
        if (!take){
            ans.insert(v);
        }
}

void printV(vector<int> ansV){
    int sz = ansV.size();
    for(int i=0; i<sz; i++){
        if (i==sz-1)printf("%d\n", ansV[i]);
        else printf("%d ", ansV[i]);
    }

    /*
    vector<int>::iterator itr1 = v.begin();
    //vector<int>::iterator itr2 = v.end();
    while(itr1 != v.end()){
        cout<<*itr1<<endl;
        itr1++;
    }
    */
}

void printAns(){
    for(auto vec: ans){
        printV(vec);
    }
}


int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", A+i);

    scanf("%d", &m);
    for(int i=0;i<m;i++)
        scanf("%d", B+i);

    haveFun();
    printAns();

    return 0;
}

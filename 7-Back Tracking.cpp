/*
  180 Daraga Training
  Session No : 7
  Session : Back Tracking
  By : Ahmed Gamal
  On : 17/09/2022
*/

#include <iostream>

using namespace std;

int n,m,ans=0;
char arr[25][25];

bool isValid(int r,int c){
    return (arr[r][c]!='#' && r<n && c<m);
}
///int f=0;
void backTrack(int r=0,int c=0){
   /// if(f==1)return;
    /// base condition | terminate recursion
        if(arr[r][c] == 'T'){
            ans++;
            ///f=1;
            return;
        }

    /// op1 (go right)
    if (isValid(r,c+1)){
        c++;/// do
        backTrack(r,c);/// recurse
        c--;/// undo
    }
    /// op2 (go down)
     if (isValid(r+1,c)){
        r++;/// do
        backTrack(r,c);/// recurse
        r--;/// undo
     }
}

bool isValid2(int i, int j) {
    return i<n && j<m && arr[i][j] != '#';
}

void backTrack2(int r=0, int c=0){
    /// base case
        if (arr[r][c]=='T')
            ans++;


    /// op1 (go right)
        //c++; /// do
        if(isValid2(r,c+1))backTrack2(r,c+1); /// recurse
        //--c; /// undo
    /// op2 (go down)
        //r++; /// do
        if(isValid2(r+1,c))backTrack2(r+1,c); /// recurse
        //r--; /// undo
}


int main()
{
    /// read input
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
    /// solve
        backTrack2();
    /// print ans
        cout<<ans<<endl;
    return 0;
}

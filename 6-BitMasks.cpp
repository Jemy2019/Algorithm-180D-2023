/*
  180 Daraga Training
  Session No : 6
  Session : Bitwise & Bitmasks
  By : Ahmed Gamal
  On : 28/08/2023
*/
#include <iostream>
#define ll long long
#define N (int)1e3
#define add(x,y) (x+y)
//#define isOn(x,k) (bool)((1<<(k))&(x))


using namespace std;

bool isOn(int x, int k) {
    return ((1<<k)&x);
}

int main()
{
    /// int x=7, y=3;
   // if (x && y){ /// logical and
           // 1 && 0 && 1 >> 0
   // cout << (x && y) << endl;
   //}
    /// bit wise AND
    //cout << (x & y) << endl;

     /// logical OR
           // 1 || 0 || 1 >> 1
  // cout << (x || y) << endl;

    /// bit wise OR
  //  cout << (x | y) << endl;

  /// logical not !
  // cout << !x << endl;

    /// bit wise ~ Telda
   // cout << ~x << endl;

     /// bit wise ^ XOR
   // cout << (x^y) << endl;

    /// bit wise << left shift
   // cout << (x<<y) << endl;

    /// bit wise << right shift
    //cout << (x>>y) << endl;
  

    int n = 4, arr[] = {4,2,5,7};
    int t;
    cin>>t;
    int flag = 0;
    for(int mask = 0; mask < (1<<n); mask++){
        int sum = 0;
        for(int k = 0; k < n; k++){
            if(isOn(mask, k)){
                sum+=arr[k];
            }
        }
        if (sum == t){
            flag = 1;
            break;
        }
    }
    if (flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

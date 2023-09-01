/*
  180 Daraga Training
  Session No : 7
  Session : Recursion
  By : Ahmed Gamal
  On : 17/09/2022
*/

#include <iostream>

using namespace std;

int fact(int n){
    /// terminate condition
    if(n==1 || n==0) return 1;
    /// recursive call
    return n * fact(n-1);
}
/*
int power1(int a, int p){
    /// terminate condition
    if(p==0) return 1;
    /// recursive call
    return a * power1(p-1);
}*/

int power2(int a, int p){
    /// terminate condition
    if(p==0) return 1;
    else if (p==1) return a;
    /// recursive call
    int ret = power2(a,p/2);
    if(p%2==0) return ret * ret;
    else return a*ret*ret;
}


int cnt=0;
int main()
{
    cout<<cnt++<<endl;
    main();
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}

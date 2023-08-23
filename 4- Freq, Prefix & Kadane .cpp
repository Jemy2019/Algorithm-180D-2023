/*
  180 Daraga Training
  Session No : 4
  Session : Greedy
  By : Ahmed Gamal
  On : 10/09/2022
*/
#include <iostream>

using namespace std;

int arr[101],n,q,frq[101],pre[101],kad[101];
int main()
{
    //fill(frq, frq+n, 3);///O(n)
    //memset(frq, 0, sizeof frq);///O(log n)

    cin>>n;
    for(int i =0;i<n;i++){
        cin>>arr[i];
        ///
        frq[arr[i]]++;
        /// PREFIX SUM
        if (i==0)pre[i]=arr[i];
        else pre[i] = arr[i] + pre[i-1];
        /// Kadane
        if (i==0)kad[i]=arr[i];
        else kad[i] = arr[i] + kad[i-1];
        if(kad[i]<0)
            kad[i]=0;

    }
    cin>>q;
    int l, r;
    while(q--){
        cin>>l>>r;
        if (l==0) cout<<pre[r];
        else cout<<pre[r]-pre[l-1];
    }


    return 0;
}

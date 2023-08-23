/*
  180 Daraga Training
  Session No : 4
  Session : Counting Sort
  By : Ahmed Gamal
  On : 8/09/2022
*/

#include <iostream>

using namespace std;

int arr[101], frq[101], B[101],n, mx;

void printArray(){
    cout<<"Array values: ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/// O(n)
void countSort(){
    for(int i=1;i<=n;i++){ ///O(n)
        ///  arr: 1 5 2 0 2 3 3 3  arr[i]
        ///  frq: 0->1 1->1 2->2 3->3 4->0 5->1 6->0
        frq[arr[i]]++;
    }

    for(int i=1;i<=mx;i++){ ///O(n)
        /// i:   0 1 2 3 4 5
        /// frq - prefix sum: 1 2 4 7 7 8
        frq[i] += frq[i-1];
    }

    for(int i=1; i<=n; i++){///O(n)
        /// inserting sorted in array B
        B[ frq[ arr[i] ]-- ] = arr[i];

    }

    for(int i=1; i<=n; i++){///O(n)
        arr[i] = B[i];
    }
}

int main()

{

    cin>>n;
    mx = -1;
    for(int i=1; i<=n; i++){ ///i >>  0,1,2,3,4
        cin>>arr[i];
        mx = max(arr[i],mx);
    }
    printArray();
    countSort();
    cout<<"After sort"<<endl;
    printArray();

    return 0;
}

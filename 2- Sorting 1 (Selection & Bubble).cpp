/*
  180 Daraga Training
  Session No : 2
  Session : Bubble & Selection
  By : Ahmed Gamal
  On : 15/8/2023
*/


#include <iostream>

using namespace std;

int n, arr[1001];

/// n = 7  , 2 =< n =< 10^3
/// arr = 2 5 8 3 4 9 1
void swapAB(int &a, int &b){
    int c = b;
    b = a;
    a = c;
}

void printArray(){
    cout<<"Array Values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selection() {
    /// arr = 2 3    4    5 8 9 10
    for(int j=0; j<n; j++){ /// j 0 1  O(n^2)
        int mn = arr[j], mnIdx = j; /// 2
        for(int i=j+1; i<n; i++){
            if(arr[i] < mn){
               mn = arr[i];
               mnIdx = i;
            }
        }
        //cout<<mn <<"   "<< mnIdx;
        swapAB(arr[mnIdx], arr[j]);
    }
}

void bubble(){
    /// n = 7
    /// arr = 2 5 8 3 4          n-2   1         n-1 9
    /// 1 2 5 7 8 10
    bool f = false;
    for(int j=0; j<n; j++){ ///O(n) ==> O(n^2)
        f = false;
        for(int i=0; i<n-1-j; i++){ ///O(n)
            if (arr[i]  > arr[i+1]){
                swapAB(arr[i], arr[i+1]);
                f = true;
            }
        }
        if(!f)break;
    }
}


int main()
{
/*
    int x=7 ,y=5;
    cout<<x<<" "<<y <<endl; /// 7  5
    swapAB(x,y);
    cout<<x<<" "<<y; /// 7  5  || 5  7

    int a = 10; /// a => 20 <= b
    int &b = a;  ///
    cout<< a <<" "<< b<<endl;
    a += 5;
    cout<< a <<" "<< b<<endl;
    b += 5;
    cout<< a <<" "<< b<<endl;
*/


    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    printArray();
    bubble();
    //selection();
    printArray();


    return 0;
}

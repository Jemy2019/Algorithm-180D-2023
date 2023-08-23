/*
  180 Daraga Training
  Session No : 3
  Session : Insertion sort
  By : Ahmed Gamal
  On : 8/09/2022
*/

#include <iostream>

using namespace std;

int arr[101], n;

void swapAB(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
  //  cout<< "inside Func" <<a<<" " <<b<<endl;
}

void printArray(){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void insertionSort()
{
        for(int i=1;i<n;i++){
            int temp = arr[i];
            int j=i-1;
            for(; j>=0; j--){
                if(temp < arr[j]){
                    arr[j+1] = arr[j];
                }else {
                    break;
                }
            }
            arr[j+1] = temp;
        }
}
/// O(n^2)
void insertionSort1(){
    ///0 0 1 2 4 4  5 << temp= 2
    for (int i=1; i<n; i++){ /// O(n)
        int temp = arr[i];
        int j;
        for (j=i-1; j>=0; j--){ /// O(n)
            if (arr[j] > temp){
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
/*
    int a=5, b=6;
    cout<<a<<" "<<b<<endl;
    swapAB(a,b);
    cout<<a<<" "<<b<<endl;
  */
  /// 5
  /// 1 4 9 3 8

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    printArray();
    insertionSort1();
    cout<<"After sort"<<endl;
    printArray();


    return 0;
}

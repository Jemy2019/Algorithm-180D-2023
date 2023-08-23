/*
  180 Daraga Training
  Session No : 3
  Session : Quick sort
  By : Ahmed Gamal
  On : 10/09/2022
*/

#include <iostream>

using namespace std;


void swapAB(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
  //  cout<< "inside Func" <<a<<" " <<b<<endl;
}

void printArray(int arr[], int n){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/// O(n)
int partition(int arr[], int i, int j){
    int pivot = arr[i];
    while(i<j){

        if(arr[i]>arr[j]){
            swapAB(arr[i],arr[j]);
        }

        if(pivot == arr[i])j--;
        else i++;
    }
    return i;
}

/// O(n*log(n))
void quickSort(int arr[], int l, int h){
    while(l<h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, h);
    }
}


int main()
{
    int arr[]={10,7,8,5,4,9,3},n=7;
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}

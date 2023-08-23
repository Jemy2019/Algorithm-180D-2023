/*
  180 Daraga Training
  Session No : 3
  Session : Merge sort
  By : Ahmed Gamal
  On : 10/09/2022
*/

#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/// O(n)
void merge(int arr[], int l, int mid, int h){
    int i = l;
    int endA = mid;
    int szA = mid-l+1;


    int j = mid+1;
    int endB = h;
    int szB = h-mid;   /// h-(mid+1)+1


    int C[szA+szB],k=0;

     while(i<=endA && j<szB){
        if(arr[i]<arr[j]){
            C[k++]=arr[i++];
            //k++;i++;
        } else {
            C[k++]=arr[j++];
        }
    }

    while(i<=endA){
        C[k++]=arr[i++];
    }

    while(j<=endB){
        C[k++]=arr[j++];
    }
   k=0;
   while(l<=h){
        arr[l++] = C[k++];
   }


}

/*
void merge(int A[], int szA, int B[], int szB){

    int C[szA+szB];
    int i,j,k;
    i=j=k=0;

    while(i<szA && j<szB){
        if(A[i]<B[j]){
            C[k++]=A[i++];
            //k++;i++;
        } else {
            C[k++]=B[j++];
        }
    }

    while(i<szA){
        C[k++]=A[i++];
    }

    while(j<szB){
        C[k++]=B[j++];
    }
    printArray(C, k);
}*/

/// O(n*log(n))
void mergeSort(int arr[], int l, int h){
    int mid = (l+h)/2;
    if(l<h){
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}


int main()
{

    int arr[]={10,7,8,5,4,9,3},n=7;
    //int A[]={3,7,10,11},B[]={5,7,9};
    //merge(A,4,B,3);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}

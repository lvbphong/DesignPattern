#include <bits/stdc++.h>
using namespace std;

void minAndMaxFunc(int arr[], int size, int* min, int* max){
    for(int i=0; i<size; i++){
        if(arr[i]>*max){
            *max = arr[i];
        } else if(arr[i]< *min){
           *min = arr[i]; 
        }
    }
}

int main(){
    int numbers[] = {1,2,4,3,5,6,4,2,9};
    // int size = numbers.size();
    int max= numbers[0];
    int min= numbers[0];
    minAndMaxFunc(numbers,9, &min, &max);
    cout << "min:" << min << endl;
    cout << "max:" << max << endl;


    int size;
    cout << "size:";
    cin >> size;
    int* myArray = new int[size];

    for(int i=0; i<size; i++){
        cout << "Array[" << i <<"]";
        cin >> myArray[i];
    }
    for(int i=0; i<size; i++){
        cout << *(myArray+i);
    }

    return 0;
}
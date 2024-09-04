#include <bits/stdc++.h>
// #include <agorithm>

using namespace std;
bool descending(int a, int b){
    return a > b;
}

bool ascending(int a, int b){
    return b > a;
}

void customSort(vector<int> &vec, bool (*compareFunction)(int, int)) {
    for(int i=0; i<vec.size(); i++){
        int bestIndex = i;
        for(int j=i+1; j<vec.size(); j++){
            if(compareFunction(vec[j], vec[bestIndex])){
                bestIndex = j;
            }
        }
        swap(vec[i], vec[bestIndex]);
    }
}

int main(){
    vector<int> vec = {1,3,6,8,5,9};
    bool (*ptrPointer)(int, int) = descending;
    customSort(vec, ptrPointer);
    
    for(int i=0; i< vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;




int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    } 
    int res = 0;

    for(int i=0 ; i<=N; i++){
        for(int j=0; j<=N ; j++){
            if(i + j  > N) continue;
            long long A = 0;
            long long B = 0;
            for(int k = 0; k < i; k++){
                A+= arr[k];
            }
            for(int k = N-j; k < N; k++){
                B+= arr[k];
            }

            if(A == B){
                res = max(res, i+j);
            }
        }
    }

    cout << res;
    return 0;
}
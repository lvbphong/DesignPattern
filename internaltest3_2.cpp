#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> M(N);
    vector<long long> D(N);
    for(int i = 0; i < N; i++){
        cin >> M[i];
    }
    for(int i = 0; i < N; i++){
        cin >> D[i];
    }
    int K;
    cin >> K;
    vector<pair<long long, pair<long long, int>>> plants;
    for(int i=0; i<N; i++){
        plants.push_back({D[i], {M[i], i}});
    }
    sort(plants.begin(), plants.end());
    vector<long long> totalPower(N, 0);
    long long diameter_temp = 0;

    priority_queue<long long> connectable;
    for(int i=0; i<N;i++){
        long long diameter = plants[i].first;
        long long power = plants[i].second.first;
        int index = plants[i].second.second;
        totalPower[index] = diameter_temp;

        if(connectable.size() < K){
            connectable.push(power);
            diameter_temp += power;
        } else if(connectable.top() < power){
            connectable.pop();
            diameter_temp -= connectable.top();
            connectable.push(power);
            diameter_temp += power;
        }
        
    }
    for(int i=0; i<N; i++){
        if(i == N-1){
            cout << totalPower[i] << endl;
        } else {
            cout << totalPower[i] <<"," ;
        }
    }
    return 0;
}
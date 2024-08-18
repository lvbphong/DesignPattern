#include <iostream>
#include <thread>
#include <map>
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono_literals;

using namespace std;

void func1(string symbol) {
    for(int i=0; i<200; i++){
       cout << symbol;
    }
}


void func2(string symbol) {
    for(int i=0; i<200; i++){
       cout << symbol;
    }
}

void refreshForecast(std::map<std::string, int>& forecastMap) {
    while (true) {
        for (auto& item : forecastMap) {
            item.second++;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        std::this_thread::sleep_for(2000ms);
    }
}

int main() {
    // std::thread thread1(func1, "+");
    // std::thread thread2(func1, "-");

    std::map<std::string, int> forecastMapVN = {
        {"Ha Noi", 25},
        {"Ho Chi Minh", 30},
        {"Da Nang", 32}
    };
    std::thread bWorker(refreshForecast, std::ref(forecastMapVN));
    // thread1.join();
    // thread2.join();
    bWorker.join();
    return 0;
}
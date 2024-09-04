
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

std::mutex gLock;
std::condition_variable gCondition_variable;

int main(){
    int result = 0;
    bool notified = false;
    // cout << notified;

    //reporting thread
    //must wait on work, done by working thread
    std::thread reporter([&](){
        cout << " Come to report:" << result << endl;
        std::unique_lock<std::mutex> lock(gLock);
        cout << " After lock:" << result << endl;
        if(!notified){
            cout << " Wait, result is:" << result << endl;
            gCondition_variable.wait(lock);
        }
        cout << " Report, result is:" << result << endl;
    });

    std::thread work([&](){
        std::unique_lock<std::mutex> lock(gLock);
        // Do our work
        result = 42+10;
        notified = true;
        cout << "before 5s :" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "after 2s  then notify:" << endl;
        gCondition_variable.notify_one();

    });
        reporter.join();
        work.join();
        return 0;


}
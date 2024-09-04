#include <iostream>
#include <memory>

using namespace std;

class MyClass {
    public:
        MyClass() {
            cout << "contructor " << endl;
        }
        ~MyClass() {
            cout << "decontructor " << endl;
        }
};

int main(){
    // unique_ptr<int> unPtr1 = make_unique<int>(25);
    // unique_ptr<int> unPtr2   = move(unPtr1); 


    // // cout << unPtr1 << endl;
    // cout << *unPtr2;
    // cout << *unPtr1;

    {
        unique_ptr<MyClass> unitPtr1 = make_unique<MyClass>();
    } 

{    shared_ptr<MyClass> shPtr1 = make_shared<MyClass>();
    cout << "Shared count :"<< shPtr1.use_count() << endl; }
    system("pause>nul");
}
#include <bits/stdc++.h>
using namespace std;

int _sum(int a, int b){
    return a+b;
};

int _sum(int a, int b, int c){
    return a+b+c;
};


class User {
public:
    virtual void getPermission(){
        cout << "User can see limited info" << endl;
    }
};
class SuperUser : public User {
public:
    void getPermission(){
        cout << "SuperUser can see limited info" << endl;
    }
};
int main() {
    cout << _sum(1,2) << endl;
    cout << _sum(1,2,3) << endl;

    User u;
    SuperUser su;
    list<User*> ls;
    ls.push_back(&u);
    ls.push_back(&su);

    for(auto item : ls){
        item->getPermission();
    }
    
    return 0;
}
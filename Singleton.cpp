#include<iostream>

class ApplicationState {
private:
    static ApplicationState* instance;
    bool loggedIn;

    ApplicationState() : loggedIn(false) {}

public:
    static ApplicationState* getAppState() {
        if(!instance){
            instance = new ApplicationState();
        }
        return instance;
    }

    bool isLoggedIn() {
        return loggedIn;
    }
};

ApplicationState* ApplicationState::instance = nullptr;



class ApplicationState2
{
private:
    bool loggedIn;

    ApplicationState2() : loggedIn(false) {}

public:
    static ApplicationState2& getAppState2() {
        static ApplicationState2 instance;
        return instance;
    }

    bool isLoggedIn() {
        return loggedIn;
    }
};


int main(){
    ApplicationState* appState1 = ApplicationState::getAppState();

    ApplicationState2& appState2 = ApplicationState2::getAppState2();
    std::cout << appState1->isLoggedIn() << std::endl;
    std::cout << appState2.isLoggedIn() << std::endl;

    return 0;
}

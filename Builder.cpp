#include <iostream>
#include <string>

class Burger {
private:
    std::string buns;
    std::string patty;
    std::string cheese;

public:
    void setBuns(std::string bunStyle) {
        buns = bunStyle;
    }

    void setPatty(std::string pattyStyle) {
        patty = pattyStyle;
    }

    void setCheese(std::string cheeseStyle) {
        cheese = cheeseStyle;
    }

    void displayBurger() {
        std::cout << "Burger with " << buns << " buns, " << patty << " patty, and " << cheese << " cheese." << std::endl;
    }
};

class BurgerBuilder {
    private:
        Burger burger;
    public:
        BurgerBuilder() {}

        BurgerBuilder& addBun(std::string bunStyle) {
            burger.setBuns(bunStyle);
            return *this;
        }

            BurgerBuilder& addPatty(std::string pattyStyle) {
            burger.setPatty(pattyStyle);
            return *this;
        }

        BurgerBuilder& addCheese(std::string cheeseStyle) {
            burger.setCheese(cheeseStyle);
            return *this;
        }

}

int main() {
    Burger burger = BurgerBuilder()
                        .addBuns("sesame")
                        .addPatty("firs-patty")
                        .addCheese("swiss cheese")
                        .build();

    burger.displayBurger();

    return 0;
}

#include <iostream>
#include <vector>

class Burger {
private:
    std::vector<std::string> ingredients;

public:
    Burger(std::vector<std::string> ingredients) : ingredients(ingredients) {}

    void print() {
        for (const auto& ingredient : ingredients) {
            std::cout << ingredient << " ";
        }
        std::cout << std::endl;
    }
};

class BurgerFactory {
public:
    Burger createCheeseBurger() {
        std::vector<std::string> ingredients = {"bun", "cheese", "beef-g"};
        return Burger(ingredients);
    }
    
    Burger createDeluxteCheeseBurger() {
        std::vector<std::string> ingredients = {"bun", "tomato", "beef-g"};
        return Burger(ingredients);
    }
};

int main() {
    BurgerFactory burgerFactory;

    Burger cheeseBurger = burgerFactory.createCheeseBurger();
    cheeseBurger.print();

    Burger deluxeCheeseBurger = burgerFactory.createDeluxteCheeseBurger();
    deluxeCheeseBurger.print();

    return 0;
}
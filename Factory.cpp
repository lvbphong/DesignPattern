#include <iostream>
#include <vector>

/*
class Burger {
public:
    Burger(std::vector<std::string> ingredients) : ingredients(ingredients) {}

    void print() {
        for (const auto& ingredient : ingredients) {
            std::cout << ingredient << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::string> ingredients;
};

int main() {
    std::vector<std::vector<std::string>> burgersIngredients = {
        {"bun", "cheese", "beef-g"},
        {"bun", "tomato", "beef-g"},
        {"bun", "lettuce", "chicken"}
    };

    std::vector<Burger> burgers;
    for (const auto& ingredients : burgersIngredients) {
        Burger burger(ingredients);
        burgers.push_back(burger);
    }

    // Printing all burgers
    for (const auto& burger : burgers) {
        burger.print();
    }

    return 0;
} */


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
/*
 In the context of the provided example of creating instances of different types of burgers,
using a factory pattern like the BurgerFactory can offer several advantages:

1. Encapsulation of Object Creation Logic:
The factory encapsulates the creation logic for different types of burgers. 
This means that the client code creating the burgers does not need to know how
each type of burger is created; it only needs to call the appropriate factory method.

2. Centralized Object Creation:
By centralizing the creation of burger instances within the factory, any changes 
to the creation process (such as adding new types of burgers or modifying existing ones)
 can be done within the factory class without affecting the client code.

3. Code Reusability:
The factory pattern promotes code reusability by centralizing the object creation logic.
 If the same type of object needs to be created in multiple places within the codebase,
using a factory can help avoid code duplication.

4. Flexibility and Scalability:
Factories can easily accommodate changes or additions to the types of objects being created.
 If new types of burgers need to be added in the future, the factory can be extended to support 
these new types without impacting existing code.

5. Testing and Maintenance:
Factories can simplify testing by allowing for easier mocking during unit testing.
 They also make it easier to maintain and understand the codebase by separating the object 
 creation logic from other business logic. */
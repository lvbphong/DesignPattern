#include <iostream>
#include <string>

/*#include <iostream>
#include <string>

class Burger {
private:
    std::string buns;
    std::string patty;
    std::string cheese;

public:
    Burger(std::string bunStyle, std::string pattyStyle, std::string cheeseStyle) : buns(bunStyle), patty(pattyStyle), cheese(cheeseStyle) {}

    void displayBurger() {
        std::cout << "Burger with " << buns << " buns, " << patty << " patty, and " << cheese << " cheese." << std::endl;
    }
};

int main() {
    Burger burger1("sesame", "firs-patty", "swiss cheese");
    Burger burger2("whole wheat", "veggie patty", "cheddar cheese");

    burger1.displayBurger();
    burger2.displayBurger();

    return 0;
}*/

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

/*In the context of the provided example of creating instances of different types of burgers, using a factory pattern like the 
BurgerFactory can offer several advantages:

1.Encapsulation of Object Creation Logic:
The factory encapsulates the creation logic for different types of burgers. This means that the client code creating the burgers 
does not need to know how each type of burger is created; 
it only needs to call the appropriate factory method.

2.Centralized Object Creation:
By centralizing the creation of burger instances within the factory, any changes to the creation process (such as adding new types
 of burgers or modifying existing ones) can be done within the factory class without affecting the client code.

3.Code Reusability:
The factory pattern promotes code reusability by centralizing the object creation logic. If the same type of object needs to be 
created in multiple places within the codebase, using a factory can help avoid code duplication.

4.Flexibility and Scalability:
Factories can easily accommodate changes or additions to the types of objects being created. If new types of burgers need to be
added in the future, the factory can be extended to support these new types without impacting existing code.

5.Testing and Maintenance:
Factories can simplify testing by allowing for easier mocking during unit testing. They also make it easier to maintain and 
understand the codebase by separating the object creation logic from other business logic.

6.Polymorphism and Inheritance:
Factories can be extended to support polymorphic object creation. For example, you could have a base Burger class and different
 subclasses (e.g., CheeseBurger, DeluxeCheeseBurger) that the factory can create based on the situation.*/
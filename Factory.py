class Burger:
    def __init__(self, ingredients):
        self.ingredients = ingredients

    def print(self):
        print(self.ingredients)

class BurgerFactory:
    def createCheeseBurger(self):
        ingredients = ["bun", "cheese", "beef-g"]
        return Burger(ingredients)
    
    def createDeluxteCheeseBurger(self):
        ingredients = ["bun", "tomato", "beef-g"]
        return Burger(ingredients)

burger_factory = BurgerFactory()

cheese_burger = burger_factory.createCheeseBurger()
cheese_burger.print()

deluxe_cheese_burger = burger_factory.createDeluxteCheeseBurger()
deluxe_cheese_burger.print()
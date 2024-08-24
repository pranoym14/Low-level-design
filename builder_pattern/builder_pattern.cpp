#include <iostream>

class Pizza {
public:
    Pizza(const std::string& crust, const std::string& sauce, const std::string& cheese)
        : crust_(crust), sauce_(sauce), cheese_(cheese) {}

    std::string getCrust() const { return crust_; }
    std::string getSauce() const { return sauce_; }
    std::string getCheese() const { return cheese_; }

private:
    std::string crust_;
    std::string sauce_;
    std::string cheese_;
};

class PizzaBuilder {
public:
    virtual PizzaBuilder& setCrust(const std::string& crust) = 0;
    virtual PizzaBuilder& setSauce(const std::string& sauce) = 0;
    virtual PizzaBuilder& setCheese(const std::string& cheese) = 0;
    virtual Pizza build() = 0;
    virtual void reset()=0;
};

class PepperoniPizzaBuilder : public PizzaBuilder {
public:
    PepperoniPizzaBuilder()
    {
      this->reset();
    }
    void reset() override
    {
      this->crust_ = "NAN";
      this->sauce_ = "NAN";
      this->cheese_= "NAN";
    }

    PizzaBuilder& setCrust(const std::string& crust) override {
        crust_ = crust;
        return *this;
    }

    PizzaBuilder& setSauce(const std::string& sauce) override {
        sauce_ = sauce;
        return *this;
    }

    PizzaBuilder& setCheese(const std::string& cheese) override {
        cheese_ = cheese;
        return *this;
    }

    Pizza build() override {
        Pizza product= Pizza(crust_, sauce_, cheese_);
        this->reset();
        return product;
    }

private:
    std::string crust_;
    std::string sauce_;
    std::string cheese_;
};
// Client or director calls builder which in turn sets the parameters 
int main() {
    PepperoniPizzaBuilder builder;
    Pizza pizza = builder.setCrust("thin").setSauce("marinara").build();

    std::cout << "Pizza crust: " << pizza.getCrust() << std::endl;
    std::cout << "Pizza sauce: " << pizza.getSauce() << std::endl;
    std::cout << "Pizza cheese: " << pizza.getCheese() << std::endl;

    return 0;
}
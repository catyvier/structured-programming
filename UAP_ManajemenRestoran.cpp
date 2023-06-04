/* Ujian Akhir Praktikum - Structured Programming
 * Restaurant Management
 *
 * Contributor
 * 2217051004
 * 
 */
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Order {
private:
    std::string name;
    std::vector<std::string> listOfOrders;

    void sortOrders();

public:
    Order(const std::string &str, const std::initializer_list<std::string> &ls) : name(str), listOfOrders(ls) {}

    void setName(const std::string &newName);
    void setListOfOrders(const std::vector<std::string> &ls);

    const std::string& getName();
    const std::vector<std::string>& getListOfOrders();

    void addOrder(const std::string &newOrder);
    bool cancelOrder(const std::string &orderName);
    void printOrders();
};

void Order::setName(const std::string &newName)
{
    this->name = newName;
}

void Order::setListOfOrders(const std::vector<std::string> &ls)
{
    this->listOfOrders = ls;
}

const std::string& Order::getName()
{
    return this->name;
}

const std::vector<std::string>& Order::getListOfOrders()
{
    return this->listOfOrders;
}

void Order::addOrder(const std::string &newOrder)
{
    this->listOfOrders.push_back(newOrder);
}

bool Order::cancelOrder(const std::string &orderName)
{
    std::vector<std::string>::iterator it = std::find(this->listOfOrders.begin(), this->listOfOrders.end(), orderName);

    if (it != this->listOfOrders.end()) {
        this->listOfOrders.erase(it);
        return true;
    }

    return false;
}

void Order::printOrders()
{
    std::cout << "List of orders by " << this->name << std::endl;
    for (size_t i = 0, n = this->listOfOrders.size(); i < n; ++i) {
        std::cout << i+1 << ". " << this->listOfOrders[i] << std::endl;
    }
    
    std::cout << std::endl;
}

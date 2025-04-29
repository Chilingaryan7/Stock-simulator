#include "header.hpp"

int main(){
    std::unordered_map<std::string, Isubject *> stockMarket;
    stockMarket["Apple"] = new Subject(115.00, "apple");
    stockMarket["Google"] = new Subject(150.00, "Google");
    stockMarket["Tesla"] = new Subject(175.00, "Tesla");
    Iobserver * observer1 = new Observer();
    Iobserver * observer2 = new Observer();
    Iobserver * observer3 = new Observer();
    Iobserver * observer4 = new Observer();
    Iobserver * observer5 = new Observer();
    Iobserver * observer6 = new Observer();
    stockMarket["Apple"]->add_observer(observer1);
    stockMarket["Apple"]->add_observer(observer2);
    stockMarket["Google"]->add_observer(observer3);
    stockMarket["Google"]->add_observer(observer4);
    stockMarket["Tesla"]->add_observer(observer5);
    stockMarket["Tesla"]->add_observer(observer6);
    stockMarket["Apple"]->set_price(125.00);
    stockMarket["Google"]->set_price(145.00);
    stockMarket["Tesla"]->set_price(195.00);
    stockMarket["Apple"]->delete_observer(observer2);
    stockMarket["Google"]->delete_observer(observer4);
    observer6->unfollow();
    stockMarket["Apple"]->set_price(100.00);
    stockMarket["Google"]->set_price(80.00);
    stockMarket["Tesla"]->set_price(70.00);
    delete observer1;
    delete observer2;
    delete observer3;
    delete observer4;
    delete observer5;
    delete observer6;
    for (auto &pair : stockMarket) {
        delete pair.second;
    }
stockMarket.clear();
    return 0;
}
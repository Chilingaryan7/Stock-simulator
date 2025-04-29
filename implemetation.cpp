#include "header.hpp"

Isubject::Isubject(float price, std::string name) : m_name{name},  m_price{price} {}

Subject::Subject(float price, std::string name) :Isubject(price, name) {}

Isubject::~Isubject(){
    m_observers.clear();
}

void Subject::add_observer(Iobserver* observer) {
    for (Iobserver* ptr : m_observers) {
        if (ptr == observer) {
            return;
        }
    }
    observer ->set_subject(this);
    m_observers.push_back(observer);
    return;
}

void Subject::delete_observer(Iobserver* observer) {
    m_observers.remove(observer);
    return;
}

void Subject::notify() {
    for (Iobserver * ptr : m_observers) {
        if(ptr) {
            ptr->update();
        }
    }
}

float Isubject::get_price() const{
    return m_price;
}
void Isubject::set_price(float price){
    m_price = price;
    notify();
    return;
}

const std::string& Isubject::get_name() const {
    return m_name;
}

void Observer::unfollow(){
    m_subject->delete_observer(this);
    return;
}
void Observer::follow(std::unordered_map<std::string, Isubject *>& stock, std::string subject){
    if (stock.find(subject) != stock.end()) {
        stock[subject]->add_observer(this);
        m_subject = stock[subject];
        std::cout << "Access Follow" << std::endl;
    } else {
        std::cout << "Sorry, we don't have that stock" << std::endl;
    }
    return;
}
void Observer::update() const{
    std::cout << "New price of "<< m_subject->get_name() << " : " << m_subject->get_price() << std::endl;
    return;
}

void Iobserver::set_subject(Isubject * subject){
    m_subject = subject;
    return;
}



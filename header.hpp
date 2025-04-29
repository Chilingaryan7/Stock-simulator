#ifndef HEADER
#define HEADER

#include <iostream>
#include <memory>
#include <utility>
#include <list>
#include <string>
#include <unordered_map>
#include <algorithm>

class Isubject;
class Iobserver {
public:
    //ctors && dtor
    // Iobserver() = default;
    // Iobserver(const Iobserver& other) = default;
    // Iobserver(Iobserver&& other) = default;
    // Iobserver& operator=(const Iobserver& other) = default;
    // Iobserver& operator=(Iobserver&& other) = default;
     virtual ~Iobserver() = default;
    
    //member functions
    void set_subject(Isubject * subject);
    virtual void unfollow() = 0;
    virtual void follow(std::unordered_map<std::string,Isubject *>& stock, std::string subject) = 0;
    virtual void update() const = 0;

protected:
    Isubject * m_subject;
};

class Isubject {
public:
    //ctors && dtor
    Isubject(float price, std::string name = "");
    // Isubject(const Isubject& other) = default;
    // Isubject(Isubject&& other) = default;
    // Isubject& operator=(const Isubject& other) = default;
    // Isubject& operator=(Isubject&& other) = default;
    virtual ~Isubject() = 0;

    //member functions
    float get_price() const;
    void set_price(float price);
    const std::string& get_name() const;
    virtual void add_observer(Iobserver* observer) = 0;
    virtual void delete_observer(Iobserver* observer) = 0;
    virtual void notify() = 0;

protected:
    const std::string m_name;
    std::list<Iobserver* > m_observers;
    float m_price;

};

class Observer : public Iobserver {
public:
    //member functions
    void unfollow();
    void follow(std::unordered_map<std::string, Isubject *>& stock, std::string subject);
    void update() const;
};

class Subject : public Isubject {
public:
    //ctors a&& dtor
    Subject(float price, std::string name  = "");
    // Subject(const Subject& other) = default;
    // Subject(Subject&& other) = default;
    // Subject& operator=(const Subject& other) = default;
    // Subject& operator=(Subject&& other) = default;

    //member functions
    virtual void add_observer(Iobserver* observer);
    virtual void delete_observer(Iobserver* observer);
    virtual void notify();
};

#endif //HEADER
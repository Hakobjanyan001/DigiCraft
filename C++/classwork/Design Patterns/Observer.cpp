#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// Observer ինտերֆեյս
class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() {}
};

// Subject (Publisher)
class Subject {
	std::vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void detach(Observer* obs) {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notify(const std::string& msg) {
        for (auto* obs : observers) {
            obs->update(msg);
        }
    }
};

// Կոնկրետ observer-ներ
class User : public Observer {
	std::string name;
public:
    User(std::string n) : name(n) {}
    void update(const std::string& message) override {
	 std::cout << name << " got notification: " << message << std::endl;
    }
};

int main() {
    Subject s;

    User u1("Alice");
    User u2("Bob");
    User u3("Charlie");

    s.attach(&u1);
    s.attach(&u2);
    s.attach(&u3);

    s.notify("New message: Hello World!");
}

#include <iostream>
#include <string.h>
using namespace std;

class Hero {
    protected:
    int health;
    char level;

    public:
    char *name;
    static int game;

    // Default Constructor
    Hero() {
        cout << "Hero created!" << endl;
        cout << "Address of this: " << this << endl;
        name = new char[100];
    };
    // Parameterised Constructor with one parameter
    Hero(int health) {
        cout << "Hero created!" << endl;
        cout << "Address of this: " << this << endl;
        name = new char[100];
        this->health = health;
    };
    // Parameterised Constructor with two parameter
    Hero(int health, char level) {
        cout << "Hero created!" << endl;
        cout << "Address stored in this" << this << endl;
        name = new char[100];
        this->health = health;
        this->level = level;
    };
    // Copy Constructor
    Hero(Hero &h) {
        cout << "Hero copied!" << endl;
        char *ch = new char[strlen(h.name) + 1];
        strcpy(ch, h.name);
        this->name = ch;
        this->health = h.health;
        this->level = h.level;
    };
    // Object Destructor
    ~Hero() {
        cout << "Hero has been destroyed!" << endl;
    }

    void print() {
        cout << endl;
        cout << "***********" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Level: " << this->getLevel() << endl;
        cout << "Health: " << this->getHealth() << endl;
        cout << "***********" << endl;
        cout << endl;
    }

    int getHealth() {
        return this->health;
    };

    void setHealth(int h) {
        this->health = h;
    }

    char getLevel() {
        return this->level;
    };

    void setLevel(char l) {
        this->level = l;
    }

    void setName(char n[]) {
        strcpy(this->name, n);
    }

    static int change_server(int s) {
        game = s;
        cout << "Game server changed to: " << s << endl;
        return game;
    }
    // Function Overloading
    static int change_server(int s, char x) {
        game = s;
        cout << "Game server changed to: " << s << " " << x << endl;
        return game;
    }
    // Operator Overloading
    void operator+ (Hero &h) {
        this->health += h.health;
        cout << "Heroes joined forces!";
    }
};

class Marvel: public Hero {
    public:
    int id;
};

int Hero::game;

int main() {
    Hero *h1 = new Hero(10, 'A');
    cout << "Address of object: " << h1 << endl;
    cout << "Size of pointer: " << sizeof(h1) << endl;
    cout << "Size of object: " << sizeof(*h1) << endl;
    char hero_name[7] = "Pranav";
    h1->setName(hero_name);
    cout << "Name of hero: " << h1->name << endl;
    cout << "Health of hero: " << h1->getHealth() << endl;
    h1->setHealth(5);
    cout << "Health after setting: " << h1->getHealth() << endl;
    cout << "Level of hero: " << h1->getLevel() << endl;
    h1->setLevel('B');
    cout << "Level after setting: " << h1->getLevel() << endl;
    h1->print();
    Hero *h2 = new Hero(*h1);
    h2->print();
    h2->name[5] = 'y';
    cout << "After modifying deep copy!" << endl;
    h1->print();
    h2->print();
    h2 = h1;
    cout << "After copy assignment!" << endl;
    h1->print();
    h2->print();
    // Accessing static variable in a class.
    Hero::game = 102086;
    cout << "Game server: " << Hero::game << endl;
    // Using static function of a class.
    Hero::change_server(102011);
    Marvel *m1 = new Marvel;
    m1->id = 201819;
    m1->setHealth(10);
    cout << "Marvel Hero ID " << m1->id << " has " << m1->getHealth() << " heath." << endl;
    Hero::change_server(102011, 'A');
    *h1 + *h2;
    h1->print();
    h2->print();
    // Dynamically allocated objects need to be destroyed manually.
    delete h1;
    delete h2;
    return 0;
};
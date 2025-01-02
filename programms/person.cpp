#include <iostream>

class Person {
public:
    Person(unsigned int _pesel,
           const char *_name,
           const char *_surname)
    {
        pesel = _pesel;
        name = strdup(name);
        surname = strdup(surname);
    }
    ~Person()
    {
        /* Używamy strdup, więc zwalniamy w stylu C */
        free(name);
        free(surname);
    }

private:
    unsigned int pesel;
    char *name;
    char *surname;
};

int main() {
    Person p(1234567890, "Robert", "Kowalski");
    Person p2(p); /* Konstruktor kopiujący */

    Person p3(1234567890, "Adam", "Lewandowski");
    p = p3; /* Operator przypisania */
    return 0;
}
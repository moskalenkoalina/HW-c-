#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string pib;
    string gender;
    int age;
public:
    Person() : pib(""), gender(""), age(0) {}
    Person(string p, string g, int a) : pib(p), gender(g), age(a) {}
    Person(const Person& other) : pib(other.pib), gender(other.gender), age(other.age) {}

    virtual void input() {
        cout << "Enter PIB: ";
        getline(cin, pib);
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }

    virtual void output() const {
        cout << "PIB: " << pib << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : virtual public Person {
protected:
    int course;
    string group;
    string university;
public:
    Student() : Person(), course(0), group(""), university("") {}
    Student(string p, string g, int a, int c, string gr, string univ)
        : Person(p, g, a), course(c), group(gr), university(univ) {}
    Student(const Student& other)
        : Person(other), course(other.course), group(other.group), university(other.university) {}

    void input() override {
        Person::input();
        cout << "Enter the rate: ";
        cin >> course;
        cin.ignore();
        cout << "Enter the group: ";
        getline(cin, group);
        cout << "Enter the university: ";
        getline(cin, university);
    }

    void output() const override {
        Person::output();
        cout << "Rate: " << course << endl;
        cout << "group: " << group << endl;
        cout << "University: " << university << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string university;
    string position;
public:
    Teacher() : Person(), university(""), position("") {}
    Teacher(string p, string g, int a, string univ, string pos)
        : Person(p, g, a), university(univ), position(pos) {}
    Teacher(const Teacher& other)
        : Person(other), university(other.university), position(other.position) {}

    void input() override {
        Person::input();
        cout << "Enter the university: ";
        getline(cin, university);
        cout << "Enter the position: ";
        getline(cin, position);
    }

    void output() const override {
        Person::output();
        cout << "university: " << university << endl;
        cout << "Position: " << position << endl;
    }
};

class Aspirant : public Student, public Teacher {
private:
    string science_direction;
public:
    Aspirant() : Person(), Student(), Teacher(), science_direction("") {}

    Aspirant(string p, string g, int a, int c, string gr,
             string univ, string pos, string science)
        : Person(p, g, a),
          Student(p, g, a, c, gr, univ),
          Teacher(p, g, a, univ, pos),
          science_direction(science) {}

    Aspirant(const Aspirant& other)
        : Person(other),
          Student(other),
          Teacher(other),
          science_direction(other.science_direction) {}

    void input() override {
        Person::input();

        cout << "Enter the rate: ";
        cin >> course;
        cin.ignore();

        cout << "Enter the group: ";
        getline(cin, group);

        cout << "Enter the university: ";
        getline(cin, university);
        Teacher::university = university;

        cout << "Enter the position: ";
        getline(cin, position);

        cout << "Enter the scientific direction: ";
        getline(cin, science_direction);
    }

    void output() const override {
        Person::output();
        cout << "Rate: " << course << endl;
        cout << "Group: " << group << endl;
        cout << "university: " << university << endl;
        cout << "Position: " << position << endl;
        cout << "scientific direction: " << science_direction << endl;
    }
};

void demonstrateClasses() {
    Person person;
    person.input();
    person.output();

    Student student;
    student.input();
    student.output();

    Teacher teacher;
    teacher.input();
    teacher.output();






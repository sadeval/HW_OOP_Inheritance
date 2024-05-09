#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    string name;
    string surename;

public:
    Person(string name, string surename) : name(name), surename(surename) {
        cout << "Person C-TOR\n";
    }

    ~Person() {
        cout << "Person D-TOR\n";
    }

    void Print() const {
        cout << "Person's name: " << name << " " << surename << "\n";
    }

    void SetName(const string& name) {
        this->name = name;
    }

    string GetName() const {
        return name;
    }

    void SetSurename(const string& surename) {
        this->surename = surename;
    }

    string GetSurename() const {
        return surename;
    }
};

class Student : public Person {
    vector<int> ratings;

public:
    Student(string name, string surename, const vector<int>& ratings) : Person(name, surename), ratings(ratings) {
        cout << "Student C-TOR\n";
    }

    ~Student() {
        cout << "Student D-TOR\n";
    }

    void Overslept() {
        cout << "Oh NO!\n";
    }

    void PassExam() {
        cout << "Finally!\n";
    }

    void SetRatings(const vector<int>& ratings) {
        this->ratings = ratings;
    }

    vector<int> GetRatings() const {
        return ratings;
    }

    void Print() const {
        cout << "Student's name: " << GetName() << " " << GetSurename() << "\n";
        cout << "Ratings: ";
        for (int rating : ratings) {
            cout << rating << " ";
        }
        cout << "\n";
    }
};

class Aspirant : public Student {
    string topicOfCandidate;

public:
    Aspirant(string name, string surename, const vector<int>& ratings, string topicOfCandidate) : Student(name, surename, ratings), topicOfCandidate(topicOfCandidate) {
        cout << "Aspirant C-TOR\n";
    }

    ~Aspirant() {
        cout << "Aspirant D-TOR\n";
    }

    void PreparationForDefending() {
        cout << "Research on quantum physics\n";
    }

    void SetTopicOfCandidate(const string& topic) {
        topicOfCandidate = topic;
    }

    string GetTopicOfCandidate() const {
        return topicOfCandidate;
    }

    void Print() const {
        cout << "Aspirant's name: " << GetName() << " " << GetSurename() << "\n";
        cout << "Ratings: ";
        for (int rating : GetRatings()) {
            cout << rating << " ";
        }
        cout << "\n";
        cout << "Topic of candidate work: " << topicOfCandidate << "\n";
    }
};

int main() {

    vector<int> studentRatings = { 12, 11, 11, 12, 9 };
    Student student("Vasya", "Pupkin", studentRatings);
    student.Print();

    vector<int> aspirantRatings = { 12, 12, 11, 12, 12 };
    Aspirant aspirant("Katya", "Pushkareva", aspirantRatings, "Research on quantum physics");
    aspirant.Print();

}

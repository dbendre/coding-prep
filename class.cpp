/*
 Create a class named Student with age, first name, last name, grade.
 Include the following functions:
 get_age, set_age
 get_first_name, set_first_name,
 get_last_name, set_last_name,
 get_grade, set_grade
 to_string() which returns the string consisting of the above elements separated by a comma
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Student {
private:
    int age;
    string firstName;
    string lastName;
    int grade;
    
public:
    void set_age(int inputAge) {
        age = inputAge;
    }
    
    int get_age() {
        return age;
    }
    
    void set_first_name(string inputFirstName) {
        firstName = inputFirstName;
    }
    
    string get_first_name() {
        return firstName;
    }
    
    void set_last_name(string inputLastName) {
        lastName = inputLastName;
    }
    
    string get_last_name() {
        return lastName;
    }
    
    void set_grade(int inputGrade) {
        grade = inputGrade;
    }
    
    int get_grade() {
        return grade;
    }
    
    string to_string() {
        stringstream output;
        output << age << "," << firstName << "," << lastName << "," << grade;
        return (output.str());
    }
};

int main() {
    int age, grade;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> grade;
    
    Student st;
    st.set_age(age);
    st.set_grade(grade);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_grade() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
    
    
}

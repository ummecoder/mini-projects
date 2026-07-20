#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int marks;
    char grade;
};

// Grade calculate karne ka function
char calculateGrade(int marks) {
    if(marks >= 90) return 'A';
    else if(marks >= 80) return 'B';
    else if(marks >= 70) return 'C';
    else if(marks >= 60) return 'D';
    else return 'F';
}

// 1. Student add karne ka function
void addStudent(vector<Student> &students) {
    Student s;
    cout << "\nEnter details for new Student:" << endl;
    cout << "Name: ";
    cin.ignore(); // Enter saaf karne ke liye
    getline(cin, s.name);
    cout << "Marks 0-100: ";
    cin >> s.marks;
    s.grade = calculateGrade(s.marks);
    students.push_back(s);
    cout << "Student added successfully!" << endl;
}

// 2. Sab students dikhane ka function
void showAll(vector<Student> &students) {
    if(students.empty()) {
        cout << "\nNo students found. Pehle 1 se student add karein!" << endl;
        return;
    }

    cout << "\n--- All Students ---" << endl;
    for (auto s : students) {
        cout << "Name: " << s.name << " | Marks: " << s.marks << " | Grade: " << s.grade << endl;
    }
}

// 3. Student search karne ka function
void searchStudent(vector<Student> &students) {
    string searchName;
    cout << "\nEnter name to search: ";
    cin.ignore();
    getline(cin, searchName);

    for (auto s : students) {
        if(s.name == searchName) {
            cout << "Found! Name: " << s.name << " | Marks: " << s.marks << " | Grade: " << s.grade << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

// 4. Student delete karne ka function
void deleteStudent(vector<Student> &students) {
    string delName;
    cout << "\nEnter name to delete: ";
    cin.ignore();
    getline(cin, delName);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == delName) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

// 5. File me save karne ka function
void saveToFile(vector<Student> &students) {
    ofstream outfile("grades.txt");
    outfile << "--- Student Grade Report ---\n";
    for (auto s : students) {
        outfile << "Name: " << s.name << ", Marks: " << s.marks << ", Grade: " << s.grade << endl;
    }
    outfile.close();
    cout << "Data saved to grades.txt successfully!" << endl;
}

// Main function - Menu
int main() {
    vector<Student> students;
    int choice;

    cout << "=== Student Grade Management System ===" << endl;

    do {
        cout << "\n1. Add New Student" << endl;
        cout << "2. Show All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(students); break;
            case 2: showAll(students); break;
            case 3: searchStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: saveToFile(students); break;
            case 6: cout << "Program Exited. Bye!" << endl; break;
            default: cout << "Invalid choice! 1 se 6 tak likhein." << endl;
        }
    } while(choice!= 6);

    return 0;
}
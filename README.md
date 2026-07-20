# mini projects
This is a *Student Grade Management System in C++*

### *Full Line-by-Line Explanation*

#### *1. Libraries and Structure*
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
*What it does:*
- `iostream` → for `cin` and `cout`
- `vector` → to store multiple students in a list
- `string` → to store student names
- `fstream` → to save data to a file `grades.txt`
- `struct Student` → creates a template. Every student will have Name, Marks, and Grade

#### *2. Function to Calculate Grade*
char calculateGrade(int marks) {
    if(marks >= 90) return 'A';
    else if(marks >= 80) return 'B';
    else if(marks >= 70) return 'C';
    else if(marks >= 60) return 'D';
    else return 'F';
}
*What it does:* Takes marks and returns grade A, B, C, D, or F.

#### *3. Function 1: Add Student*
void addStudent(vector<Student> &students) {
    Student s;
    cout << "Enter Name: ";
    cin.ignore(); 
    getline(cin, s.name); // takes full name with spaces
    cout << "Enter Marks 0-100: ";
    cin >> s.marks;
    s.grade = calculateGrade(s.marks); // auto calculate grade
    students.push_back(s); // add to the list
}
*What it does:* Takes input for 1 student and adds it to the `students` vector.

#### *4. Function 2: Show All Students*
void showAll(vector<Student> &students) {
    for (auto s : students) {
        cout << "Name: " << s.name << " | Marks: " << s.marks << " | Grade: " << s.grade << endl;
    }
}
*What it does:* Loops through the list and prints details of all students.

#### *5. Function 3: Search Student*
void searchStudent(vector<Student> &students) {
    string searchName;
    getline(cin, searchName);
    for (auto s : students) {
        if(s.name == searchName) {
            // print details and return
        }
    }
}
*What it does:* Searches a student by exact name match.

#### *6. Function 4: Delete Student*
void deleteStudent(vector<Student> &students) {
    // finds the student by name
    students.erase(students.begin() + i); // removes from vector
}
*What it does:* Deletes a student from the list using their name.

#### *7. Function 5: Save to File*
void saveToFile(vector<Student> &students) {
    ofstream outfile("grades.txt");
    for (auto s : students) {
        outfile << "Name: " << s.name << ", Marks: " << s.marks << ", Grade: " << s.grade << endl;
    }
    outfile.close();
}
*What it does:* Writes all student data into a file called `grades.txt`

#### *8. Main Function - The Menu*
int main() {
    vector<Student> students; // empty list
    int choice;
    do {
        // Show Menu 1 to 6
        cin >> choice;
        switch(choice) {
            case 1: addStudent(students); break;
            case 2: showAll(students); break;
            case 3: searchStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: saveToFile(students); break;
            case 6: exit; break;
        }
    } while(choice != 6);
}
*What it does:* Runs a loop until you press 6. It shows a menu and calls the function you choose.

### *Summary of What This Program Does:*
This program works like a mini database.  
1.  *Add* new students with name + marks
2.  *Show* all students
3.  *Search* any student by name
4.  *Delete* any student
5.  *Save* everything to `grades.txt` file

### *How to Run in Terminal - Shortcut*

*Step 1: Compile*  
Open terminal in the folder where your file is
g++ student-grade.cpp -o student-grade
*Step 2: Run*
./student-grade
____________________________________________________________________________________________________________________________


          NUMBER GUESSING GAME


Question No: 3

DESCRIPTION:
This is a simple console-based Number Guessing Game written in C++.
The program randomly selects a number between 1 and 100.
The player has to guess the number. 
After each guess, the program gives a hint: "Too High" or "Too Low".
The game continues until the player guesses the correct number.
At the end, it shows how many attempts the player took.

HOW TO COMPILE:
Open Terminal or Command Prompt and type:
g++ guess.cpp -o guess

HOW TO RUN:
On Linux/Mac:  ./guess
On Windows:    guess.exe

HOW TO PLAY - STEP BY STEP:
Step 1: Run the program. You will see the title "NUMBER GUESSING GAME".
Step 2: The program will ask: "Enter your guess:"
Step 3: Type any number between 1 to 100 and press Enter.
Step 4: If your guess is too big, it will say "Too High! Try again."
Step 5: If your guess is too small, it will say "Too Low! Try again."
Step 6: Keep guessing until you find the correct number.
Step 7: When you win, it will show:
        - CONGRATULATIONS message
        - The correct number
        - Total number of attempts you took
        - Author information

CODE EXPLANATION:
1. srand(time(0)) and rand() % 100 + 1  -> Generates a random number from 1 to 100
2. while(true) loop                     -> Keeps asking for guesses until correct
3. if-else statements                   -> Checks if guess is High, Low, or Correct
4. attempts++                           -> Counts how many times you guessed
5. break                                -> Exits the loop when you win

FEATURES:
- Random number generation between 1 and 100
- Unlimited attempts for the player
- Hint after every guess
- Counts and displays total attempts
- Simple and easy to use.
___________________________________________________________________________________________________________________________________-

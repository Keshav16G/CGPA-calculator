#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Course {
    string name;
    float credit;
    float gradePoint;
};

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    float totalCredits = 0.0, totalGradePoints = 0.0;

    cout << "\nEnter details for each course:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin.ignore(); // To ignore leftover newline
        getline(cin, courses[i].name);
        
        cout << "Credit Hours: ";
        cin >> courses[i].credit;

        cout << "Grade Point (e.g., 10, 9, 8...): ";
        cin >> courses[i].gradePoint;

        totalCredits += courses[i].credit;
        totalGradePoints += (courses[i].credit * courses[i].gradePoint);
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n\n------ Grade Report ------\n";
    cout << left << setw(20) << "Course" << setw(10) << "Credits" << setw(15) << "Grade Point" << "\n";
    cout << "-------------------------------\n";

    for (const auto& course : courses) {
        cout << left << setw(20) << course.name
             << setw(10) << course.credit
             << setw(15) << course.gradePoint << "\n";
    }

    cout << "-------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Credits: " << totalCredits << "\n";
    cout << "Total Grade Points: " << totalGradePoints << "\n";
    cout << "Calculated CGPA: " << cgpa << "\n";

    if (cgpa >= 9.0)
        cout << "Performance: Excellent\n";
    else if (cgpa >= 8.0)
        cout << "Performance: Very Good\n";
    else if (cgpa >= 7.0)
        cout << "Performance: Good\n";
    else if (cgpa >= 6.0)
        cout << "Performance: Satisfactory\n";
    else
        cout << "Performance: Needs Improvement\n";

    return 0;
}

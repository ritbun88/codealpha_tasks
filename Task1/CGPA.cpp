#include<iostream>
#include<iomanip> // for setprecision
using namespace std;

int main() {
    int numCourses;
    float totalGradePoints = 0, totalCredits = 0;
    
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; i++) {
        float grade, credits;
        cout << "\nCourse " << i << " Grade (on 10.0 scale): ";
        cin >> grade;
        cout << "Course " << i << " Credit: ";
        cin >> credits;

        totalGradePoints += (grade * credits);
        totalCredits += credits;
    }

    if (totalCredits == 0) {
        cout << "\nNo credits entered. Cannot calculate CGPA." << endl;
    } else {
        float CGPA = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2); // Display result with 2 decimal places
        cout << "\nTotal Credits: " << totalCredits;
        cout << "\nTotal Grade Points: " << totalGradePoints;
        cout << "\nCGPA: " << CGPA << endl;
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


float calculateAttendanceMarks(int classesAttended) {
    const int totalClasses = 24;
    const int fullMarks = 10;
    if (classesAttended >= 20) {
        return fullMarks;
    } else {
        int missedClasses = 20 - classesAttended;
        float deduction = missedClasses * 0.25f;
        return max(0.0f, fullMarks - deduction);
    }
}


float calculateGrade(float totalMarks) {
    if (totalMarks >= 90) return 4.00;
    if (totalMarks >= 86) return 3.67;
    if (totalMarks >= 82) return 3.33;
    if (totalMarks >= 78) return 3.00;
    if (totalMarks >= 74) return 2.67;
    if (totalMarks >= 70) return 2.33;
    if (totalMarks >= 66) return 2.00;
    if (totalMarks >= 62) return 1.67;
    if (totalMarks >= 58) return 1.33;
    if (totalMarks >= 55) return 1.00;
    return 0.0;
}

int main() {
    float midTerm, finalExam, classTests[4], classTestAverage = 0, attendanceMarks;
    int classesAttended;


    cout << "Enter Mid-term marks (out of 30): ";
    cin >> midTerm;

    cout << "Enter Final Exam marks (out of 40): ";
    cin >> finalExam;

    cout << "Enter marks for 4 class tests (each out of 20): ";
    for (int i = 0; i < 4; i++) {
        cin >> classTests[i];
    }

    cout << "Enter number of classes attended (out of 24): ";
    cin >> classesAttended;


    sort(classTests, classTests + 4, greater<float>());
    classTestAverage = (classTests[0] + classTests[1] + classTests[2]) / 3.0f;
    classTestAverage = (classTestAverage / 20.0f) * 20.0f;


    attendanceMarks = calculateAttendanceMarks(classesAttended);


    float totalMarks = midTerm + finalExam + classTestAverage + attendanceMarks;


    float grade = calculateGrade(totalMarks);


    cout << fixed << setprecision(2);
    cout << "\n--- Results ---\n";
    cout << "Mid-term Marks: " << midTerm << "/30\n";
    cout << "Final Exam Marks: " << finalExam << "/40\n";
    cout << "Average of Best Three Class Tests (scaled): " << classTestAverage << "/20\n";
    cout << "Attendance Marks: " << attendanceMarks << "/10\n";
    cout << "Total Marks: " << totalMarks << "/100\n";
    cout << "Grade: " << grade << endl;

    return 0;
}

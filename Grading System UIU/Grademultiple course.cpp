#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int TOTAL_CLASSES = 24;
const int FULL_ATTENDANCE_MARKS = 10;
const int MIDTERM_MAX_1CREDIT = 20;
const int FINAL_EXAM_MAX_1CREDIT = 30;
const int MIDTERM_MAX_3CREDIT = 30;
const int FINAL_EXAM_MAX_3CREDIT = 40;
const int CLASS_TEST_MAX = 20;

struct Course {
    string name;
    int credits;
    float midTerm, finalExam, classTests[4], classTestAverage, attendanceMarks, totalMarks, evaluationMarks, grade;
    string letterGrade;
};

float calculateAttendanceMarks(int classesAttended) {
    if (classesAttended >= 20) {
        return FULL_ATTENDANCE_MARKS;
    } else {
        int missedClasses = TOTAL_CLASSES - classesAttended;
        float deduction = missedClasses * 0.25f;
        return max(0.0f, FULL_ATTENDANCE_MARKS - deduction);
    }
}

void calculateGrade(float totalMarks, float &gpa, string &letterGrade) {
    if (totalMarks >= 90) {
        gpa = 4.00;
        letterGrade = "A";
    } else if (totalMarks >= 86) {
        gpa = 3.67;
        letterGrade = "A-";
    } else if (totalMarks >= 82) {
        gpa = 3.33;
        letterGrade = "B+";
    } else if (totalMarks >= 78) {
        gpa = 3.00;
        letterGrade = "B";
    } else if (totalMarks >= 74) {
        gpa = 2.67;
        letterGrade = "B-";
    } else if (totalMarks >= 70) {
        gpa = 2.33;
        letterGrade = "C+";
    } else if (totalMarks >= 66) {
        gpa = 2.00;
        letterGrade = "C";
    } else if (totalMarks >= 62) {
        gpa = 1.67;
        letterGrade = "C-";
    } else if (totalMarks >= 58) {
        gpa = 1.33;
        letterGrade = "D+";
    } else if (totalMarks >= 55) {
        gpa = 1.00;
        letterGrade = "D";
    } else {
        gpa = 0.0;
        letterGrade = "F";
    }
}

int main() {
    int numCourses;
    vector<Course> courses;
    float totalGradePoints = 0, totalCredits = 0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        Course course;
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin.ignore();
        getline(cin, course.name);

        cout << "Credits (1 or 3): ";
        cin >> course.credits;

        if (course.credits == 1) {
            cout << "Enter Mid-term marks (out of 20): ";
            cin >> course.midTerm;

            cout << "Enter Final Exam marks (out of 30): ";
            cin >> course.finalExam;
        } else if (course.credits == 3) {
            cout << "Enter Mid-term marks (out of 30): ";
            cin >> course.midTerm;

            cout << "Enter Final Exam marks (out of 40): ";
            cin >> course.finalExam;
        }

        cout << "Enter marks for 4 class tests (each out of 20): ";
        for (int j = 0; j < 4; j++) {
            cin >> course.classTests[j];
        }

        cout << "Enter number of classes attended (out of 24): ";
        int classesAttended;
        cin >> classesAttended;

        if (course.credits == 1) {
            cout << "Enter Evaluation marks (out of 20): ";
            cin >> course.evaluationMarks;
        }

        sort(course.classTests, course.classTests + 4, greater<float>());
        course.classTestAverage = (course.classTests[0] + course.classTests[1] + course.classTests[2]) / 3.0f;

        course.attendanceMarks = calculateAttendanceMarks(classesAttended);

        if (course.credits == 1) {
            course.totalMarks = course.midTerm + course.finalExam + course.classTestAverage + course.attendanceMarks + course.evaluationMarks;
        } else if (course.credits == 3) {
            course.totalMarks = course.midTerm + course.finalExam + course.classTestAverage + course.attendanceMarks;
        }

        calculateGrade(course.totalMarks, course.grade, course.letterGrade);

        totalGradePoints += course.grade * course.credits;
        totalCredits += course.credits;

        courses.push_back(course);
    }

    float averageCGPA = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\n--- Results ---\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.name << " (" << course.credits << " credits)\n";
        cout << "  Total Marks: " << course.totalMarks << "/100\n";
        cout << "  Grade: " << course.grade << " (" << course.letterGrade << ")\n";
    }
    cout << "\nOverall CGPA: " << averageCGPA << endl;

    return 0;
}

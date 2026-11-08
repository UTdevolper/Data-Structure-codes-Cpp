//<---------------------By UTDevolper-------------------->
#include <iostream>
using namespace std;

int main()
{
    int student_marks[10] = {20, 50, 60, 80, 90, 70, 45, 16, 89, 99};

    int total_marks = 0;
    int highest_marks = student_marks[0];
    int lowest_marks = student_marks[0];
    int passed_students = 0;
    int failed_students = 0;

    cout << "Following are the marks of students:\n";

    for(int i = 0; i < 10; i++)
    {
        cout << "Marks of student " << i + 1 << " = "
             << student_marks[i] << endl;

        total_marks += student_marks[i];

        if(student_marks[i] > highest_marks)
            highest_marks = student_marks[i];

        if(student_marks[i] < lowest_marks)
            lowest_marks = student_marks[i];

        if(student_marks[i] >= 50)
            passed_students++;
        else
            failed_students++;
    }

    float avg_marks = total_marks / 10.0;

    cout << "\nAverage Marks = " << avg_marks << endl;
    cout << "Highest Marks = " << highest_marks << endl;
    cout << "Lowest Marks = " << lowest_marks << endl;

    cout << "\nNo of Passed Students = " << passed_students << endl;
    cout << "No of Failed Students = " << failed_students << endl;

    return 0;
}
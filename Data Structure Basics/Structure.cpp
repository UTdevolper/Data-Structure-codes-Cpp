#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int emp_id;
    string emp_name;
    double basic_salary;
    double allowance;
};

double Calculate_GrossSalary(Employee emp)
{
    return emp.basic_salary + emp.allowance;
}

double Calculate_Tax(double gross_salary)
{
    if(gross_salary > 100000)
        return gross_salary * 0.05;
    else
        return gross_salary * 0.02;
}

void Show_Details(Employee emp)
{
    double gross_salary = Calculate_GrossSalary(emp);
    double tax = Calculate_Tax(gross_salary);
    double final_salary = gross_salary - tax;

    cout << "\n----------- EMPLOYEE DETAILS -----------\n";

    cout << "Employee Name       : " << emp.emp_name << endl;
    cout << "Employee ID         : " << emp.emp_id << endl;
    cout << "Allowance           : " << emp.allowance << endl;
    cout << "Basic Salary        : " << emp.basic_salary << endl;
    cout << "Gross Salary        : " << gross_salary << endl;
    cout << "Tax Deducted        : " << tax << endl;
    cout << "Final Salary        : " << final_salary << endl;
}

int main()
{
    Employee emp;

    cout << "Enter Employee Name: ";
    cin >> emp.emp_name;

    cout << "Enter Employee ID: ";
    cin >> emp.emp_id;

    cout << "Enter Allowance: ";
    cin >> emp.allowance;

    cout << "Enter Basic Salary: ";
    cin >> emp.basic_salary;

    Show_Details(emp);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string name;
    double salary;
    string department;
};

void addEmployee(vector<Employee>& employees) {
    Employee newEmployee;
    cout << "Enter employee name: ";
    cin.ignore(); // Ignore any newline character in the buffer
    getline(cin, newEmployee.name);
    cout << "Enter employee salary: ";
    cin >> newEmployee.salary;
    cout << "Enter employee department: ";
    cin.ignore(); // Ignore any newline character in the buffer
    getline(cin, newEmployee.department);

    employees.push_back(newEmployee);
    cout << "Employee added successfully.\n";
}

void displayAllEmployees(const vector<Employee>& employees) {
    cout << "\n----- All Employees -----\n";
    for (const auto& employee : employees) {
        cout << "Name: " << employee.name << ", Salary: $" << employee.salary
             << ", Department: " << employee.department << endl;
    }
}

void searchEmployee(const vector<Employee>& employees, const string& name) {
    cout << "\n----- Search Results -----\n";
    bool found = false;
    for (const auto& employee : employees) {
        if (employee.name == name) {
            cout << "Name: " << employee.name << ", Salary: $" << employee.salary
                 << ", Department: " << employee.department << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Employee not found.\n";
    }
}

int main() {
    vector<Employee> employees;

    while (true) {
        cout << "\n----- Employee Management Menu -----\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Exit\n";

        int choice;
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                displayAllEmployees(employees);
                break;
            case 3: {
                string searchName;
                cout << "Enter employee name to search: ";
                cin.ignore(); // Ignore any newline character in the buffer
                getline(cin, searchName);
                searchEmployee(employees, searchName);
                break;
            }
            case 4:
                cout << "Exiting the Employee Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 4.\n";
        }
    }

    return 0;
}

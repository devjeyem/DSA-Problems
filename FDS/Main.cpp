#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student
{
    string studentId;
    string surName;
    string  firstName;
    string birthDate;
    char gender;
};

void createNewFile(string activeFile, vector<Student> students); // Create a File.
void displayStudentRecords(string activeFile, vector<Student> students); // Display of current record.

int main ()
{
    /*string activeFile = "sample.txt";
    vector<Student> students;
    cin >> activeFile;
    // Test creating a new file
    createNewFile(activeFile, students);*/

    std::string activeFile = "sample.txt";
    std::vector<Student> students = 
    {
        {"01-1-00177", "ABELLA", "JOCELYN", "1/1/90", 'F'},
        {"98-1-00754", "AURE REV", "RHIZZA", "1/2/90", 'M'},
        {"01-1-00385", "AUSTERO", "AGNES MARIE", "1/3/90", 'F'},
        {"01-1-01114", "BALDO", "DEMETRIO", "1/4/90", 'M'},
        {"01-1-00706", "CACHUELA", "DAISY", "1/5/90", 'F'},
        {"01-1-01143", "CADIZ", "ADELFA", "1/6/90", 'F'}
    };

    char choice;
    do
    {
        std::cout << "Active File : [" << activeFile << "]\n";
        std::cout << "[1] Create New File [2] Open an Existing File [3] Manage Data [4] Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case '1':
                createNewFile(activeFile,students);
                break;
            case '3':
                displayStudentRecords(activeFile,students);
                break;

            case '4':
                cout << "Exit program.\n";
                break;
            default:
                cout << "Choose again.\n";
        }
    } while (choice!='4');

    return 0;
}

void createNewFile(string activeFile, vector<Student> students) //Create a File. (Checked)
{   
    cout << "Enter new file name: ";
    cin >> activeFile;
    ofstream outStudRec(activeFile);
    if (outStudRec)
    {
        std::cout << "File created successfully. :)\n";
        students.clear();
    }
    else
    {
        std::cout << "File not created. :( \n";
    }
}

void displayStudentRecords(string activeFile, vector<Student> students)
{
    cout << "Active File : [" << activeFile << "]" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Rec\tStudent ID\tSurname\t\tFirstname\tBirthDate\tSex" << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << i + 1 << "\t" << students[i].studentId << "\t" 
             << setw(10) << left <<  students[i].surName << "\t" 
             << setw(10) << left << students[i].firstName << "\t" << students[i].birthDate << "\t\t" 
             << students[i].gender << endl;

    }
    cout << "---------------------------------------------------------------------------" << endl;
}


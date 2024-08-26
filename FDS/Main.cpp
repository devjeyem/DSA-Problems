#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ctype.h>

using namespace std;

struct Student
{
    string studentId;
    string surName;
    string  firstName;
    string birthDate;
    char gender;
};

string createNewFile(vector<Student> &students); // Create a File.
void displayStudentRecords(string &activeFile, vector<Student> &students); // Display of current record.
void manageData(string &activeFile,  vector<Student> &students); // Manage data button.
void saveFileButton(string &activeFile,  vector<Student> &students); // Save current file.
void addRecordButton(vector<Student> &students); //Implement the addRecord buttion.
void editRecordButton(vector<Student> &students, int i); //Edit existing records.
void deleteRecordButton(vector<Student> &students, int i); //Delete a record.
void sortBySurnameButton(vector <Student> &students); //Sort by Surname button.
void sortByIdButton(vector <Student> &students); // Sort by studentID.
void openExistingFileButton(string &activeFile, std::vector<Student> &students); //Open existing file.

int main ()
{
    /*string activeFile = "sample.txt";
    vector<Student> students;
    cin >> activeFile;
    // Test creating a new file
    createNewFile(activeFile, students);*/
    system("cls");
    string activeFile = "";
    vector<Student> students;
    char choice;
    do
    {
        cout << "Active File : [" << (activeFile.empty() ? "None" : activeFile) << "]" << endl;
        cout << "[1] Create New File [2] Open an Existing File [3] Manage Data [4] Exit " << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case '1':
                activeFile = createNewFile(students);
                break;
            case '2':
                openExistingFileButton(activeFile, students);
                break;
            case '3':
                if (!activeFile.empty())
                {
                    manageData(activeFile, students);
                }
                else
                {
                    cout << "No file open! Please open or create a file first." << endl;
                }
                break;
            case '4':
                cout << "Thank you for using! :)\n";
                break;
            default:
                cout << "Choose again.\n";
        }
    } while (choice!='4');

    return 0;
}

string createNewFile(vector<Student> &students) //Create a File. (Checked)
{   
    string newFileName;
    cout << "Enter new file name: ";
    cin >> newFileName;
    ofstream outStudRec(newFileName);
    if (outStudRec.is_open())
    {
        cout << "File created successfully. :)\n";
        students.clear();
    }
    else
    {
        cout << "File not created. :( \n";
    }
    return newFileName;
}

void displayStudentRecords(string &activeFile, vector<Student> &students) //Working
{
    cout << "Active File : [" << activeFile << "]" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Rec\tStudent ID\tSurname\t\tFirstname\tBirthDate\tSex" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << i + 1 << "\t" << students[i].studentId << "\t" 
             << setw(10) << left <<  students[i].surName << "\t" 
             << setw(10) << left << students[i].firstName << "\t" << students[i].birthDate << "\t\t" 
             << students[i].gender << endl;
    }
    cout << "---------------------------------------------------------------------------" << endl;
}

void manageData(string &activeFile, vector<Student> &students) 
{
    char choice;
    do
    {
        displayStudentRecords(activeFile,students);
        cout << "[A]dd [E]dit [D]elete [S]ort sa[V]e e[X]it" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch(toupper(choice))
        {
            case 'A':
            {
                addRecordButton(students);
                break;
            }
            case 'E':
            {
                int index;
                cout << "Enter record number you wish to edit: ";
                cin >> index;
                editRecordButton(students,index - 1);
                break;
            }
            case 'D':
            {
                int index;
                cout << "Enter record number you wish to delete: ";
                cin >> index;
                deleteRecordButton(students, index - 1);
                break;
            }
            case 'S':
            {
                char c;
                cout << "Sort by     : [S]urname [I]D "<< endl;
                cout << "Enter choice: ";
                cin >> c;
                switch(toupper(c))
                    case 'S':
                    {
                        sortBySurnameButton(students);
                        break;
                    }
                    case 'I':
                    {
                        sortByIdButton(students);
                        break;
                    }
                break;
            }
            case 'V':
            {
                saveFileButton(activeFile,students);
                break;
            }
            case 'X' :
            {
                cout << "Exiting Manage Data Option..." << endl; 
                break;
            }
            default:
            {
                cout << "Enter valid choice please..."  << endl;

            }
           
        }
    } while (choice!= 'X'  && choice != 'x');
}

void saveFileButton(string &activeFile, vector<Student> &students)
{
    ofstream outStudRec(activeFile);
    if (!outStudRec)
    {
        cout << "Error / Cannot save!" << endl;
        return;
    }

    for (int i = 0; i< students.size(); i++)
    {
        outStudRec << students[i].studentId << " " << students[i].surName << " "
                   << students[i].firstName << " " << students[i].birthDate << " "
                   << students[i].gender << endl;
    }
    cout << "File saved successfully!" << endl;
}

void addRecordButton(vector<Student> &students)
{
    Student newStudent;
    cout << "Rec:[" << students.size() + 1 << "]" << endl;
    cout << endl;
    cout << "Student ID : ";
    cin  >> newStudent.studentId;
    cout << "Surname    : ";
    cin.ignore();
    getline(cin,newStudent.surName);
    cout << "Firstname  : ";
    getline(cin,newStudent.firstName);
    cout << "Birthdate  : ";
    cin >> newStudent.birthDate;
    cout << "Sex        : ";
    cin >> newStudent.gender;

    students.push_back(newStudent);
    cout << "Added successfully!"  << endl;
}

void editRecordButton(vector<Student> &students, int i)
{
    int size = students.size();
    if (i < 0 || i >= size)
    {
        cout << "Invalid number! Try again." << endl;
        return;
    }
    cout << endl;
    Student &student = students[i];
    cout << "Rec:[" << i+1 << "]"  << endl;
    cout << "\t\tCurrent\t\tNew" << endl;
    cout << "Student ID\t:  " << student.studentId << "\t: ";
    string newStudentId;
    cin  >> newStudentId;
    if (!newStudentId.empty())
    {
        student.studentId = newStudentId;
    }

    cout << "Surname   \t: " << student.surName << "\t: ";
    string newSurname;
    cin.ignore();
    getline(cin,newSurname);
    if (!newSurname.empty())
    {
        student.surName = newSurname;
    }

    cout << "Firstname \t: " << student.firstName << "\t: ";
    string newFirstName;
    getline(cin,newFirstName);
    if (!newFirstName.empty())
    {
        student.firstName = newFirstName;
    }

    cout <<  "Birthdate \t: " << student.birthDate << "\t: ";
    string newBirthDate;
    cin >> newBirthDate;
    if (!newBirthDate.empty())
    {
        student.birthDate = newBirthDate;
    }

    cout << "Sex        \t: " << student.gender << "\t\t: ";
    char newSex;
    cin >> newSex;
    if (newSex == 'M' || newSex == 'F')
    {
        student.gender = newSex;
    }
    cout << "Record successfully edited!" << endl;
}

void deleteRecordButton(vector<Student> &students, int i)
{
    int size = students.size();
    if (i < 0 || i >= size)
    {
        cout << "Invalid record number. Try again.\n";
        return;
    }

    students.erase(students.begin() + i);
    cout << "Record deleted successfully.\n";
}

void sortBySurnameButton(vector <Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j<students.size()-i-1; j++)
        {
            if (students[j].surName> students[j+1].surName)
            {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void sortByIdButton(vector <Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j<students.size()-i-1; j++)
        {
            if (students[j].studentId> students[j+1].studentId)
            {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void openExistingFileButton(string &activeFile, vector<Student> &students)
{
    cout << "Enter filename to open: ";
    cin >> activeFile;

    ifstream inStudRec(activeFile);
    if (!inStudRec)
    {
        cout << "Error opening file: " << activeFile << endl;
        return;
    }
    students.clear();

    while (inStudRec)
    {
        Student student;
        inStudRec >> student.studentId >> student.surName;

        string firstNamePart;
        student.firstName = "";
        while (inStudRec >> firstNamePart)
        {
            if (firstNamePart.find('/') != string::npos)
            {
                student.birthDate = firstNamePart;
                break;
            }
            if (!student.firstName.empty())
            {
                student.firstName += " ";
            }
            student.firstName += firstNamePart;
        }

        inStudRec >> student.gender;
        if (inStudRec)
        {
            students.push_back(student);
        }
    }

    inStudRec.close();
    cout << "File opened successfully: " << activeFile << endl;
}

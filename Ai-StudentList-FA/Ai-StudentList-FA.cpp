// Ai-StudentList-FA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


class Student {
private:
    string firstName;
    string lastName;
    int grade;
public:
    Student(){}
    Student(string firstName, string lastName, int grade) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->grade = grade;
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    int getGrade() {
        return grade;
    }
    void setFirstName(string firstName) {
        this->firstName = firstName;
    }
    void setLastName(string lastName) {
        this->lastName = lastName;
    }
    void setGrade(int grade) {
        this->grade = grade;
    }

};
int main()
{
    vector<Student> studentList;
    
    string firstName;
    string lastName;
    int grade;
    
    string remainder;
    
    ifstream myFile("example.txt");
    string delimeter = " ";
    string line;
    
    //Opening file
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            //Separating first, last name and grade 
            firstName = line.substr(0, line.find(delimeter));
            remainder = line.substr(line.find(delimeter)+1);
            lastName = remainder.substr(0, remainder.find(delimeter));
            remainder = remainder.substr(remainder.find(delimeter) + 1);
            grade = stoi(remainder);
            //Adding student to student list
            Student student(firstName, lastName, grade);
            studentList.push_back(student);
                    
       }

       
    }
    
    //Sorting student grades from highest to lowest
    int length = studentList.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (studentList[j].getGrade() > studentList[j + 1].getGrade()) {
                Student temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }     
    }
   
    //Output 
    for (int i = length - 1; i >= 0; i--) {
        cout << studentList[i].getFirstName() << " " << studentList[i].getLastName() << " " << studentList[i].getGrade() << endl;
    }
    cout << endl;

    myFile.close();
}

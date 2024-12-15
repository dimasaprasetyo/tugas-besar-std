#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef struct Student studentInfo;
typedef struct ElmStudent *elmStudent;

struct Student {
    string nim;
    string name;
    string code;
    string gender;
};

struct ElmStudent {
    studentInfo info;
    elmStudent next;
};

//Fungsi - fungsi mahasiswa
void createStudentList(elmStudent& head);
elmStudent createNewStudent(string nim, string name, string code, string gender);
void insertStudent(elmStudent& head, elmStudent newStudent);
void deleteStudent(elmStudent& head, string nim);
void showAllStudents(elmStudent head);
elmStudent findStudentByNim(elmStudent head, const string& nim);
elmStudent findStudent(elmStudent head, const string& nim);
elmStudent findStudentByName(elmStudent head, const string& name);

#endif // STUDENT_H_INCLUDED

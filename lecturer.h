#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef struct Lecturer lecturerInfo;
typedef struct ElmLecturer *elmLecturer;

struct Lecturer {
    string nidn;
    string name;
    string code;
    string gender;
};

struct ElmLecturer {
    lecturerInfo info;
    elmLecturer next;
};

// Contract methods
void createLecturerList(elmLecturer& lecturerList);
elmLecturer findLecturer(elmLecturer lecturerList, const string& name);

#endif // LECTURER_H_INCLUDED

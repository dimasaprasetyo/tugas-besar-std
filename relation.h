#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "lecturer.h"
#include "student.h"

struct Relation {
    elmLecturer lecturer;
    elmStudent student;
};

typedef struct Relation relationInfo;
typedef struct ElmRelation *elmRelation;

struct ElmRelation {
    relationInfo info;
    elmRelation next;
};

//Fungsi - fungsi relasi
void createRelationList(elmRelation& head);
elmRelation createNewRelation(elmLecturer lecturer, elmStudent student);
void insertRelation(elmRelation& head, elmRelation newRelation);
void deleteRelation(elmRelation& head, elmLecturer lecturer, elmStudent student);
void showAllRelations(elmRelation relationList);
void editRelation(elmRelation& head, const string& nim, elmLecturer newLecturer);
void showChildWithParent(elmRelation head);
int countParentsForChild(elmRelation head, const string& nim);
int countChildWithoutParent(elmRelation head, elmStudent studentList);

#endif

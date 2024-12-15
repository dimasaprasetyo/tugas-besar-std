#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "lecturer.h"  // Header file untuk dosen
#include "student.h"   // Header file untuk mahasiswa

struct Relation {
    elmLecturer lecturer; // Pointer ke elemen dosen
    elmStudent student;   // Pointer ke elemen mahasiswa
};

typedef struct Relation relationInfo;
typedef struct ElmRelation *elmRelation;

struct ElmRelation {
    relationInfo info;
    elmRelation next;
};


//void createRelationList(elmRelation &relationList);
//elmRelation createNewRelation(elmLecturer lecturer, elmStudent student);
//void insertRelation(elmRelation &relationList, elmRelation newRelation);
//void deleteRelation(elmRelation &relationList, elmLecturer lecturer, elmStudent student);
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

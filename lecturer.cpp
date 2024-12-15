#include <iostream>
#include "lecturer.h"

using namespace std;

void createLecturerList(elmLecturer& lecturerList) {
    lecturerList = nullptr; // Inisialisasi list dosen sebagai kosong
}

elmLecturer findLecturer(elmLecturer lecturerList, const string& name) {
    elmLecturer current = lecturerList;
    while (current != nullptr) {
        if (current->info.name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

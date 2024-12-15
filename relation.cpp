#include "relation.h"

void createRelationList(elmRelation& head) {
    head = NULL;
}

elmRelation createNewRelation(elmLecturer lecturer, elmStudent student) {
    elmRelation newRelation = new ElmRelation;
    newRelation->info.lecturer = lecturer;
    newRelation->info.student = student;
    newRelation->next = NULL;
    return newRelation;
}

void insertRelation(elmRelation& head, elmRelation newRelation) {
    if (head == NULL) {
        head = newRelation;
    } else {
        elmRelation temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRelation; // Menambahkan elemen di akhir
    }
}

void deleteRelation(elmRelation& head, elmLecturer lecturer, elmStudent student) {
    if (head == NULL) {
        cout << "List relasi kosong.\n";
        return;
    }

    elmRelation prev = NULL, current = head;
    while (current != NULL &&
           (current->info.lecturer != lecturer || current->info.student != student)) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Relasi tidak ditemukan.\n";
        return;
    }

    if (prev == NULL) {
        head = current->next; // Hapus elemen pertama
    } else {
        prev->next = current->next; // Hapus elemen di tengah/akhir
    }

    delete current;
    cout << "Relasi berhasil dihapus.\n";
}

void showAllRelations(elmRelation head) {
    if (head == NULL) {
        cout << "Tidak ada relasi.\n";
        return;
    }

    elmRelation temp = head;
    while (temp != NULL) {
        cout << "Dosen: " << temp->info.lecturer->info.name
             << " - Mahasiswa: " << temp->info.student->info.name << endl;
        temp = temp->next;
    }
}

void showChildWithParent(elmRelation head) {
    if (head == NULL) {
        cout << "Tidak ada relasi yang tersedia.\n";
        return;
    }

    elmRelation current = head;
    while (current != NULL) {
        cout << "Mahasiswa: " << current->info.student->info.name
             << " (NIM: " << current->info.student->info.nim << ") "
             << "berelasi dengan Dosen: " << current->info.lecturer->info.name
             << " (Kode: " << current->info.lecturer->info.code << ").\n";
        current = current->next;
    }
}

int countParentsForChild(elmRelation head, const string& nim) {
    int count = 0;
    elmRelation current = head;
    while (current != NULL) {
        if (current->info.student->info.nim == nim) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int countChildWithoutParent(elmStudent studentList, elmRelation relationList) {
    int count = 0;
    elmStudent currentStudent = studentList;

    while (currentStudent != NULL) {
        bool hasParent = false;

        elmRelation currentRelation = relationList;
        while (currentRelation != NULL) {
            if (currentRelation->info.student == currentStudent) {
                hasParent = true;
                break;
            }
            currentRelation = currentRelation->next;
        }

        if (!hasParent) {
            count++;
        }

        currentStudent = currentStudent->next;
    }

    return count;
}

void editRelation(elmRelation& head, const string& nim, elmLecturer newLecturer) {
    elmRelation current = head;
    while (current != NULL) {
        if (current->info.student->info.nim == nim) {
            current->info.lecturer = newLecturer; // Mengganti dosen
            cout << "Relasi berhasil diperbarui.\n";
            return;
        }
        current = current->next;
    }
    cout << "Relasi untuk mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

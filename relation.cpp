#include "relation.h"

void createRelationList(elmRelation& head) {
    head = nullptr; // Inisialisasi list relasi sebagai kosong
}

elmRelation createNewRelation(elmLecturer lecturer, elmStudent student) {
    elmRelation newRelation = new ElmRelation;
    newRelation->info.lecturer = lecturer;
    newRelation->info.student = student;
    newRelation->next = nullptr;
    return newRelation;
}

void insertRelation(elmRelation& head, elmRelation newRelation) {
    if (head == nullptr) {
        head = newRelation; // Jika list kosong, elemen menjadi head
    } else {
        elmRelation temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Iterasi hingga elemen terakhir
        }
        temp->next = newRelation; // Menambahkan elemen di akhir
    }
}

void deleteRelation(elmRelation& head, elmLecturer lecturer, elmStudent student) {
    if (head == nullptr) {
        cout << "List relasi kosong.\n";
        return;
    }

    elmRelation prev = nullptr, current = head;
    while (current != nullptr &&
           (current->info.lecturer != lecturer || current->info.student != student)) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Relasi tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) {
        head = current->next; // Hapus elemen pertama
    } else {
        prev->next = current->next; // Hapus elemen di tengah/akhir
    }

    delete current;
    cout << "Relasi berhasil dihapus.\n";
}

void showAllRelations(elmRelation head) {
    if (head == nullptr) {
        cout << "Tidak ada relasi.\n";
        return;
    }

    elmRelation temp = head;
    while (temp != nullptr) {
        cout << "Dosen: " << temp->info.lecturer->info.name
             << " - Mahasiswa: " << temp->info.student->info.name << endl;
        temp = temp->next;
    }
}

void showChildWithParent(elmRelation head) {
    if (head == nullptr) {
        cout << "Tidak ada relasi yang tersedia.\n";
        return;
    }

    elmRelation current = head;
    while (current != nullptr) {
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
    while (current != nullptr) {
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

    while (currentStudent != nullptr) {
        bool hasParent = false;

        elmRelation currentRelation = relationList;
        while (currentRelation != nullptr) {
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
    while (current != nullptr) {
        if (current->info.student->info.nim == nim) {
            current->info.lecturer = newLecturer; // Mengganti dosen
            cout << "Relasi berhasil diperbarui.\n";
            return;
        }
        current = current->next;
    }
    cout << "Relasi untuk mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

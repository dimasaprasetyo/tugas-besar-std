#include "student.h"

// Membuat list kosong mahasiswa
void createStudentList(elmStudent& head) {
    head = NULL;
}

// Membuat elemen mahasiswa baru
elmStudent createNewStudent(string nim, string name, string code, string gender) {
    elmStudent newStudent = new ElmStudent;
    newStudent->info.nim = nim;
    newStudent->info.name = name;
    newStudent->info.code = code;
    newStudent->info.gender = gender;
    newStudent->next = NULL;
    return newStudent;
}

//Menambahkan dummy data untuk student
void addDummyStudents(elmStudent& studentList) {
    elmStudent student1 = new ElmStudent;
    student1->info.nim = "103042310105";
    student1->info.name = "Dimas";
    student1->info.code = "PJJ";
    student1->info.gender = "L";
    student1->next = NULL;

    studentList = student1;
}

// Menambahkan elemen mahasiswa ke dalam list
void insertStudent(elmStudent& head, elmStudent newStudent) {
    if (head == NULL) {
        head = newStudent;
    } else {
        elmStudent temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Menghapus mahasiswa berdasarkan NIM
void deleteStudent(elmStudent& head, string nim) {
    if (head == NULL) {
        cout << "List kosong. Tidak ada mahasiswa untuk dihapus.\n";
        return;
    }
    if (head->info.nim == nim) {
        elmStudent temp = head;
        head = head->next;
        delete temp;
        cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
        return;
    }
    elmStudent temp = head;
    while (temp->next != NULL && temp->next->info.nim != nim) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    } else {
        elmStudent toDelete = temp->next;
        temp->next = toDelete->next; // Elemen yang dihapus akan dilewati
        delete toDelete; // Menghapus elemen yang dimaksud
        cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
    }
}

// Menampilkan semua mahasiswa dalam list
void showAllStudents(elmStudent head) {
    if (head == NULL) {
        cout << "List kosong. Tidak ada mahasiswa untuk ditampilkan.\n";
        return;
    }
    cout << "\nDaftar Mahasiswa:\n";
    elmStudent temp = head;
    while (temp != NULL) {
        cout << "NIM: " << temp->info.nim
             << ", Nama: " << temp->info.name
             << ", Kode Prodi: " << temp->info.code
             << ", Gender: " << temp->info.gender << endl;
        temp = temp->next;
    }
}

// Mencari mahasiswa berdasarkan NIM
elmStudent findStudentByNim(elmStudent head, const string& nim) {
    elmStudent current = head;
    while (current != NULL) {
        if (current->info.nim == nim) {
            return current; // Mahasiswa ditemukan
        }
        current = current->next;
    }
    return NULL; // Jika tidak ditemukan
}

// Mencari mahasiswa berdasarkan nama
elmStudent findStudentByName(elmStudent head, const string& name) {
    elmStudent current = head;
    while (current != NULL) {
        if (current->info.name == name) {
            return current; // Mahasiswa ditemukan
        }
        current = current->next;
    }
    return NULL; // Jika tidak ditemukan
}

elmStudent findStudent(elmStudent head, const string& nim) {
    elmStudent current = head;
    while (current != NULL) {
        if (current->info.nim == nim) {
            return current; // Mahasiswa ditemukan
        }
        current = current->next;
    }
    return NULL; // Jika tidak ditemukan
}

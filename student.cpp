#include "student.h"

// Membuat list kosong
void createStudentList(elmStudent& head) {
    head = nullptr; // Head diinisialisasi sebagai nullptr
}

// Membuat elemen mahasiswa baru
elmStudent createNewStudent(string nim, string name, string code, string gender) {
    elmStudent newStudent = new ElmStudent; // Alokasi memori
    newStudent->info.nim = nim;
    newStudent->info.name = name;
    newStudent->info.code = code;
    newStudent->info.gender = gender;
    newStudent->next = nullptr; // Elemen baru selalu diakhiri dengan nullptr
    return newStudent;
}

// Menambahkan elemen mahasiswa ke dalam list
void insertStudent(elmStudent& head, elmStudent newStudent) {
    if (head == nullptr) {
        head = newStudent; // Jika list kosong, elemen menjadi head
    } else {
        elmStudent temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Iterasi hingga elemen terakhir
        }
        temp->next = newStudent; // Menambahkan elemen di akhir
    }
}

// Menghapus elemen mahasiswa berdasarkan NIM
void deleteStudent(elmStudent& head, string nim) {
    if (head == nullptr) {
        cout << "List kosong. Tidak ada mahasiswa untuk dihapus.\n";
        return;
    }
    if (head->info.nim == nim) {
        elmStudent temp = head;
        head = head->next; // Head berpindah ke elemen berikutnya
        delete temp; // Menghapus elemen awal
        cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
        return;
    }
    elmStudent temp = head;
    while (temp->next != nullptr && temp->next->info.nim != nim) {
        temp = temp->next; // Iterasi untuk menemukan elemen
    }
    if (temp->next == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    } else {
        elmStudent toDelete = temp->next;
        temp->next = toDelete->next; // Melewati elemen yang akan dihapus
        delete toDelete; // Hapus elemen
        cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
    }
}

// Menampilkan semua mahasiswa dalam list
void showAllStudents(elmStudent head) {
    if (head == nullptr) {
        cout << "List kosong. Tidak ada mahasiswa untuk ditampilkan.\n";
        return;
    }
    cout << "\nDaftar Mahasiswa:\n";
    elmStudent temp = head;
    while (temp != nullptr) {
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
    while (current != nullptr) {
        if (current->info.nim == nim) {
            return current; // Mahasiswa ditemukan
        }
        current = current->next;
    }
    return nullptr; // Jika tidak ditemukan
}

// Mencari mahasiswa berdasarkan nama
elmStudent findStudentByName(elmStudent head, const string& name) {
    elmStudent current = head;
    while (current != nullptr) {
        if (current->info.name == name) {
            return current; // Mahasiswa ditemukan
        }
        current = current->next;
    }
    return nullptr; // Jika tidak ditemukan
}

elmStudent findStudent(elmStudent head, const string& nim) {
    elmStudent current = head;
    while (current != nullptr) {
        if (current->info.nim == nim) {
            return current; // Mahasiswa ditemukan
        }
        current = current->next;
    }
    return nullptr; // Jika tidak ditemukan
}

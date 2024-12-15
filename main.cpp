#include <iostream>
#include "student.h"
#include "relation.h"
using namespace std;

elmLecturer lecturerList;
elmStudent studentList;
elmRelation relationList;

// Menu untuk Dosen
void menuDosen() {
    cout << "\n=== Menu Dosen ===\n";
    cout << "Fitur ini belum tersedia.\n";
}

// Menu Mahasiswa
void menuMahasiswa() {
    int choice;
    do {
        cout << "\n=== Menu Mahasiswa ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Tampilkan Mahasiswa\n";
        cout << "4. Pencarian Mahasiswa\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nim, name, code, gender;

                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, name);
                cout << "Masukkan Kode Prodi: ";
                cin >> code;
                cout << "Masukkan Gender (L/P): ";
                cin >> gender;

                elmStudent newStudent = createNewStudent(nim, name, code, gender);
                insertStudent(studentList, newStudent);
                cout << "Mahasiswa berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                string nim;
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                deleteStudent(studentList, nim);
                break;
            }
            case 3:
                showAllStudents(studentList);
                break;
            case 4: {
                cout << "\n=== Cari Mahasiswa ===\n";
                cout << "1. Cari Berdasarkan NIM\n";
                cout << "2. Cari Berdasarkan Nama\n";
                cout << "Pilihan Anda: ";
                int searchChoice;
                cin >> searchChoice;
                cin.ignore();

                if (searchChoice == 1) {
                    string nim;
                    cout << "Masukkan NIM: ";
                    getline(cin, nim);

                    elmStudent result = findStudentByNim(studentList, nim);
                    if (result != nullptr) {
                        cout << "Mahasiswa Ditemukan:\n";
                        cout << "NIM: " << result->info.nim << "\n";
                        cout << "Nama: " << result->info.name << "\n";
                        cout << "Kode: " << result->info.code << "\n";
                        cout << "Jenis Kelamin: " << result->info.gender << "\n";
                    } else {
                        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
                    }
                } else if (searchChoice == 2) {
                    string name;
                    cout << "Masukkan Nama: ";
                    getline(cin, name);

                    elmStudent result = findStudentByName(studentList, name);
                    if (result != nullptr) {
                        cout << "Mahasiswa Ditemukan:\n";
                        cout << "NIM: " << result->info.nim << "\n";
                        cout << "Nama: " << result->info.name << "\n";
                        cout << "Kode: " << result->info.code << "\n";
                        cout << "Jenis Kelamin: " << result->info.gender << "\n";
                    } else {
                        cout << "Mahasiswa dengan nama " << name << " tidak ditemukan.\n";
                    }
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            case 5:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 5);
}

void menuRelasi() {
    int choice;
    do {
        cout << "\n=== Menu Relasi ===\n";
        cout << "1. Tambah Relasi\n";
        cout << "2. Hapus Relasi\n";
        cout << "3. Tampilkan Relasi\n";
        cout << "4. Tampilkan Relasi\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string lecturerName, studentNim;
                cout << "Masukkan nama dosen: ";
                cin.ignore();
                getline(cin, lecturerName);
                cout << "Masukkan NIM mahasiswa: ";
                cin >> studentNim;

                elmLecturer lecturer = findLecturer(lecturerList, lecturerName);
                elmStudent student = findStudent(studentList, studentNim);

                if (lecturer == nullptr || student == nullptr) {
                    cout << "Dosen atau Mahasiswa tidak ditemukan.\n";
                } else {
                    elmRelation newRelation = createNewRelation(lecturer, student);
                    insertRelation(relationList, newRelation);
                    cout << "Relasi berhasil ditambahkan.\n";
                }
                break;
            }
            case 2: {
                string lecturerName, studentNim;
                cout << "Masukkan nama dosen: ";
                cin.ignore();
                getline(cin, lecturerName);
                cout << "Masukkan NIM mahasiswa: ";
                cin >> studentNim;

                elmLecturer lecturer = findLecturer(lecturerList, lecturerName);
                elmStudent student = findStudent(studentList, studentNim);

                if (lecturer == nullptr || student == nullptr) {
                    cout << "Dosen atau Mahasiswa tidak ditemukan.\n";
                } else {
                    deleteRelation(relationList, lecturer, student);
                }
                break;
            }
            case 3: {
                showAllRelations(relationList);
                break;
            }
            case 4: {
                cout << "\n=== Menampilkan Relasi ===\n";
                showChildWithParent(relationList);
                break;
            }
            case 5: {
                cout << "\n=== Hitung Parent untuk Child ===\n";
                cout << "Masukkan NIM mahasiswa: ";
                string nim;
                cin >> nim;

                int parentCount = countParentsForChild(relationList, nim);
                cout << "Mahasiswa dengan NIM " << nim << " memiliki " << parentCount << " parent.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
            }
        }
    } while (choice != 6);
}


int main() {
    createLecturerList(lecturerList);
    createStudentList(studentList);
    createRelationList(relationList);
    int pilihan;

    do {
        cout << "\n======================================\n";
        cout << "         SELAMAT DATANG               \n";
        cout << "======================================\n";
        cout << "1. Dosen\n";
        cout << "2. Mahasiswa\n";
        cout << "3. Relasi Dosen dan Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "======================================\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuDosen();
                break;
            case 2:
                menuMahasiswa();
                break;
            case 3:
                menuRelasi();
                break;
            case 4:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 4);

    return 0;
}

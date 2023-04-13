#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
private:
    string nama;
    string npm;
    double s1, s2, s3;
public:
    void setNama(string newNama) {
        this->nama = newNama;
    }

    void setNPM(string newNPM) {
        this->npm = newNPM;
    }

    void setNilai(double s1, double s2, double s3) {
        this->s1 = s1;
        this->s2 = s2;        
        this->s3 = s3;
    }

    double average() {
        double res = s1 + s2 + s3;
        return res / 3;
    }

    void print() {
        cout << this->nama << endl;
        cout << this->npm << endl;
        cout << this->average() << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    Mahasiswa data_mahasiswa[n];

    string nama, npm;
    double v1, v2, v3;

    for (int i = 0; i < n; ++i) {
        getline(cin, nama);
        getline(cin, npm);
        cin >> v1 >> v2 >> v3;
        cin.ignore();

        data_mahasiswa[i].setNama(nama);
        data_mahasiswa[i].setNPM(npm);
        data_mahasiswa[i].setNilai(v1, v2, v3);
    }

    Mahasiswa res = data_mahasiswa[0];
    for (int i = 1; i < n; ++i) {
        if (res.average() < data_mahasiswa[i].average()) {
            res = data_mahasiswa[i];
        }
    }
    
    res.print();
    return 0;
} 

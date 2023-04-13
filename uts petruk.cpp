#include <iostream>
#include <string>

// Class Person
class Person {
private:
    std::string name;
    std::string address;
    int age;

public:
    std::string getName() {
        return this->name;
    }

    std::string getAddress() {
        return this->address;
    }

    int getAge () {
        return this->age;
    }

    void setName (std::string newName) {
        this->name = newName;
    }

    void setAddress (std::string newAddress) {
        this->address = newAddress;
    }

    void setAge (int newAge) {
        this->age = newAge;
    }

};

/* swapInt
 * desc     : function that swap int value
 * usage    :
 *          int a = 50;
 *          int b = 10;
 *          swapInt(&a, &b);
 *          a == 10
 *          b == 50
 */
void swapInt(int *lhs, int *rhs) {
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

/* fungsi menghitung luas segitiga
 *
 */
double luasSegitiga (double alas, double tinggi) {
    return alas / 2 * tinggi;
}

using namespace std;

int main()
{
    const char * str = "hello world";       // c string
    int a = 100;
    int b = 200;

    cout << str << endl;
    cout << "a = " << a << endl;     // 100
    cout << "b = " << b << endl;     // 200

    swapInt(&a, &b);            // swap a and b
    cout << "a = " << a << endl;     // 200
    cout << "b = " << b << endl;     // 100

    Person orangBaik;
    orangBaik.setName("Siapa ya");
    orangBaik.setAddress("dimana ya");
    orangBaik.setAge(100);

    cout << "Nama saya = " << orangBaik.getName() << endl;
    cout << "Tinggal di = " << orangBaik.getAddress() << endl;
    cout << "Umur saya = " << orangBaik.getAge() << endl;

    return 0;
}
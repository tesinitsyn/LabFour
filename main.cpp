#include <iostream>
#include <cstdlib>

using namespace std;

class vect {
    int *p;
    int size;
public:
    // constructor
    vect() {
        size = 20;
        p = new int[size];
    }
    //initialisation constructor
    vect(int n) {
        if (n < 1) {
            cout << "Wrong borders\n" << n << "\n";
            exit(1);
        }
        size = n;
        p = new int[size];
    }

    //destructor
    ~vect() {
        delete[] p;
    }

    //probably getter idk
    int &element(int i) {
        if (i < 0 || i > size) {
            cout << "Wrong borders" << i << "\n";
            exit(2);
        }
        return (p[i]);
    }

    int get_size() const {
        return size;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << p[i] << " ";
        }
    }

    void input() {
        cout << "Input array: \n";
        for (int i = 0; i < size; i++) {
            cin >> p[i];
        }
    }

    void reshenie() {
        double maxs = p[0];
        int nom = 0;
        for (int i = 0; i < size; i++) {
            if (p[i] > maxs) {
                maxs = p[i];
                nom = i;
            }
        }
        int *massiv = new int[size - nom - 1];
        for (int i = nom + 1; i < size; i++) {
            massiv[i] = p[i];
        }
        cout << endl << "Полученный массив: ";
        int kol = 0;
        for (int i = nom + 1; i < size; i++) {
            cout << massiv[i] << " ";
            kol += 1;
        }
        cout << endl;
        cout << "Размер массива: " << kol;
    }
};
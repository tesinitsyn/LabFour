#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

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

    void inputAuto(int number) {
        for (int i = 0; i < size; i++) {
            p[i] = number;
        }
    }

    static int solution(int arrayX[], int arrayC[]) {
        int totalSum = 0;
        for (int i = 0; i < 20; i++) {
            if (arrayX[i] < arrayC[i]) {
                return -1;
            } else {
                totalSum = pow(arrayX[i], 2) - pow(arrayC[i], 2) + totalSum;
            }
        }
        return totalSum;
    }
};


int main() {

    vect forTest;
    int arrayX[20];
    int arrayC[20];
    string answer;
    cout << "Enter data automatically or manually[a/m]?";
    cin >> answer;
    if (answer == "a") {
        for (int i = 0; i < 20; i++) {
            arrayX[i] = 10;
            arrayC[i] = 1;
        }
    } else {
        cout << "Input first array: \n";
        for (int &i: arrayX) {
            cin >> i;
        }
        cout << "Input second array: \n";
        for (int &i: arrayC) {
            cin >> i;
        }
    }
    cout << "Solution is ";
    cout << forTest.solution(arrayX, arrayC);
    cout << "\n";
}
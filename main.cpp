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
    int solution(int arrayX[], int arrayC[]){
        int totalSum = 0;
        for(int i = 0; i < 20; i++){
            if(arrayX[i] < arrayC[i]){
                return -1;
            }else{
                totalSum = pow(arrayX[i], 2 ) - pow(arrayC[i], 2) + totalSum;
            }
        }
        return totalSum;
    }
};


int main() {
    int solutionType = 10;
    while (solutionType != 0) {
        cout << "Lab 4 solutions: \n";
        cout << "1. Class like method solution\n";
        cout << "2. Field access solution\n";
        cout << "If you want to exit write 0 pls :3\n";
        cout << "Enter number: ";
        cin >> solutionType;                           
        if (solutionType == 0) {
            cout << "Have a good day, honey!!!";
        }
        if (solutionType == 1) {
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
        }
        if (solutionType == 2) {
            vect arrayX(20);
            vect arrayC(20);
            cout << "Input first array\n";
            arrayX.input();
            cout << "Input second array\n";
            arrayC.input()
        }
//    vect x(7);
//    x.input();
//    x.print();
//    double maxs = x.element(0);
//    int nom = 0;
//    for (int i = 0; i < x.get_size(); i++) {
//        if (x.element(i) > maxs) {
//            maxs = x.element(i);
//            nom = i;
//        }
//    }
//    int *massiv = new int[x.get_size() - nom - 1];
//    for (int i = nom + 1; i < x.get_size(); i++) {
//        massiv[i] = x.element(i);
//    }
//    cout << endl << "Initial array: ";
//    int kol = 0;
//    for (int i = nom + 1; i < x.get_size(); i++) {
//        cout << massiv[i] << " ";
//        kol += 1;
//    }
//    cout << endl;
//    cout << "Array size: " << kol;
//    return 0;
    }
}
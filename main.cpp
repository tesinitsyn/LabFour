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

    void inputAuto(int number){
        for (int i = 0; i < size; i++) {
            p[i] = number;
        }
    }
    static int solution(int arrayX[], int arrayC[]){
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
            cout << "\n";
        }
        if (solutionType == 2) {
            int totalSum = 0;
            vect arrayX(20);
            vect arrayC(20);
            string answer;
            cout << "Enter data automatically or manually[a/m]?";
            cin >> answer;
            if (answer == "a") {
                arrayX.inputAuto(10);
                arrayC.inputAuto(1);
            } else {
               cout << "Input first array\n";
               arrayX.input();
               cout << "Input second array\n";
               arrayC.input();
            }                                                                                   
            for (int i = 0; i < arrayX.get_size(); i++) {
                if(arrayX.element(i) < arrayC.element(i)) {
                    cout << "Solution is -1";
                    break;
                }else{
                    totalSum = pow(arrayX.element(i), 2 ) - pow(arrayC.element(i), 2) + totalSum;
                }
            }
            cout << "Solution is " + to_string(totalSum) + "\n";
        }
    }
}
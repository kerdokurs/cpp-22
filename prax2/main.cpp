//
// Created by Kerdo Kurs on 15.02.2023.
//
#include <iostream>
#include <cmath>
#include <iomanip>

const int MAX_N = 1000;

double mySqrt(double n) {
    double alg = n / 2;

    for (int i = 0; i < MAX_N; ++i) {
        double r = n / alg;
        double newAlg = (alg + r) / 2;
        double diff = std::abs(newAlg - alg) / alg;
        if (diff < 0.01) {
            alg = newAlg;
            break;
            // TODO: 2x loop
        }
        alg = newAlg;
    }

    return alg;
}

void yl1() {
    std::cout << mySqrt(46) << '\n';
}

void yl2() {
//    int summa = 0;
//    int maxSumma = 0;
}

void printIstmeteTabel(bool istmed[6][4]) {
    for (int rida = 0; rida < 6; ++rida) {
        std::cout << (rida + 1) << ' ';
        for (int veerg = 0; veerg < 4; ++veerg) {
            if (istmed[rida][veerg])
                std::cout << "X ";
            else
                std::cout << static_cast<char>('A' + veerg) << ' ';
        }
        std::cout << '\n';
    }
}

void yl3() {
    bool istmed[6][4];
    printIstmeteTabel(istmed);
}

int main() {
    int x[2] = {1, 2};
    int y = 0[x];
//     x[0] -> *(x+0)
//     0[x] -> *(0+x)
    std::cout << y << '\n';
}
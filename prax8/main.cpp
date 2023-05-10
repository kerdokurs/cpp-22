//
// Created by Kerdo Kurs on 29.03.2023.
//

#include <iostream>
#include <cmath>

template<typename T>
void vaheta_ref(T &x, T &y) {
    T juhuslik = x;
    x = y;
    y = juhuslik;
}

template<typename T>
void vaheta_ptr(T *x, T *y) {
    auto temp = *x;
    *x = *y;
    *y = temp;
}

bool lahenda_1(double a, double b, double c, double &x1, double &x2) {
    if (a == 0) {
        return false;
    }

    auto D = b * b - 4 * a * c;
    if (D < 0) {
        return false;
    }
    D = std::sqrt(D);

    x1 = (-b + D) / (2 * a);
    x2 = (-b - D) / (2 * a);
    return true;
}

bool lahenda_2(double *a, double *b, double *c, double &x1, double &x2) {
    if (*a == 0) {
        return false;
    }

    auto D = *b * *b - 4 * *a * *c;
    if (D < 0) {
        return false;
    }
    D = std::sqrt(D);

    x1 = (-*b + D) / (2 * *a);
    x2 = (-*b - D) / (2 * *a);
    return true;
}

bool lahenda_3(double &a, double &b, double &c, double *x1, double *x2) {
    if (a == 0) {
        return false;
    }

    auto D = b * b - 4 * a * c;
    if (D < 0) {
        return false;
    }
    D = std::sqrt(D);

    *x1 = (-b + D) / (2 * a);
    *x2 = (-b - D) / (2 * a);
    return true;
}

bool *lahenda_4(double *a, double *b, double *c, double *x1, double *x2) {
    bool lahendub = true;

    return &lahendub;
}

int main() {
    int x = 5, y = 7;
    vaheta_ref<int>(x, y);   // x = 7 ja y = 5
    std::cout << x << ' ' << y << '\n';

    vaheta_ptr<int>(&x, &y);   // x = 5 ja y = 7
    std::cout << x << ' ' << y << '\n';

    double a = 1.0, b = -3.0, c = 1.0;
//    double a = 0.0, b = -2.0, c = 1.0;
//    double a = 1.0, b = 2.0, c = 1.0;
    double x1, x2;
    if (lahenda_1(a, b, c, x1, x2))
        std::cout << "Lahendid on: " << x1 << ", " << x2 << '\n';
    else
        std::cout << "Reaalarvulisi lahendeid ei ole!" << '\n';
}
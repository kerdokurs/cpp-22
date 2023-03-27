//
// Created by Kerdo Kurs on 08.03.2023.
//

#ifndef CPP_22_PAHUPIDIARV_H
#define CPP_22_PAHUPIDIARV_H

#include <iostream>

class PahupidiArv {
    int m_Arv{0};

public:
    explicit PahupidiArv(int arv);

    PahupidiArv() = default;

    ~PahupidiArv();

    PahupidiArv(const PahupidiArv &o);
    PahupidiArv(const PahupidiArv &&o);
    PahupidiArv &operator=(const PahupidiArv &o);
    PahupidiArv &operator=(const PahupidiArv &&o);

    int operator+(int arv);

    int operator-(int arv);

    int operator*(int arv);

    int operator/(int arv);

    void operator+=(int arv);

    friend std::ostream &operator<<(std::ostream &o, const PahupidiArv &arv);

    int arv();

    void arv(int arv);
};


#endif //CPP_22_PAHUPIDIARV_H

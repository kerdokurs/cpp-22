//
// Created by Kerdo Kurs on 08.03.2023.
//

#include "PahupidiArv.h"

#include <iostream>

PahupidiArv::PahupidiArv(int arv)
        : m_Arv(arv) {
    std::cout << "Konstruktor\n";
}

PahupidiArv::~PahupidiArv() {
    std::cout << "Destruktor\n";
}

PahupidiArv::PahupidiArv(const PahupidiArv &o) {
    std::cout << "Koopiakonstruktor\n";
    m_Arv = o.m_Arv;
}

PahupidiArv::PahupidiArv(const PahupidiArv &&o) {
    std::cout << "Teisalduskonstruktor\n";
    m_Arv = o.m_Arv;
}

PahupidiArv &PahupidiArv::operator=(const PahupidiArv &o) {
    std::cout << "Koopia operaator\n";

    if (this != &o) {
        m_Arv = o.m_Arv;
    }

    return *this;
}

PahupidiArv &PahupidiArv::operator=(const PahupidiArv &&o) {
    std::cout << "Teisaldus operaator\n";

    if (this != &o) {
        m_Arv = o.m_Arv;
    }

    return *this;
}

int PahupidiArv::operator+(int arv) {
    return m_Arv - arv;
}

int PahupidiArv::operator-(int arv) {
    return m_Arv + arv;
}

int PahupidiArv::operator*(int arv) {
    return m_Arv / arv;
}

int PahupidiArv::operator/(int arv) {
    return m_Arv * arv;
}

void PahupidiArv::operator+=(int arv) {
    m_Arv += arv;
}

int PahupidiArv::arv() {
    return m_Arv;
}

void PahupidiArv::arv(int arv) {
    m_Arv = arv;
}

std::ostream &operator<<(std::ostream &o, const PahupidiArv &arv) {
    o << arv.m_Arv;
    return o;
}

//
// Created by Kerdo Kurs on 05.04.2023.
//

#include "raamat.h"

#include <iostream>
#include <memory>

using namespace std;

int main() {
    auto teosed = loeTeosed("teosed.txt");

    auto hoiataja = make_shared<ViiviseHoiataja>(0.2);
    auto leidja = make_shared<SuurimaViiviseLeidja>();

    for (auto &teos: teosed) {
        teos->arvutaViivis(hoiataja);
    }

    cout << "Hoiatus!\n";
    for (auto &nimi: *(hoiataja->getHoiatatavadLaenutajad())) {
        cout << *nimi << '\n';
    }

    for (auto &teos: teosed) {
        teos->arvutaViivis(leidja);
        cout << *teos << '\n';
    }

    return 0;
}
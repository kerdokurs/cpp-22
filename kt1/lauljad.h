//
// Created by Kerdo Kurs on 22.03.2023.
//

#ifndef CPP_22_LAULJAD_H
#define CPP_22_LAULJAD_H

#include <concepts>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

template<typename T>
requires std::integral<T>
void lauljad(T ridadeArv, std::string failitee) {
    std::ifstream fail(failitee);
    if (!fail.is_open()) {
        std::cout << "Faili '" << failitee << "' ei saanud avada.\n";
        return;
    }

    int eesnimedePikkus{0}, koguPikkus{0};
    std::vector<std::string> eesnimed;

    std::string rida;
    while (getline(fail, rida) && ridadeArv--) {
        koguPikkus += rida.length();

        auto eesnimeLopp = rida.find(' ');
        eesnimed.push_back(rida.substr(0, eesnimeLopp));
        eesnimedePikkus += eesnimeLopp;

        std::cout << rida << '\n';
    }

    std::cout << "Eesnimed:";
    for (auto eesnimi : eesnimed) {
        std::cout << " " << eesnimi;
    }
    std::cout << '\n';

    std::cout << "Eesnimede kogupikkus: " << eesnimedePikkus << '\n';
    std::cout << "Nimede kogupikkus: " << koguPikkus << '\n';
    std::cout << "Eesnimed moodustavad nimedest "
        << std::setprecision(4) << (eesnimedePikkus / static_cast<float>(koguPikkus))*100
        << " protsenti\n";
}

#endif //CPP_22_LAULJAD_H

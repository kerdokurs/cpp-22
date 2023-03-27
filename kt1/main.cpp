//
// Created by Kerdo Kurs on 22.03.2023.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#include "asfalt.h"
#include "lauljad.h"
#include "videod.h"

int main() {


    {
        // 1. ülesanne
        std::cout << "===== 1. ülesanne =====\n";

        float laius, kogus;
        std::cout << "Tee laius: ";
        std::cin >> laius;

        std::cout << "Asfalti kogus: ";
        std::cin >> kogus;

        std::cout << "Kuluv aeg: " << arvuta_ajakulu(laius, kogus) << '\n';

        std::cout << '\n';
    }

    {
        // 2. ülesanne
        std::cout << "===== 2. ülesanne =====\n";

        lauljad<int>(1, "lauljad.txt");
        std::cout << "\n\n";
        lauljad<int>(2, "lauljad.txt");

        std::cout << '\n';
    }

    {
        // 3. ülesanne
        std::cout << "===== 3. ülesanne =====\n";

        Video koduvideo("Koduvideo", "mp4", 12);
        Film avatar("Avatar", "UHD", 192, 2022, 7);
        Pleier pleier("GOM", "UHD");

        std::cout << koduvideo << '\n';
        std::cout << avatar << '\n';
        std::cout << pleier << '\n';
        std::cout << '\n';

        pleier.mangi(koduvideo);
        pleier.mangi(avatar);

        std::cout << '\n';
    }
}
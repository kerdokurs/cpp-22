//
// Created by Kerdo Kurs on 08.03.2023.
//

#include <iostream>
#include <vector>

#include "PahupidiArv.h"

int main() {
    // 5. praktikum
    PahupidiArv arv(4);
    std::cout << arv.arv() << '\n';

    std::cout << arv + 1 << '\n';
    std::cout << arv - 1 << '\n';
    std::cout << arv * 2 << '\n';
    std::cout << arv / 2 << '\n';

    std::cout << "arv: " << arv << '\n';
    std::cout << "--------------------\n";

    PahupidiArv arv1 = arv;
    std::cout << arv1.arv() << '\n';
    arv1 = arv;
    std::cout << arv1.arv() << '\n';

    PahupidiArv arv2 = std::move(arv);
    std::cout << arv2.arv() << '\n';

    arv2 = std::move(arv);
    std::cout << arv2.arv() << '\n';
}
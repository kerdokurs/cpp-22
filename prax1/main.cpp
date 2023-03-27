#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>

void yl1() {
    std::cout << "Sisesta täisarv: ";
    int sisend;
    std::cin >> sisend;
    std::cout << "Viimane number: " << (sisend % 10) << "\n";
    int tulemus = sisend >> 1;
    std::cout << "Arv nihutatult üks koht paremale: " << tulemus << "\n";
    std::cout << "Tulemus nihutatult kaks kohta vasakule: "
              << (tulemus << 2) << "\n";
}

void yl2() {
    int weight, time;
    std::cout << "Sisesta kaal: ";
    std::cin >> weight;
    std::cout << "Sisesta aeg minutites: ";
    std::cin >> time;

    
    std::cout << "Tegevus\tAeg min\tKulutatud kcal\n";
    std::cout << "------------------------------\n";
    std::cout << "Kõndimine\t" << time << "\t" << 4 * weight * (time / 60.0) << '\n';
    std::cout << "Treppidel käimine\t" << time << "\t" << 5.5 * weight * (time / 60.0) << '\n';
    std::cout << "Ujumine\t" << time << "\t" << 10 * weight * (time / 60.0) << '\n';
    std::cout << "Korvpall\t" << time << "\t" << 8 * weight * (time / 60.0) << '\n';
}

void yl3() {
//    std::cout << "Siseta ringi raadius: ";
//    double radius;
//    std::cin >> radius;

    std::cout << std::fixed << std::setprecision(2)
              << M_PI << '\n';
    std::cout << std::fixed << std::setprecision(2)
              << std::numbers::pi << '\n';
}

int main() {
//    yl1();
//    yl2();
    yl3();

    return 0;
}


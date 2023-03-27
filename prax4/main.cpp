//
// Created by Kerdo Kurs on 01.03.2023.
//

#include <algorithm>
#include <concepts>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void sagedus(const string &asukoht) {
    ifstream sisend(asukoht);
    if (!sisend.is_open()) {
        cerr << "Faili '" << asukoht << "' ei saanud avada.\n";
        return;
    }

    string rida;
    while (getline(sisend, rida)) {
        map<char, int> m;

        stringstream ss(rida);
        char sona;

        while (ss >> sona) {
            //            m[sona]++;
            auto it = m.find(sona);
            if (it == m.end()) {
                // sone pole mapis
                m.insert({sona, 1});
            } else {
                it->second++;
            }
        }

        char maxStr;
        int maxVal{INT_MIN};

        for (auto &[key, value]: m) {
            if (value > maxVal) {
                maxVal = value;
                maxStr = key;
            }
        }

        cout << maxStr << ": " << maxVal << '\n';
    }
}

template<typename T, int N = 10>
auto liidaJaPiira(T a, T b) {
    auto summa = a + b;
    return min(summa, N);
}

#include <filesystem>

template<typename T>
void looFailJaKirjuta(filesystem::path path, T elements[], size_t arv) {}

int main() {
    sagedus("sisend.txt");
    std::cout << liidaJaPiira(4, 1) << '\n';
    std::cout << liidaJaPiira(10, 100) << '\n';
    std::cout << liidaJaPiira<int, 0>(0, 1) << '\n';
}

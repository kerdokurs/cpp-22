//
// Created by Kerdo Kurs on 19.04.2023.
//

#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <deque>
#include <concepts>

#include "peidetud.hpp"

using namespace std;

#define PROFILE_ENABLED 0
#if PROFILE_ENABLED == 1
    #define PROFILE Timer t
#else
    #define PROFILE
#endif

#include <chrono>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> Start;
    std::chrono::time_point<std::chrono::high_resolution_clock> End;

    Timer() {
        Start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        End = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(End - Start);
        std::cout << "Aega kulus " << std::fixed << duration.count() << " ms\n";
    }
};

template<typename Container, typename T>
bool leidub(Container &konteiner, T &otsitav) {
//    return std::any_of(c.begin(), c.end(), [&el](auto &x) {
//        return x == el;
//    });
    for (auto &element: konteiner) {
        if (element == otsitav) {
            return true;
        }
    }

    return false;
}

template<typename T1, typename T2, typename T3>
void yhisosa(T1 &esimene, T2 &teine, T3 &kolmas) {
    for (auto &el: esimene) {
        bool leidus = leidub(teine, el);
        if (leidus) {
            leidus = leidub(kolmas, el);
            if (!leidus) {
                kolmas.push_back(el);
            }
        }
    }
}

template<typename T1, typename T2, typename T3>
void yhend(T1 &esimene, T2 &teine, T3 &kolmas) {
    for (auto &el: esimene) {
        if (!leidub(kolmas, el)) {
            kolmas.push_back(el);
        }
    }
    for (auto &el: teine) {
        if (!leidub(kolmas, el)) {
            kolmas.push_back(el);
        }
    }
}

template<typename T1, typename T2, typename T3>
void vahe(T1 &esimene, T2 &teine, T3 &kolmas) {
    for (auto &el: esimene) {
        if (!leidub(teine, el) && !leidub(kolmas, el)) {
            kolmas.push_back(el);
        }
    }
}

template<typename T>
void taida(T &andmed, int n) {
    for (int i = 0; i < n; i++) {
        andmed.push_back(i);
    }
//    andmed.resize(n);
//    int i = 0;
//    std::transform(andmed.begin(), andmed.end(),
//                   andmed.begin(), [&i](auto x) -> int {
//        return i++;
//    });
//    std::iota(andmed.begin(), andmed.end(), 0);
}

template<typename T>
int summa1(T &andmed) {
    int summa = 0;
    for (size_t i = 0; i < andmed.size(); i++) {
        summa += andmed[i];
    }
    return summa;
}

template<typename T>
int summa2(T &andmed) {
    int summa = 0;
    for (auto x: andmed) {
        summa += x;
    }
    return summa;
}

template<typename T>
int summa3(T &andmed) {
    return std::accumulate(andmed.begin(), andmed.end(), 0);
}

int main() {
//    vector<int> v1{10, 11, 5, 3, 3};
//    vector<int> v2{3, 5, 3, 5, 1};
//    vector<int> v3{};
//    tryki(v1, cout); // kuvab elemendid ekraanile
//    tryki(v2, cout);
//    yhisosa(v1, v2, v3);
//    cout << "v1 ja v2 ühisosa:\n";
//    tryki(v3, cout);
//    v3.clear();
//    yhend(v1, v2, v3);
//    cout << "v1 ja v2 ühend:\n";
//    tryki(v3, cout);
//    v3.clear();
//    vahe(v1, v2, v3);
//    cout << "v1 ja v2 vahe:\n";
//    tryki(v3, cout);

    vector<int> vec;
    taida(vec, 10000);

    const int N = 10000;

    {
        PROFILE;
        for (size_t i = 0; i < N; i++) {
            summa1(vec);
        }
    }
    {
        PROFILE;
        for (size_t i = 0; i < N; i++) {
            summa2(vec);
        }
    }
    {
        PROFILE;
        for (size_t i = 0; i < N; i++) {
            summa3(vec);
        }


    }


    return 0;
}
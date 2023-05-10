//
// Created by Kerdo Kurs on 19.04.2023.
//

#pragma once

#include <iostream>

template<typename T>
std::ostream &tryki(T &t, std::ostream &o = std::cout) {
    for_each(begin(t), end(t), [&o](auto const &x) {
        o << x << ' ';
    });
    o << '\n';

    return o;
}
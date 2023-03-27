//
// Created by Kerdo Kurs on 22.03.2023.
//

#include "asfalt.h"

#include <cmath>

std::string ajakulu(float aeg) {
    int minutes = int(std::round(aeg / 2));
    int hours = minutes / 60;
    minutes %= 60;

    if ((hours >= 8 && minutes == 0) || hours > 8) {
        return "ajakulu ületab tööpäeva kestvuse";
    }

    return std::to_string(hours) + " h " + std::to_string(minutes) + " min";
}

float teepikkus(float laius, float kogus) {
    kogus /= 3.0f;
    return kogus / laius;
}

std::string arvuta_ajakulu(float laius, float kogus) {
    auto tp = teepikkus(laius, kogus);
    return ajakulu(tp);
}

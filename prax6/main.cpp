#include <iostream>
#include <vector>

#include "osalejad_tulemused.h"

int main() {
    std::vector<Tulemus> tulemused;
    loe_failist("tulemused.txt", tulemused);

    Osaleja osaleja1("Osaleja 1", "38002055060");
    Osaleja osaleja2("Osaleja 2", "37806135649");
    Osaleja osaleja3("Osaleja 3", "34501234215");

    osaleja1.lisaTulemused(tulemused);
    osaleja2.lisaTulemused(tulemused);
    osaleja3.lisaTulemused(tulemused);

    [[maybe_unused]] auto o1t = osaleja1.getTulemused();
    [[maybe_unused]] auto o2t = osaleja2.getTulemused();
    [[maybe_unused]] auto o3t = osaleja3.getTulemused();
}


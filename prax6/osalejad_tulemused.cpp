//
// Created by Kerdo Kurs on 15.03.2023.
//

#include "osalejad_tulemused.h"

#include <fstream>
#include <cassert>

Tulemus::Tulemus(std::string ik, std::string nimi, int koht)
        : m_Isikukood(ik), m_VoistluseNimi(nimi), m_Koht(koht) {
}

auto Tulemus::getIsikukood() {
    return m_Isikukood;
}

auto Tulemus::getVoistluseNimi() {
    return m_VoistluseNimi;
}

auto Tulemus::getKoht() {
    return m_Koht;
}

std::ostream &operator<<(std::ostream &o, Tulemus &t) {
    o << "isikukood: " << t.getIsikukood()
      << ", võistlus: " << t.getVoistluseNimi()
      << ", koht: " << t.getKoht();
    return o;
}

Osaleja::Osaleja(std::string nimi, std::string ik)
        : m_Nimi(nimi), m_Isikukood(ik) {
}

void Osaleja::lisaTulemused(std::vector<Tulemus> &tulemused) {
    for (auto &tulemus: tulemused) {
        if (tulemus.getIsikukood() == m_Isikukood) {
            m_Tulemused.push_back(tulemus);

            if (tulemus.getKoht() == 1) {
                m_Voite++;
            }
        }
    }
}

int Osaleja::voite() {
    return m_Voite;
}

int Osaleja::tulemusi() {
    return static_cast<int>(m_Tulemused.size());
}

auto Osaleja::getNimi() {
    return m_Nimi;
}

auto Osaleja::getIsikukood() {
    return m_Isikukood;
}

std::vector<Tulemus> Osaleja::getTulemused() {
    return m_Tulemused;
}

void loe_failist(std::string path, std::vector<Tulemus> &tulemused) {
    std::ifstream file(path);
    assert(file.is_open());

    std::string rida;
    while (getline(file, rida)) {
        std::string nimi, isikukood;
        int koht{-1};

        auto pos = rida.find(';');
        isikukood = rida.substr(0, pos);
        rida = rida.substr(pos + 1);

        pos = rida.find(';');
        if (pos == std::string::npos) {
            // ei ole kohta
            nimi = rida;
        } else {
            nimi = rida.substr(0, pos);
            rida = rida.substr(pos + 1);
            koht = std::stoi(rida);
        }

        tulemused.push_back(Tulemus(isikukood, nimi, koht));
    }
}


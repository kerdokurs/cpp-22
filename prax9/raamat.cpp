//
// Created by Kerdo Kurs on 05.04.2023.
//

#include "raamat.h"

#include <cmath>

Teos::Teos(string nimi, string tahis, shared_ptr<string> laenutajaNimi, int paevadeArv)
        : m_Nimi(nimi), m_Tahis(tahis), m_LaenutajaNimi(laenutajaNimi), m_PaevadeArv(paevadeArv) {}

int Teos::laenutusaeg() {
    if (m_Tahis == "roheline") {
        return 1;
    }

    if (m_Tahis == "puudub") {
        return 14;
    }

    if (m_Tahis == "kollane") {
        return 30;
    }

    if (m_Tahis == "sinine") {
        return 60;
    }

    return 0;
}

float Teos::paevaneViivis() {
    auto laenutusAeg = laenutusaeg();

    switch (laenutusAeg) {
        case 30:
        case 60:
            return 0.05f;
        case 14:
            return 0.15f;
        case 1:
            return 2.0f;
        default:
            return 0.0f;
    }
}

void Teos::arvutaViivis(shared_ptr<Kontrollija> kontrollija) {
    auto viivsePaevad = static_cast<float>(m_PaevadeArv - laenutusaeg());
    auto viivis = max(0.0f, viivsePaevad * paevaneViivis());

    kontrollija->salvestaViivis(m_LaenutajaNimi, m_Nimi, viivis);
}

ostream &Teos::print(ostream &o) {
    o << "Pealkiri: " << m_Nimi << '\n'
      << "Tähis: " << m_Tahis << '\n'
      << "Laenutaja: " << *m_LaenutajaNimi << '\n'
      << "Päevi: " << m_PaevadeArv
      << "Hoidlast: " << (kasHoidlast() ? "jah" : "ei");

    return o;
}

ostream &operator<<(ostream &o, Teos &t) {
    t.print(o);
    return o;
}

bool operator<(Teos &lhs, Teos &rhs) {
    return lhs.m_Nimi < rhs.m_Nimi;
}

Raamat::Raamat(string nimi, string tahis, shared_ptr<string> laenutajaNimi, int paevadeArv) : Teos(nimi, tahis,
                                                                                                   laenutajaNimi,
                                                                                                   paevadeArv) {}

bool Raamat::kasHoidlast() {
    return m_Tahis == "kollane" || m_Tahis == "sinine";
}

ostream &Raamat::print(ostream &o) {
    Teos::print(o); // ülemklassi print liikmefunktsioon
    o << "\n^ Raamat";

    return o;
}

ViiviseHoiataja::ViiviseHoiataja(float viivis)
        : m_Viivis(viivis), m_Nimed(new vector<shared_ptr<string>>) {}

ViiviseHoiataja::~ViiviseHoiataja() {
    delete m_Nimed;
}

void ViiviseHoiataja::salvestaViivis(shared_ptr<string> laenutajaNimi, string teoseNimi, float viivis) {
    if (viivis < m_Viivis) {
        return;
    }

    bool exists = false;
    for (auto &nimi: *m_Nimed) {
        // ! tuleb võrrelda sõnesid, mitte viitasid
        if (*nimi == *laenutajaNimi) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        m_Nimed->push_back(laenutajaNimi);
    }
}

void SuurimaViiviseLeidja::salvestaViivis(shared_ptr<string> laenutajaNimi, string teoseNimi, float viivis) {
    if (viivis > m_Viivis) {
        m_LaenutajaNimi = laenutajaNimi;
        m_TeoseNimi = teoseNimi;
        m_Viivis = viivis;
    }
}

void SuurimaViiviseLeidja::saadaHoiatus() {
    cout << "Suurima viivisega on " << *m_LaenutajaNimi
         << " teosega " << m_TeoseNimi << '\n';
}

vector<shared_ptr<Teos>> loeTeosed(const string &asukoht) {
    vector<shared_ptr<Teos>> vec;
    vec.push_back(
            std::make_shared<Raamat>("Matemaatika VI klassile", "kollane", std::make_shared<std::string>("Joosep Kask"),
                                     125));
//    vec.push_back(
//            make_shared<Ajakiri>("Kodu ja aed", "kollane", make_shared<string>("Teele Tamm"), 59, 2013));
    vec.push_back(make_shared<Raamat>("Kevade", "sinine", make_shared<string>("Teele Tamm"), 39));

    return vec;
}
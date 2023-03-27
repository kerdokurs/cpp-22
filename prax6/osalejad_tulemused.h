//
// Created by Kerdo Kurs on 15.03.2023.
//

#ifndef CPP_22_OSALEJAD_TULEMUSED_H
#define CPP_22_OSALEJAD_TULEMUSED_H

#include <string>
#include <vector>
#include <iostream>

class Osalenud {
public:
    virtual ~Osalenud() = default;

    virtual int voite() = 0;
    virtual int tulemusi() = 0;
};

class Tulemus {
    std::string m_Isikukood;
    std::string m_VoistluseNimi;
    int m_Koht;

public:
    Tulemus(std::string, std::string, int);

    auto getIsikukood();
    auto getVoistluseNimi();
    auto getKoht();

    friend std::ostream &operator<<(std::ostream &, Tulemus &);
};

class Osaleja : Osalenud {
    std::string m_Nimi{};
    std::string m_Isikukood{};
    std::vector<Tulemus> m_Tulemused{};
    int m_Voite{0};

public:
    ~Osaleja() override = default;

    Osaleja(std::string, std::string);

    int voite() override;
    int tulemusi() override;

    void lisaTulemused(std::vector<Tulemus> &tulemused);

    auto getNimi();
    auto getIsikukood();
    std::vector<Tulemus> getTulemused();
};

class Lapsosaleja : Osaleja {
};

void loe_failist(std::string, std::vector<Tulemus> &);

#endif //CPP_22_OSALEJAD_TULEMUSED_H

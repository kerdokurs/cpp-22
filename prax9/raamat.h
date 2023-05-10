//
// Created by Kerdo Kurs on 05.04.2023.
//

#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

// Deklaratsiooni edastamine (forward declaration)
class Kontrollija;

class Teos {
protected:
    string m_Nimi;
    string m_Tahis;
    shared_ptr<string> m_LaenutajaNimi;
    int m_PaevadeArv;

public:
    Teos(string nimi, string tahis, shared_ptr<string> laenutajaNimi, int paevadeArv);
    virtual ~Teos() = default; // Vajalik polümorfismi jaoks

    virtual bool kasHoidlast() = 0;

    int laenutusaeg();
    float paevaneViivis();

    void arvutaViivis(shared_ptr<Kontrollija> kontrollija);

    virtual ostream &print(ostream &o);
    friend ostream &operator<<(ostream &o, Teos &t);

    friend bool operator<(Teos &lhs, Teos &rhs);
};

class Raamat : public Teos {
public:
    Raamat(string nimi, string tahis, shared_ptr<string> laenutajaNimi, int paevadeArv);

    bool kasHoidlast() override;
    ostream &print(ostream &o) override;
};

class Ajakiri : public Teos {
};

class Kontrollija {
public:
    virtual ~Kontrollija() = default; // Vajalik polümorfismi jaoks
    virtual void salvestaViivis(shared_ptr<string> laenutajaNimi, string teoseNimi, float viivis) = 0;
};

class ViiviseHoiataja : public Kontrollija {
    float m_Viivis;
    vector<shared_ptr<string>>* m_Nimed;

public:
    explicit ViiviseHoiataja(float viivis);
    ~ViiviseHoiataja();

    void salvestaViivis(shared_ptr<string> laenutajaNimi, string teoseNimi, float viivis) override;

    auto getHoiatatavadLaenutajad() {
        return m_Nimed;
    }
};

class SuurimaViiviseLeidja : public Kontrollija {
    shared_ptr<string> m_LaenutajaNimi;
    string m_TeoseNimi;
    float m_Viivis;

public:
    void salvestaViivis(shared_ptr<string> laenutajaNimi, string teoseNimi, float viivis) override;

    void saadaHoiatus();
};

vector<shared_ptr<Teos>> loeTeosed(const string &asukoht);

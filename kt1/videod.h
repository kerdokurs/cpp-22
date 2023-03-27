//
// Created by Kerdo Kurs on 22.03.2023.
//

#ifndef CPP_22_VIDEOD_H
#define CPP_22_VIDEOD_H

#include <string>
#include <iostream>

class Video {
    std::string m_Nimi;
    std::string m_Esitus;
    int m_Pikkus;

public:
    Video() = default;
    Video(std::string, std::string, int);

    std::string getNimi();
    std::string getEsitus();
    int getPikkus();

    friend std::ostream &operator<<(std::ostream &, Video &);
};

class Film : public Video {
    int m_Aasta;
    int m_Reiting;

public:
    Film(std::string, std::string, int, int, int);

    friend std::ostream &operator<<(std::ostream &, Film &);
};

class Pleier {
    std::string m_Liik;
    std::string m_Esitus;

public:
    Pleier(std::string, std::string);

    void mangi(Video&);

    friend std::ostream &operator<<(std::ostream &, Pleier &);
};

#endif //CPP_22_VIDEOD_H

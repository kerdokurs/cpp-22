//
// Created by Kerdo Kurs on 22.03.2023.
//

#include "videod.h"

Video::Video(std::string nimi, std::string esitus, int pikkus)
    : m_Nimi(nimi)
    , m_Esitus(esitus)
    , m_Pikkus(pikkus) {
}

std::string Video::getNimi() {
    return m_Nimi;
}

std::string Video::getEsitus() {
    return m_Esitus;
}

int Video::getPikkus() {
    return m_Pikkus;
}

std::ostream &operator<<(std::ostream &o, Video &video) {

    o <<
        video.m_Nimi << ' '
        << video.m_Esitus << ' '
        << video.m_Pikkus << " min";

    return o;
}

Film::Film(std::string nimi, std::string esitus, int pikkus, int aasta, int reiting)
    : Video(nimi, esitus, pikkus)
    , m_Aasta(aasta)
    , m_Reiting(reiting) {
}

std::ostream &operator<<(std::ostream &o, Film &film) {

    o <<
      dynamic_cast<Video&>(film) << ' '
      << film.m_Aasta << ' '
      << film.m_Reiting;

    return o;
}

Pleier::Pleier(std::string liik, std::string esitus)
    : m_Liik(liik)
    , m_Esitus(esitus) {
}

void Pleier::mangi(Video &video) {
    auto mangib = video.getEsitus() == m_Esitus;

    std::cout << "Pleier " << m_Liik << ' ';
    if (mangib) {
        std::cout << "mängib";
    } else {
        std::cout << "ei mängi";
    }
    std::cout << " videot " << video << '\n';
}

std::ostream &operator<<(std::ostream &o, Pleier &pleier) {
    o << "Pleier " << pleier.m_Liik
        << " mängib esitust " << pleier.m_Esitus;

    return o;
}
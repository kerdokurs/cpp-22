#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string lyhendaja_rec(string nimi) {
    auto esimeneTyhikPos = nimi.find(' ');
    // kui leidub tühik ei ole perenimi
    if (esimeneTyhikPos == string::npos) {
        // ei leidu tühikut
        return nimi;
    }

    // Mari-Anne Lill
    string eesnimi = nimi.substr(0, esimeneTyhikPos); // Mari-Anne
    nimi = nimi.substr(esimeneTyhikPos + 1, nimi.length()); // Lill

    string e{eesnimi.at(0)};

    return (e + ". ") + lyhendaja_rec(nimi);
}

string lyhendaja(string nimi) {
    string tulemus;

    stringstream ss(nimi);
    string osa;
    while (ss >> osa) {
        bool isPerenimi = ss.eof();
        if (isPerenimi) {
            tulemus = osa + " " + tulemus;
        } else {
            std::replace(osa.begin(), osa.end(), '-', ' ');
            stringstream ss1(osa);

            string eesnimeosa;
            while (ss1 >> eesnimeosa) {
                tulemus += eesnimeosa.at(0);
                if (!ss1.eof()) {
                    tulemus += '-';
                } else {
                    tulemus += ". ";
                }
            }
        }
    }


    return tulemus;
}

void tagurpidi(size_t arv, string massiiv[]) {
    for (int i = 0; i < arv; ++i) {
        auto s = massiiv[i];
        std::reverse(begin(s), end(s));
    }
    std::reverse(massiiv, massiiv + arv);
}

int main(int argc, char *argv[]) {
    const int arv = 3;
    string massiiv[] = {"ok", "ok1", "ok2"};
    tagurpidi(arv, massiiv);
    for (auto &s: massiiv) {
        std::cout << s << '\n';
    }
}
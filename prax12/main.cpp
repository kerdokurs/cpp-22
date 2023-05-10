//
// Created by Kerdo Kurs on 26.04.2023.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cassert>
#include <sstream>

// https://fmt.dev
#include <fmt/format.h>

using namespace std;


struct Tudeng {
    string Nimi;
    string Id;
    map<string, int> Punktid;

    Tudeng(string nimi, string id) : Nimi(nimi), Id(id) {}

    friend ostream &operator<<(ostream &o, Tudeng const &t) {
        o << fmt::format("Tudeng\n\tNimi: {}\n\tID: {}\n", t.Nimi, t.Id);
        for (auto const &[aine, punktid]: t.Punktid) {
            o << fmt::format("\t{}: {} punkti\n", aine, punktid);
        }
        o << '\n';
        return o;
    }
};

void loeRida(string line, vector<Tudeng> &tudengid) {
    stringstream ss(line);

    stringstream nimi;

    string temp;
    while (true) {
        ss >> temp;

        auto onId = any_of(temp.begin(), temp.end(), [](auto &ch) -> bool {
            return isdigit(ch);
        });
        if (onId) {
            break;
        }

        nimi << " " << temp;
    }

    tudengid.emplace_back(nimi.str().substr(1), temp);

    auto &punktid = tudengid.back().Punktid;
    string aine;
    while (ss >> line) {
        if (aine.empty()) {
            aine = line;
        } else {
            auto punkte = stoi(line);
            punktid.insert({aine, punkte});
            aine.clear();
        }
    }
}

void loeTudengid(string const &nimi, vector<Tudeng> &tudengid) {
    fstream file(nimi);
    assert(file);

    string line;
    while (getline(file, line)) {
        loeRida(line, tudengid);
    }
}

void printAbi() {
    fmt::println("Vali tegevus:");
    fmt::println("1. Lisa üliõpilane");
    fmt::println("2. Kustuta üliõpilane");
    fmt::println("5. Väljasta üliõpilased");
}

void lisa(vector<Tudeng> &tudengid) {
    string rida;
    while (true) {
        getline(cin, rida);
        if (!rida.empty()) {
            break;
        }
    }
    loeRida(rida, tudengid);
}

void kustuta(vector<Tudeng> &tudengid) {
    string id;
    cin >> id;
    for (auto it = tudengid.begin(); it != tudengid.end(); ++it) {
        if (it->Id == id) {
            tudengid.erase(it);
            break;
        }
    }
//    erase_if(tudengid, [=](auto &t) -> bool {
//        return t.Id == id;
//    });
}

int main() {
    filesystem::current_path("../");
    vector<Tudeng> tudengid;
    loeTudengid("tudengid.txt", tudengid);

    int c;
    printAbi();
    while (cin >> c) {
        switch (c) {
            case 1:
                lisa(tudengid);
                break;
            case 2:
                kustuta(tudengid);
                break;
            case 5: {
                for (auto const &tudeng: tudengid) {
                    cout << tudeng << '\n';
                }
                break;
            }
            default:
                cerr << "Valikut ei toetata!\n";
        }
        printAbi();
    }

    return 0;
}

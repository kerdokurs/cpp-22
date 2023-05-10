nclude <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <utility>
#include <numeric>
#include <mutex>

using namespace std;

void viska(int x) {
    if (x == 1) {
        throw x;
    } else if (x == 2) {
        throw string("paar");
    }
}

class ArvuPole : public exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Arvu pole";
    }
};

class PoleArv : public exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Pole arvuks teisendatav";
    }
};

class ArvuLugeja {
public:
    static vector<int> arvud(string const &sisend) {
        vector<int> vec;

        stringstream ss(sisend);
        string arv;
        while (getline(ss, arv, ',')) {
            try {
                if (arv.empty()) {
                    throw ArvuPole();
                }

                try {
                    vec.push_back(stoi(arv));
                } catch (invalid_argument &) {
                    throw PoleArv();
                }
            } catch (ArvuPole &e) {
                cout << e.what() << '\n';
            } catch (PoleArv &e) {
                cout << e.what() << '\n';
            }
        }

        return vec;
    }
};

int main() {
    vector<int> arvud{1, 2, 3, 4};
    for (const auto arv: arvud) {
        try {
            viska(arv);
            cout << "korras\n";
        } catch (int e) {
            cout << "int " << e << '\n';
        } catch (string &e) {
            cout << "string " << e << '\n';
        } catch (...) {
            cout << "haldamata erind" << '\n';
        }
    }

    arvud = ArvuLugeja::arvud("1,ab,,4");
    cout << "Arvud:";
    for (auto const arv: arvud) {
        cout << ' ' << arv;
    }
    cout << '\n';
}

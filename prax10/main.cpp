//
// Created by Kerdo Kurs on 12.04.2023.
//

#include <iostream>
#include <initializer_list>
#include <array>
#include <sstream>

template<typename T>
class Magasin {
public:
    Magasin() = default;                  // vaikekonstruktor
    ~Magasin();                           // destruktor

    Magasin(Magasin &m);            // koopiakonstruktor
    Magasin &operator=(const Magasin &m); // koopia omistamise (''copy assignment'') operaator

    void push(T &element);        // lisa element magasini
    void push(T element);

    T pop();                            // võta element magasinist välja
    bool isEmpty() const { return m_pea == nullptr; };               // kas magasin on tühi?
    void tryki();                       // kuvab magasini elemendid ekraanile
private:

    // Siseklass
    class Tipp {
    public:
        explicit Tipp(const T liige) : m_liige{liige} {} // Tipp konstruktor
        T m_liige;            // Tipus hoitav objekt
        Tipp *m_jargmine{};   // viit järgmisele tipule
    };

    Tipp *m_pea{};     // viit magasini otsale

    void kustutaTipp(Tipp *t);
};

template<typename T>
Magasin<T>::~Magasin() {
    kustutaTipp(m_pea);
}

template<typename T>
T Magasin<T>::pop() {
    auto liige = m_pea->m_liige;
    auto praegunePea = m_pea;
    m_pea = m_pea->m_jargmine;
    delete praegunePea;
    return liige;
}

template<typename T>
Magasin<T>::Magasin(Magasin &m) {
    if (m.m_pea != nullptr) {
        m_pea = new Tipp(m.m_pea->m_liige);

        auto ajutine = m.m_pea;
        auto ajutinePea = m_pea;
        while (ajutine->m_jargmine != nullptr) {
            ajutinePea->m_jargmine = new Tipp(ajutine->m_jargmine->m_liige);

            ajutine = ajutine->m_jargmine;
            ajutinePea = ajutinePea->m_jargmine;
        }
    }
}

template<typename T>
Magasin<T> &Magasin<T>::operator=(const Magasin<T> &m) {
    if (this != &m) {
        kustutaTipp(m_pea);

        if (m.m_pea != nullptr) {
            m_pea = new Tipp(m.m_pea->m_liige);

            auto ajutine = m.m_pea;
            auto ajutinePea = m_pea;
            while (ajutine->m_jargmine != nullptr) {
                ajutinePea->m_jargmine = new Tipp(ajutine->m_jargmine->m_liige);

                ajutine = ajutine->m_jargmine;
                ajutinePea = ajutinePea->m_jargmine;
            }
        }
    }

    return *this;
}

template<typename T>
void Magasin<T>::push(T element) {
    auto tipp = new Tipp(element);

    if (m_pea == nullptr) {
        m_pea = tipp;
    } else {
        tipp->m_jargmine = m_pea;
        m_pea = tipp;
    }
}


template<typename T>
void Magasin<T>::push(T &element) {
    auto tipp = new Tipp(element);

    if (m_pea == nullptr) {
        m_pea = tipp;
    } else {
        tipp->m_jargmine = m_pea;
        m_pea = tipp;
    }
}

template<typename T>
void Magasin<T>::kustutaTipp(Magasin::Tipp *t) {
    if (t == nullptr) {
        return;
    }

    kustutaTipp(t->m_jargmine);

    delete t;
}

template<typename T>
void Magasin<T>::tryki() {
    auto ajutine = m_pea;
    while (ajutine) {
        std::cout << ajutine->m_liige << " - ";
        ajutine = ajutine->m_jargmine;
    }
    std::cout << '\n';
}

template<typename Type, size_t Size>
class Massiiv {
private:
    Type m_elemendid[Size];

public:
    Massiiv(std::initializer_list<Type> elemendid);

    Type &operator[](size_t i);

    size_t getSize() { return Size; }

    void fill(Type element) {
        for (size_t i = 0; i < Size; i++) {
            m_elemendid[i] = element;
        }
    }

    std::string toString() {
        std::stringstream ss;
        ss << '[';
        ss << m_elemendid[0]; // NB! Katki kui Size == 0
        for (size_t i = 1; i < Size; i++) {
            ss << ", " << m_elemendid[i];
        }
        ss << ']';
        return ss.str();
    }

    void tryki() {
        std::cout << toString() << '\n';
    }

    friend std::ostream &operator<<(std::ostream &o, Massiiv &m) {
        o << m.toString();
        return o;
    }
};

template<typename Type, size_t Size>
Type &Massiiv<Type, Size>::operator[](size_t i) {
    return m_elemendid[i];
}

template<typename Type, size_t Size>
Massiiv<Type, Size>::Massiiv(std::initializer_list<Type> elemendid) {
//    static_assert(elemendid.size() <= Size);

//    m_elemendid = elemendid;
    for (size_t i = 0; i < elemendid.size(); i++) {
        m_elemendid[i] = data(elemendid)[i];
    }
}

int main() {
//    int x = 1;
//    Magasin<int> a;
//    a.push(x);
//    x = 2;
//    a.push(x);
//    a.tryki();
//
//    Magasin<int> b = a;
//    std::cout << "copyconst\n";
//    std::cout << "a.pop = " << a.pop() << '\n';
//    a.tryki();
//    b.tryki();
//    std::cout << "b.pop = " << b.pop() << '\n';
//    b.tryki();
//
//    Magasin<int> c;
//    std::cout << "copyassign\n";
//    c = a;
//    a.tryki();
//    c.tryki();

    Massiiv<int, 2> a = {1, 2};
    a.tryki();
    std::cout << a << '\n';

    return 0;
}
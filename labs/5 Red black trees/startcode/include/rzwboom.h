#ifndef __RZWboom_H
#define __RZWboom_H
#include <iostream>

#include <memory>
#include <functional>
#include <fstream>
#include <sstream>
#include <cassert>

using std::cerr;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::pair;
using std::string;
using std::unique_ptr;

enum RZWkleur
{
    rood,
    zwart
};

template <class Sleutel>
class RZWknoop;

/**
 * Binaire RZWboom waarin geen duplicaatsleutels zijn toegestaan.
 */
template <class Sleutel>
class RZWboom : public unique_ptr<RZWknoop<Sleutel>>
{
public:
    using unique_ptr<RZWknoop<Sleutel>>::unique_ptr;

    RZWboom(unique_ptr<RZWknoop<Sleutel>> &&a);
    RZWboom() : unique_ptr<RZWknoop<Sleutel>>(){};

    //Gegeven
    void inorder(std::function<void(const RZWknoop<Sleutel> &)> bezoek) const;
    void schrijf(ostream &os) const;
    void tekenAls234Boom(const char *bestandsnaam) const;
    string tekenrec234(ostream &uit, int &nullteller, int &knoop34teller) const;
    void tekenAlsBinaireBoom(const char *bestandsnaam) const;
    string tekenrecBinair(ostream &uit, int &nullteller) const;
    RZWboom<Sleutel> *geefBoomVanKnoop(RZWknoop<Sleutel> &knoop);

    //te implementeren
    bool zoekSleutel(const Sleutel &sleutel);
    void roteer(bool naarlinks);
    int geefDiepte() const;
    RZWkleur geefKleur() const;
    void zetKleur(RZWkleur kl);
    void voegtoe(const Sleutel &sleutel); //noot: functie mag alleen opgeroepen worden bij hoofdboom (bij wortel), niet bij deelboom!

protected:
    struct ZoekResultaat
    {
        RZWboom<Sleutel> *plaats;
        RZWknoop<Sleutel> *ouder;
    };
    /**
     * Deze functie zoekt sleutel en geeft de plaats in de boom terug waar de sleutel zich
     * bevindt, of indien afwezig: waar de sleutel zich zou moeten bevinden. 
     * 
     * Om deze functie ook in `voegtoe` te kunnen gebruiken geven we ook de ouder terug van 
     * de gevonden plaats. Deze referentie kan dan gebruikt worden om `ouder` in te vullen
     * in de nieuwe - aan te maken - knoop.
     * 
     * Tip: maak gebruik van structured binding om het resultaat van deze functie in twee
     *      variabelen op te slaan. Zo kan je voorkomen dat je de struct `ZoekResultaat`  
     *      dient te manipuleren.
     * 
     *      auto [plaats,ouder] = zoek(sleutel);
     * 
     * Noot: alhoewel de functie niets verandert aan de boom is ze geen const functie, 
     *       omdat ze een niet-const pointer naar het inwendige van de boom teruggeeft.
     */
    ZoekResultaat zoek(const Sleutel &sleutel);
};

template <class Sleutel>
RZWboom<Sleutel>::RZWboom(unique_ptr<RZWknoop<Sleutel>> &&a) : unique_ptr<RZWknoop<Sleutel>>(move(a)) {}

template <class Sleutel>
void RZWboom<Sleutel>::inorder(std::function<void(const RZWknoop<Sleutel> &)> bezoek) const
{
    if (*this)
    {
        (*this)->links.inorder(bezoek);
        bezoek(**this);
        (*this)->rechts.inorder(bezoek);
    };
}

template <class Sleutel>
void RZWboom<Sleutel>::schrijf(ostream &os) const
{
    inorder([&os](const RZWknoop<Sleutel> &knoop) {
        os << "(" << knoop.sleutel << " ";
        if (knoop.kleur == rood)
            os << "rood";
        else
        {
            os << "zwart";
        }
        os << ")";
        os << "\n  Linkerkind: ";
        if (knoop.links)
            os << knoop.links->sleutel;
        else
            os << "-----";
        os << "\n  Rechterkind: ";
        if (knoop.rechts)
            os << knoop.rechts->sleutel;
        else
            os << "-----";
        os << "\n";
    });
}

template <class Sleutel>
void RZWboom<Sleutel>::tekenAls234Boom(const char *bestandsnaam) const
{
    ofstream uit(bestandsnaam);
    assert(uit);
    int nullteller = 0;    //nullknopen moeten een eigen nummer krijgen.
    int knoop34teller = 0; //3-knopen en 4-knopen worden ook genummerd
    uit << "digraph {\n";
    this->tekenrec234(uit, nullteller, knoop34teller);
    uit << "}";
}

template <class Sleutel>
string RZWboom<Sleutel>::tekenrec234(ostream &uit, int &nullteller, int &knoop34teller) const
{
    ostringstream wortelstring;
    if (!*this)
    {
        wortelstring << "null" << ++nullteller;
        uit << wortelstring.str() << " [shape=point];\n";
    }
    else
    {
        wortelstring << '"' << (*this)->sleutel << '"';
        uit << wortelstring.str() << "[label=\"" << (*this)->sleutel << "\"]";
        if (this->geefKleur() == rood)
            uit << "[color=red]";
        uit << ";\n";
        string linkskind = (*this)->links.tekenrec234(uit, nullteller, knoop34teller);
        ;
        string rechtskind = (*this)->rechts.tekenrec234(uit, nullteller, knoop34teller);
        ;
        if ((*this)->links.geefKleur() == rood ||
            (*this)->rechts.geefKleur() == rood)
        {
            uit << "subgraph cluster_" << ++knoop34teller << " {\n   { rank=\"same\"; ";
            if ((*this)->links.geefKleur() == rood)
                uit << linkskind << " , ";
            if ((*this)->rechts.geefKleur() == rood)
                uit << rechtskind << " , ";
            uit << wortelstring.str() << "}\n";
            if ((*this)->links.geefKleur() == rood)
                uit << "   " << linkskind << " ->" << wortelstring.str() << "[dir=back];\n";
            if ((*this)->rechts.geefKleur() == rood)
                uit << "   " << wortelstring.str() << " -> " << rechtskind << ";\n";
            uit << "color=white\n}\n";
        };
        if ((*this)->links.geefKleur() == zwart)
            uit << wortelstring.str() << " -> " << linkskind << ";\n";
        if ((*this)->rechts.geefKleur() == zwart)
            uit << wortelstring.str() << " -> " << rechtskind << ";\n";
    };
    return wortelstring.str();
}

template <class Sleutel>
void RZWboom<Sleutel>::tekenAlsBinaireBoom(const char *bestandsnaam) const
{
    ofstream uit(bestandsnaam);
    assert(uit);
    int nullteller = 0; //nullknopen moeten een eigen nummer krijgen.
    uit << "digraph {\n";
    this->tekenrecBinair(uit, nullteller);
    uit << "}";
}

template <class Sleutel>
string RZWboom<Sleutel>::tekenrecBinair(ostream &uit, int &nullteller) const
{
    ostringstream wortelstring;
    if (!*this)
    {
        wortelstring << "null" << ++nullteller;
        uit << wortelstring.str() << " [shape=point];\n";
    }
    else
    {
        wortelstring << '"' << (*this)->sleutel << '"';
        uit << wortelstring.str() << "[label=\"" << (*this)->sleutel << "\"]";
        if (this->geefKleur() == rood)
            uit << "[color=red]";
        uit << ";\n";
        string linkskind = (*this)->links.tekenrecBinair(uit, nullteller);
        string rechtskind = (*this)->rechts.tekenrecBinair(uit, nullteller);
        uit << wortelstring.str() << " -> " << linkskind << ";\n";
        uit << wortelstring.str() << " -> " << rechtskind << ";\n";
    };
    return wortelstring.str();
}

template <class Sleutel>
RZWboom<Sleutel> *RZWboom<Sleutel>::geefBoomVanKnoop(RZWknoop<Sleutel> &knoop)
{
    assert((*this)->ouder == nullptr); //deze functie mag enkel in de wortel van de boom worden opgeroepen

    if (knoop.ouder == nullptr)
        return this; //wortel
    else if (knoop.ouder->links.get() == &knoop)
        return &(knoop.ouder->links);
    else
        return &(knoop.ouder->rechts);
};

// Te implementeren:
template <class Sleutel>
int RZWboom<Sleutel>::geefDiepte() const
{
    std::cout << "geefDiepte nog niet geimplementeerd." << std::endl;
    return 0;
}

template <class Sleutel>
typename RZWboom<Sleutel>::ZoekResultaat RZWboom<Sleutel>::zoek(const Sleutel &sleutel)
{
    std::cout << "Zoek nog niet geimplementeerd." << std::endl;
};

//gebruik makend van zoek()
template <class Sleutel>
bool RZWboom<Sleutel>::zoekSleutel(const Sleutel &sleutel)
{
    std::cout << "ZoekSleutel nog niet geimplementeerd." << std::endl;
    return 0;
}

//preconditie: wortel en nodige kind bestaan
template <class Sleutel>
void RZWboom<Sleutel>::roteer(bool naarLinks)
{
    std::cout << "Roteer nog niet geimplementeerd." << std::endl;
};

template <class Sleutel>
void RZWboom<Sleutel>::zetKleur(RZWkleur kleur)
{
    std::cout << "zetKleur nog niet geimplementeerd." << std::endl;
};

template <class Sleutel>
RZWkleur RZWboom<Sleutel>::geefKleur() const
{
    std::cout << "geefKleur nog niet geimplementeerd." << std::endl;
    return RZWkleur::zwart;
}

template <class Sleutel>
void RZWboom<Sleutel>::voegtoe(const Sleutel &sleutel)
{
    std::cout << "Voegtoe nog niet geimplementeerd." << std::endl;
}

#endif

#pragma once

#include <string> 
#include <vector>
#include <optional>  // C++17

#include <iostream>
#include <algorithm>
#include <cassert>
#include <tuple>

class MapTest; // Klasa porebna za testiranje privatnog dijela klase .

// Sortirani vektor kao std::map. Klasa koju trebate implementirati
class Map{
    friend class MapTest;
    public:
    //  Eksportirani tipovi.
        using value_type = std::pair<std::string, int>;
        using Key = std::string;
        using Val = int;
    // Konstruktor. Kreira prazan spremnik.
        Map(std::size_t n=0);
    // Nalaženje elementa u kolekcji. Mora biti O(log n). 
    // Vraća vrijednost ako je ključ nađen ili prazan optional ako nije.
        std::optional<Val> find(const Key & key) const;
    // Ubacivanje elementa u kolekciju. Vraća true ako je element ubačen.
    // Ako element već postoji u kolekciji ne ubacuje ga i vraća false.
        bool insert(value_type elem);
    // Brisanje elementa iz kolekcije. Vraća true ako je elemnt izbrisan, 
    // false ako ga nema u kolekciji. 
        bool erase(const Key & key);
    // Broj elemenata u kolekciji.
        std::size_t size() const;
    // Ispis kolekcije. Samo za razvoj programa. Ne testira se.
        void print(const char * message = nullptr) const;
    private:
    // Sortirani vektor kao zamjena za std::map. 
        std::vector<value_type> mData;
};

 

// LUCache = least used cache. Klasa koju trebate implementirati
template <std::size_t N>
class LUCache{
    public: 
        using Key = std::string;
        using Val = int
        using value_type = std::pair<Key, Val>;
        // Možete eksportirati i druge tipove, ali zadržite ove!

    // Konstruktor.
        LUCache();
    // Nalaženje elementa u kolekcji. Mora biti O(log n). 
    // Vraća vrijednost ako je ključ nađen ili prazan optional ako nije.
        std::optional<Val> find(const Key & key); 
    // Ubacivanje elementa u kolekciju.Vraća true ako je element ubačen.
    // Ako element već postoji u kolekciji ne ubacuje ga i vraća false.
        bool insert(value_type elem);
    // Brisanje elementa iz kolekcije.  Vraća true ako je elemnt izbrisan, 
    // false ako ga nema u kolekciji.   
        bool erase(const Key & key);
    // Broj elemenata u kolekciji. Uvijek <= N.
        std::size_t size() const;
    // Ispis kolekcije. Samo za razvoj programa. Ne testira se.
        void print(const char * message = nullptr) const;
    // Ključ i-tog elementa u kolekciji. Metoda služi samo za testiranje.
    // Ako elemet nije prisutan ponašanje je nedefinirano.
    Key getKey(std::size_t i) const;
    private:
    // Vaša implementacija. 
};

// Implementacija predloška klase dolazi u datoteku zaglavlja. 
// Napomena. typename se stavlja tamo gdje u parametriziranoj klasi LUCache<N>
//           dohvaća eksportirani tip (Key, Val). To je nužno jer ista sintaksa služi 
//           za dohvat statičke varijable.

template <std::size_t N>
std::optional<typename LUCache<N>::Val> LUCache<N>::find(const Key & key) 
{
    // Vaš kod.             
}

template <std::size_t N>
bool LUCache<N>::insert(value_type  elem){
    // Vaš kod
}

template <std::size_t N>
bool LUCache<N>::erase(const Key & key){
   // Vaš kod
}

template <std::size_t N>
void LUCache<N>::print(const char * message) const {
    // Vaš kod
}


template <std::size_t N>
typename LUCache<N>::Key LUCache<N>::getKey(std::size_t i) const{
    // Vaš kod
}

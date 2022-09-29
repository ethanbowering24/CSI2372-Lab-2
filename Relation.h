#pragma once
#include <vector>
#include "Set.h"

struct Pair
    {
        int first;
        int second;

        bool operator==(Pair const &other){
            return ((first==other.first)&&(second==other.second));
        }
    };

class Relation
{
    private:
        Set set;
        std::vector<Pair> relations;
        
    public:
        Relation();
        Relation(Relation &);
        ~Relation();
        bool add_to_set(int);
        int cardinality();
        bool add_element(Pair);
        void remove_element(Pair);
        bool is_member(Pair);
        bool equal(Relation);
        bool reflexive();
        bool irreflexive();
        bool symmetric();
        bool asymmetric();
        bool transitive();
        bool is_function();
        Relation inverse();
        Relation combination();      
};
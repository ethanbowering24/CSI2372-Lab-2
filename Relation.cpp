#include <algorithm>
#include "Relation.h"
#include "Set.h"

Relation::Relation(){
    relations = {};
};

Relation::Relation(Relation &copy){
    for (int i = 0; i < copy.set.cardinality(); i++)
    {
        set.add_element(copy.set.get_item(i));
    }

    relations = copy.relations;
}

Relation::~Relation(){};

bool Relation::add_to_set(int element){
    return (set.add_element(element));
}

int Relation::cardinality(){
    return (relations.size());
}

bool Relation::add_element(Pair element){
    relations.push_back(element);
    return true;
}

void Relation::remove_element(Pair element){
    if (is_member(element))
    {
        relations.erase(std::remove(relations.begin(), relations.end(), element));
    }
}

bool Relation::is_member(Pair element){
    if (std::find(relations.begin(), relations.end(), element) == relations.end())
    {
        return false;
    }   
    return true;
}

bool Relation::equal(Relation otherRelation){
    for (std::vector<Pair>::iterator itr = relations.begin(); itr != relations.end(); itr++)
    {
        if (!(otherRelation.is_member(*itr)))
        {
            return false;
        }
    }

    for (std::vector<Pair>::iterator itr = otherRelation.relations.begin(); itr != otherRelation.relations.end(); itr++)
    {
        if (!(is_member(*itr)))
        {
            return false;
        }   
    } 
    return true;
}

bool Relation::reflexive(){

    for (int i = 0; i < set.cardinality(); i++)
    {
        //Pair checkPair = {set.get_item(i), set.get_item(i)}
        if (!(is_member({set.get_item(i), set.get_item(i)})))
        {
            return false;
        }
    }
    return true;
        
}

bool Relation::irreflexive(){
    for (int i = 0; i < set.cardinality(); i++)
    {
        if(is_member({set.get_item(i), set.get_item(i)}))
        {
            return false;
        }
    }

    return true;
}

bool Relation::symmetric(){

    for (int i = 0; i < cardinality(); i++)
    {
        if (!(is_member({relations[i].second, relations[i].first})))
        {
            return false;
        }
    }
    return true;
}

bool Relation::asymmetric(){
    for (std::vector<Pair>::iterator itr = relations.begin(); itr != relations.end(); itr++)
    {
        if ((itr->first!=itr->second)&&(is_member({itr->second, itr->first})))
        {
            return false;
        }
    } 
    return true;
}

bool Relation::transitive(){
    for (std::vector<Pair>::iterator itr1 = relations.begin(); itr1 != relations.end(); itr1++)
    {
        if (itr1->first!=itr1->second)
        {
            for (std::vector<Pair>::iterator itr2 = relations.begin(); itr2 != relations.end(); itr2++)
            {
                if (itr2->first!=itr2->second)
                {
                    if (itr1->second==itr2->first)
                    {
                        if (!(is_member({itr1->first,itr2->second})))
                        {
                            return false;
                        }
                    }
                }                
            } 
        }
    } 
    return true;
}

bool Relation::is_function(){      
    for (std::vector<Pair>::iterator itr1 = relations.begin(); itr1 != relations.end(); itr1++)
    {
        for (std::vector<Pair>::iterator itr2 = relations.begin(); itr2 != relations.end(); itr2++)
        {
            if (itr1->first == itr2->first)
            {
                if (itr1->second != itr2->second)
                {
                    return false;
                }
            }     
        }  
    } 
    return true;
}

Relation Relation::inverse(){
    Relation inverse;
    for (std::vector<Pair>::iterator itr = relations.begin(); itr != relations.end(); itr++)
    {
        inverse.add_element({itr->second, itr->first});
    }
    return inverse;
}

Relation Relation::combination(Relation other){
    Relation combo;

    if (!(set.equal(other.set)))
    {
        return combo;
    }

    for (std::vector<Pair>::iterator itr1 = relations.begin(); itr1 != relations.end(); itr1++)
    {
        {
            for (std::vector<Pair>::iterator itr2 = other.relations.begin(); itr2 != other.relations.end(); itr2++)
            {
                {
                    if (itr1->second==itr2->first)
                    {
                        combo.add_element({itr1->first,itr2->second});   
                    }
                }                
            } 
        }
    } 
    return combo;
}


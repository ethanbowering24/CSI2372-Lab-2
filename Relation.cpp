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
    //Each relation iterates thorough its members and checks if the other set contains it. 
    //If either relation finds a member not present in the other then they are not equal.
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
    //for each element a in the set, the relation must contain (a,a)

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
    //for each element a in the set, the relation must not contain (a,a)
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
    //Iterate through the relation and for each element (a,b), if (b,a) is not an element the relation is not symmetric
    for (std::vector<Pair>::iterator itr = relations.begin(); itr != relations.end(); itr++)
    {
        if (!(is_member({itr->second, itr->first})))
        {
            return false;
        }
    }
    
    return true;
}

bool Relation::asymmetric(){
    //Iterate through the relation and for each element (a,b), if (b,a) is an element the relation is not asymmetric
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
    //interate through set, for each element (a,b) iterate through again to find a pair (b,c).
    //If it is not found, then this element does not effect if the relation is transitive or not.
    //If it is found, then for the relation to be transitive, (a,c) must also be a member.
    //If a=b then there is no point searching for (b,c) becaues if it is not found, there is no effect,
    //but if it is found then (a,c) will be equal to (b,c), which we already know exists.
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
    //Iterate through relation, for each pair (a,b), iterate again and for each element (a,c), if 
    //(b!=c) then then the relation is not a function.
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
    //Iterate through relation and for each element (a,b), add (b,a) to a new relation
    Relation inverse;
    for (std::vector<Pair>::iterator itr = relations.begin(); itr != relations.end(); itr++)
    {
        inverse.add_element({itr->second, itr->first});
    }
    return inverse;
}

Relation Relation::combination(Relation other){
    //Iterate through one relation and for each element (a,b), try to find (b,c) in the other relation. If found,
    //add (a,c) to a new relation. If the relations are equal returns an empty set.
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


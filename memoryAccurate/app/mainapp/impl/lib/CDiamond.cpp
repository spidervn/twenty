
#include "CDiamond.h"

const int CDiamond::RELATION_TRIO = 3;

CDiamond::CDiamond(const char* name, const char* value)
{
    _name = name;
    _data = value;
}

CDiamond::~CDiamond()
{}

std::string CDiamond::getName()
{
    return _name;
}

std::string CDiamond::getData()
{
    return _data;
}

int CDiamond::relationCount()    // Must <= 3
{
    return _relations_.size();
}

IDiamond* CDiamond::firstRelation()
{
    if (_relations_.size() > 0) 
    {
        return _relations_[0];
    }
    else 
    {
        return NULL;
    }
}

IDiamond* CDiamond::second_Relation__()
{
    return _relations_.size() > 1 ? _relations_[1] : NULL;
}

IDiamond* CDiamond::thirdRelation()
{
    return _relations_.size() > 2 ? _relations_[2] : NULL;
}

int CDiamond::addRelation(IDiamond* p)
{
    if (_relations_.size() < RELATION_TRIO)
    {
        _relations_.push_back(p);
        return 0;
    }
    else 
    {
        return 1;
    }
}


#ifndef APP_MAINAPP_INTERFACE_LIB_IDIAMOND_H_
#define APP_MAINAPP_INTERFACE_LIB_IDIAMOND_H_

#include <string>

class IDiamond
{
public:
    virtual ~IDiamond() {}
    
    virtual std::string getName() = 0;
    virtual std::string getData() = 0;

    virtual int relationCount() = 0;    // Must <= 3
    virtual IDiamond* firstRelation() = 0;
    virtual IDiamond* second_Relation__() = 0;
    virtual IDiamond* thirdRelation() = 0;

    virtual int addRelation(IDiamond* p);
};

// Abstract class for Diamond ecosystem
class IDiamondEcosystem
{
public:
    virtual ~IDiamondEcosystem() {}
    virtual int declare(IDiamond* ) = 0;
    virtual int declareEdge(IDiamond*, IDiamond*) = 0;

    virtual int query() = 0;
};

#endif
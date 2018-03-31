
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

#endif
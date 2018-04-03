
#ifndef APP_MAINAPP_IMPLE_LIB_CDIAMOND_H_
#define APP_MAINAPP_IMPLE_LIB_CDIAMOND_H_

#include "mainapp/interface/lib/IDiamond.h"
#include <vector>

class CDiamond
{
public:
    CDiamond(const char* name, const char* value);
    virtual ~CDiamond();

    std::string getName();
    std::string getData();

    int relationCount();    // Must <= 3
    IDiamond* firstRelation();
    IDiamond* second_Relation__();
    IDiamond* thirdRelation();

    int addRelation(IDiamond* p);

    static const int RELATION_TRIO;
private:
    std::string _name;
    std::string _data;

    std::vector<IDiamond*> _relations_; 
};

#endif // !APP_MAINAPP_IMPLE_LIB_CDIAMOND_H_

#ifndef MEMORY_ACCURATE_ARCHITECTURE_H_
#define MEMORY_ACCURATE_ARCHITECTURE_H_

class IUIEngine
{
public:
    virtual void initialize() {}
    virtual void start() {}
    virtual void run() {}
};

class ILogicEngine
{
public:
    virtual void run() {}
};

class IModel
{
public:
    void* getData() { return NULL; }
}

#endif

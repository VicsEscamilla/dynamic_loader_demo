#ifndef DYNAMIC_LOADER_H
#define DYNAMIC_LOADER_H

#include <string>

class DynamicLoader
{
public:
    DynamicLoader(std::string library);
    virtual ~DynamicLoader(void);
    void* getSymbol(std::string);
    bool isLoaded(void);

private:
    void* _handler;
};

#endif // DYNAMIC_LOADER_H

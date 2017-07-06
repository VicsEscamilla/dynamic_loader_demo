#include <dlfcn.h>

#include "dynamic_loader.h"

using namespace std;

DynamicLoader::DynamicLoader(string library) : _handler(NULL)
{
    _handler = dlopen(library.c_str(), RTLD_LAZY);
}

DynamicLoader::~DynamicLoader(void)
{
    if (isLoaded())
        dlclose(_handler);
}

void* DynamicLoader::getSymbol(string name)
{
    return dlsym(_handler, name.c_str());
}

bool DynamicLoader::isLoaded(void)
{
    return 0 != _handler;
}

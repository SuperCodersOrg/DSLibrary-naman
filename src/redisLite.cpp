#include "redisLite.h"
#include <string>
#include "HashMap.h"


void RedisCLI::handleSet(const std::string& key,const std::string& value){
    if (key.empty())
    {
        std::cout << "Error: Key cannot be empty." << std::endl;
        return;
    }

    if (value.empty())
    {
        std::cout << "Error: Value cannot be empty." << std::endl;
        return;
    }

    store.set(key, value);
    std::cout << "OK" << std::endl;
}

void RedisCLI::handleGet(const std::string& key){
   if (key.empty())
    {
        std::cout << "Usage: GET <key>" << std::endl;
        return;
    }

    try
    {
        std::cout << store.get(key) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void RedisCLI::handleDel(const std::string& key)
{
    if (key.empty())
    {
        std::cout << "Usage: DEL <key>" << std::endl;
        return;
    }

    if (!store.exists(key))
    {
        std::cout << "Key not found" << std::endl;
        return;
    }

    store.remove(key);
    std::cout << "OK" << std::endl;
}

void RedisCLI::handleExists(const std::string& key)
{
    if (key.empty())
    {
        std::cout << "Usage: EXISTS <key>" << std::endl;
        return;
    }

    if (store.exists(key))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}

void RedisCLI::handleCount()
{
    std::cout << store.getSize() << std::endl;
}

void RedisCLI::handleClear()
{
    store = HashMap<std::string, std::string>();
    std::cout << "OK" << std::endl;
}




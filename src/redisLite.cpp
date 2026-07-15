#include "redisLite.h"
#include <string>
#include "HashMap.h"
#include <iostream>
#include <sstream>


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

void RedisCLI::run()
{
    std::cout << "=====================================\n";
    std::cout << "        Welcome to Redis Lite\n";
    std::cout << "=====================================\n";
    std::cout << "Available Commands:\n";
    std::cout << "SET <key> <value>\n";
    std::cout << "GET <key>\n";
    std::cout << "DEL <key>\n";
    std::cout << "EXISTS <key>\n";
    std::cout << "COUNT\n";
    std::cout << "CLEAR\n";
    std::cout << "EXIT\n\n";

    std::string line;

    while (true)
    {
        std::cout << "redis> ";
        std::getline(std::cin, line);

        if (line.empty())
        {
            continue;
        }

        std::stringstream ss(line);

        std::string command;
        ss >> command;

        if (command == "SET")
        {
            std::string key;
            std::string value;

            ss >> key;
            ss >> value;

            handleSet(key, value);
        }
        else if (command == "GET")
        {
            std::string key;
            ss >> key;

            handleGet(key);
        }
        else if (command == "DEL")
        {
            std::string key;
            ss >> key;

            handleDel(key);
        }
        else if (command == "EXISTS")
        {
            std::string key;
            ss >> key;

            handleExists(key);
        }
        else if (command == "COUNT")
        {
            handleCount();
        }
        else if (command == "CLEAR")
        {
            handleClear();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting Redis Lite...\n";
            break;
        }
        else
        {
            std::cout << "Unknown command." << std::endl;
        }
    }
}




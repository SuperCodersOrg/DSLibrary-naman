#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "redisLite.h"

TEST(RedisLiteRunTest, SetAndGet)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Naman\n"
        "GET name\n"
        "EXIT\n"
    );

    std::ostringstream output;

    std::streambuf* cinBackup = std::cin.rdbuf();
    std::streambuf* coutBackup = std::cout.rdbuf();

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinBackup);
    std::cout.rdbuf(coutBackup);

    std::string result = output.str();

    EXPECT_NE(result.find("OK"), std::string::npos);
    EXPECT_NE(result.find("Naman"), std::string::npos);
    EXPECT_NE(result.find("Exiting Redis Lite"), std::string::npos);
}

TEST(RedisLiteRunTest, ExistsAndDelete)
{
    RedisCLI redis;

    std::istringstream input(
        "SET city Delhi\n"
        "EXISTS city\n"
        "DEL city\n"
        "EXISTS city\n"
        "EXIT\n"
    );

    std::ostringstream output;

    std::streambuf* cinBackup = std::cin.rdbuf();
    std::streambuf* coutBackup = std::cout.rdbuf();

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinBackup);
    std::cout.rdbuf(coutBackup);

    std::string result = output.str();

    EXPECT_NE(result.find("true"), std::string::npos);
    EXPECT_NE(result.find("false"), std::string::npos);
}

TEST(RedisLiteRunTest, CountAndClear)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "SET b 20\n"
        "COUNT\n"
        "CLEAR\n"
        "COUNT\n"
        "EXIT\n"
    );

    std::ostringstream output;

    std::streambuf* cinBackup = std::cin.rdbuf();
    std::streambuf* coutBackup = std::cout.rdbuf();

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinBackup);
    std::cout.rdbuf(coutBackup);

    std::string result = output.str();

    EXPECT_NE(result.find("2"), std::string::npos);
    EXPECT_NE(result.find("0"), std::string::npos);
}

TEST(RedisLiteRunTest, UnknownCommand)
{
    RedisCLI redis;

    std::istringstream input(
        "HELLO\n"
        "EXIT\n"
    );

    std::ostringstream output;

    std::streambuf* cinBackup = std::cin.rdbuf();
    std::streambuf* coutBackup = std::cout.rdbuf();

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinBackup);
    std::cout.rdbuf(coutBackup);

    EXPECT_NE(output.str().find("Unknown command"),
              std::string::npos);
}

TEST(RedisLiteRunTest, MissingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "GET abc\n"
        "EXIT\n"
    );

    std::ostringstream output;

    std::streambuf* cinBackup = std::cin.rdbuf();
    std::streambuf* coutBackup = std::cout.rdbuf();

    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinBackup);
    std::cout.rdbuf(coutBackup);

    EXPECT_NE(output.str().find("Key not found"),
              std::string::npos);
}
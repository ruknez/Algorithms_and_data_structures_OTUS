#pragma once
#include "iostream"
#include <string>
#include <optional>
#include <utility>

class cTester final
{
public:
    cTester(const std::string &path);
    cTester() = delete;

    template <class T>
    bool startTests(T func, const std::string &sumInform = "");

private:
    std::string pathToFiles_ = "";

    std::optional<std::pair<std::string, std::string>> readDataAndAnserFiles(int fileNumber) const;
    std::string readOneFile(const std::string &fileName) const;
};

//================================================================================
template <class T>
bool cTester::startTests(T func, const std::string &sumInform)
{
    int count = 0;
   
    while (auto st = readDataAndAnserFiles(count++))
    {
        if (func(st.value().first) == st.value().second)
        {
            std::cout << "Test " << count << " " <<  sumInform << " DONE!!!\n";
        }
        else
        {
             std::cout << "Test " << count << " " <<  sumInform << " FAIL!!!\n";
        }   
    }

    return true;
}
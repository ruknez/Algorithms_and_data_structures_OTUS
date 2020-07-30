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

    while (auto st = readDataAndAnserFiles(count))
    {
        auto totalValue = std::stoull(st.value().second);
        auto myValue = func(st.value().first);
        if (totalValue == static_cast<uint64_t>(myValue))
        {
            std::cout << "Test " << count << " " << sumInform << " DONE!!!\n";
        }
        else
        {
            std::cout << "Test " << count << " " << sumInform << " \x1b[31;40mFAIL!!!\x1b[0m\n";
            std::cout << "my Value = " << myValue << "  totalValue = " << totalValue << "\n\n";
            // std::cout << "data =  " << st.value().first << std::endl;
            // std::cout << "My rez = " << func(st.value().first) << " total = " << st.value().second << "\n\n";
        }
        count++;
    }
    std::cout << std::endl;
    return true;
}
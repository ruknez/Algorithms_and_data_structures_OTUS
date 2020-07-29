#include "cTester.h"
#include <fstream>
#include <sstream>

//================================================================================
cTester::cTester(const std::string &path) : pathToFiles_(path)
{
}

//================================================================================
std::string cTester::readOneFile(const std::string &fileName) const
{
    std::ifstream file;
    file.open(fileName);
    if (!file)
    {
        std::cout << "Cant find this file : " << fileName << std::endl;
        return {};
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

//================================================================================
std::optional<std::pair<std::string, std::string>> cTester::readDataAndAnserFiles(int fileNumber) const
{
    const std::string dataFileName = pathToFiles_ + "/test." + std::to_string(fileNumber) + ".in";
    const std::string anserFileName = pathToFiles_ + "/test." + std::to_string(fileNumber) + ".out";

    auto data = readOneFile(dataFileName);
    auto anser = readOneFile(anserFileName);
    if (data.empty() || anser.empty())
    {
        return {};
    }

    return make_pair(data, anser);
}
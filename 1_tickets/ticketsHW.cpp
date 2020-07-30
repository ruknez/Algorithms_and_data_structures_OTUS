#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../testSystem/cTester.h"

int stringLenth(const std::string &st)
{
    int count = 0;
    for (size_t i = 0; i < st.length(); i++)
    {
        if ((static_cast<int>(st[i]) < 7 || static_cast<int>(st[i]) > 15)) //&& static_cast<int> (st[i]) != 64)
        {
            count++;
        }
    }
    return count;
}

std::map<int, std::vector<uint64_t>> creatTable(const int maxN)
{
    if (maxN <= 0)
        return {};

    std::map<int, std::vector<uint64_t>> myTable;

    myTable[1] = std::vector<uint64_t>(10, 1);

    for (int count = 2; count <= maxN; count++)
    {
        std::vector<uint64_t> tmpVector(myTable[count - 1].size() + 9);
        for (uint64_t k = 0; k < tmpVector.size(); k++)
        {
            uint64_t sum = 0;
            for (uint64_t l = 0; l <= 9; l++)
            {
                if ((k - l >= 0) && (myTable[count - 1].size() > (k - l)))
                {
                    sum += myTable[count - 1][k - l];
                }
            }
            tmpVector[k] = sum;
        }
        myTable[count] = tmpVector;
    }

    return myTable;
}

uint64_t luckyTicketsCount(std::string N_)
{
    int N = std::stoi(N_);
    auto myTable = creatTable(N);
    uint64_t rez = 0;
    for (const auto &num : myTable[N])
    {
        rez += num * num;
    }

    return rez;
}

int main()
{

    cTester stringTest("0.String");

    stringTest.startTests(stringLenth, "lenth");

    cTester ticetTest("1.Tickets");

    ticetTest.startTests(luckyTicketsCount, "tickets");

    return 0;
}
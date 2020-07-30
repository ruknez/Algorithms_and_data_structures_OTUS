#include <iostream>
#include <string>

#include "../testSystem/cTester.h"

std::string stringLenth(const std::string &st)
{
    int count = 0;
    for (size_t i = 0; i < st.length(); i++)
    {
        if ((static_cast<int>(st[i]) < 7 || static_cast<int>(st[i]) > 15)) //&& static_cast<int> (st[i]) != 64)
        {
            count++;
        //    std::cout << "ch = " << (st[i]) << "  " << static_cast<int>(st[i]) << "  count = " << count << std::endl;
        }
    }
    //std::cout << "count = " << count << " lenth = " << st.length() << std::endl;
    return std::to_string(count);
}

int main()
{

    cTester stringTest("0.String");

    stringTest.startTests(stringLenth, " lenth");

    return 0;
}
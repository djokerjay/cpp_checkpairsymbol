#include <iostream>
#include <string>
using namespace std;

string CheckCloseSymbol(string symbol)
{
    string result;

    if (symbol == "(")
    {
        result = ")";
    }
    else if (symbol == "[")
    {
        result = "]";
    }
    else if (symbol == "{")
    {
        result = "}";
    }
    else if (symbol == "/*")
    {
        result = "*/";
    }
    return result;
}

bool checksymbol(string input)
{
    string closesymbol;
    bool special = false;
    for (int x = 0; x < input.size(); x++)
    {
        special = false;
        if (input[x] != ' ')
        {
            if (input[x] == '/')
            {
                if ((x + 1) <= input.size())
                {
                    if (input[x + 1] == '*')
                    {
                        closesymbol = CheckCloseSymbol("/*");
                        input[x] = ' ';
                        input[x + 1] = ' ';

                        special = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                string chr;
                chr += input[x];
                input[x] = ' ';
                closesymbol = CheckCloseSymbol(chr);
            }

            if (closesymbol == "")
            {
                return false;
            }
            bool found = false;
            for (int y = x; y < input.size(); y++)
            {
                if (special == true)
                {
                    if (input[y] == '*')
                    {
                        if ((y + 1) <= input.size())
                        {
                            if (input[y + 1] == '/')
                            {
                                input[y] = ' ';
                                input[y + 1] = ' ';

                                found = true;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    if (input[y] == closesymbol[0])
                    {
                        input[y] = ' ';
                        found = true;
                        break;
                    }
                }
            }
            if (found == false)
            {
                return false;
            }
        }
    }

    for (int x = 0; x < input.size(); x++)
    {
        if (input[x] != ' ')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string userinput;

    cout << "Enter Symbols:";
    cin >> userinput;
    bool result = checksymbol(userinput);
    if (result == true)
    {
        cout << "Success";
    }
    else
    {
        cout << "Failed";
    }
    return 0;
}

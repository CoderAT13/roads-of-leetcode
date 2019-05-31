#include <iostream>
using namespace std;


bool isdigit(const char c)
{
    return (c >= '0' && c <= '9');
}
bool isspace(const char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

bool isNumber(string s)
{
    bool point = false;
bool hasE = false;
    int i = 0;
    while (isspace(s[i]))
        i++;
    
    if (i == s.length())
        return false;
    if (s[i]=='+' || s[i]=='-') i++;
    int head = i;
    for (; i < s.length(); ++i)
    {
        // if meet point
        if (s[i] == '.')
        {
            if (hasE == true || point == true)
            {
                return false;
            }
            if (i == head && !isdigit(s[i + 1]))
            {
                return false;
            }
            point = true;
            continue;
        }

        if (s[i] == 'e')
        {
            if (hasE == true || i == head)
            {
                return false;
            }
            ++i;
            if (s[i] == '+' || s[i] == '-')
                i++;
            if (!isdigit(s[i]))
                return false;

            hasE = true;
            continue;
        }

        if (isspace(s[i]))
        {
            for (; i < s.length(); ++i)
            {
                if (!isspace(s[i]))
                    return false;
            }
            return true;
        }
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main(){
    cout << isNumber("-.") << endl;
    return 0;
}
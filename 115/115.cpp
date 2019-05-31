#include <vector>
#include <iostream>
#include <map>

using namespace std;

int numDistinct(string S, string T)
{
    map<char, vector<int> > pos_map;
    vector<unsigned int> numOfSubSeq(T.length() + 1, 0);
    numOfSubSeq[0] = 1;
    for (int i = T.length()-1; i >= 0; --i)
    {
        pos_map[T[i]].push_back(i);
    }

    for (int i = 0; i < S.length(); ++i)
    {
        if (pos_map.find(S[i]) != pos_map.end())
        {
            for (int j = 0; j < pos_map[S[i]].size(); j++)
            {
                int pos = pos_map[S[i]][j];
                numOfSubSeq[pos + 1] += numOfSubSeq[pos];
            }
        }
    }

    return numOfSubSeq[T.length()];
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << numDistinct(a, b) << endl;
    return 0;
}
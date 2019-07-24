#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    string line;
    int n;
    int clausulas;
    int i;
    int j = 1;

    while (getline(cin, line))
    {
        if (line[0] == 'c')
        {
            cout << "%" << line.c_str() + 1 << endl;
        }
        else if (line[0] == 'p')
        {
            stringstream aux(line);
            string token;

            aux >> token;
            aux >> token;

            aux >> n;
            aux >> clausulas;

            cout << "int: n = " << n << endl;
            cout << "int: cl = " << clausulas << endl
                 << endl;
            cout << "array[1..n] of var bool: v;" << endl;
            cout << "array[1..cl] of var bool: c;" << endl
                 << endl;
        }
        else
        {
            stringstream aux(line);

            if (!(aux >> i) || i == 0)
            {
                continue;
            }
            cout << "constraint c[" << j << "] = ";
            j++;

            if (i < 0)
            {
                cout << "not ";
                i = i * -1;
            }

            cout << "v[" << i << "] ";

            while (aux >> i and i != 0)
            {
                cout << "\\/ ";
                if (i < 0)
                {
                    cout << "not ";
                    i = i * -1;
                }

                cout << "v[" << i << "] ";
            }
            cout << ";" << endl;
        }
    }

    cout << "solve satisfy;" << endl;
    return 0;
}
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

            for (int j = 1; j <= n; j++)
            {
                cout << "var 0..1: X" << j << "; var 0..1: n_X" << j << ";" << endl;
                cout << "constraint X" << j << " + n_X" << j << " = 1;" << endl
                     << endl;
            }
        }
        else
        {
            stringstream aux(line);
            string lineaImp;
            lineaImp = "constraint ";
            while (aux >> i)
            {
                if (i < 0)
                {
                    lineaImp += "n_";
                    i = i * -1;
                }
                if (i == 0)
                {
                    size_t len = lineaImp.length();
                    cout << lineaImp.substr(0, len - 2) << ">=1;" << endl;
                }
                else
                {
                    lineaImp += "X" + to_string(i) + " ";
                    lineaImp += "+ ";
                }
            }
        }
    }

    cout << "solve satisfy;" << endl;
    for (int k = 1; k <= n; k++)
    {
        cout << "output[";
        cout << "\"X" << k << "= \" , show(X" << k << "), \"; -X" << k << "=\" , show(n_X" << k << "), ";
        cout << "];";
        cout << " output[\" \\n \"];" << endl;
    }

    return 0;
}
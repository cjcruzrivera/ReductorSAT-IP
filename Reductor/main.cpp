#include <stdio.h>
#include <iostream> 
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){

    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    string line;
    while(getline(cin, line)){
        cout << line;
    }
    return 0;
}
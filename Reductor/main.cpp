#include <stdio.h>
#include <iostream> 
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    printf( "%s \n", argv[1]);

    string path = argv[1];
    freopen(path, "r", stdin);

    // char line;
    // while(getline(cin, line)){
        // printf(line);
        // printf("\n");
    // }
    return 0;
}
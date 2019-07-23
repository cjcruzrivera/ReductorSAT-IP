# apt-get install g++

g++ -std=c++11 -o Reductor/main Reductor/main.cpp

FILES=InstanciasSAT/*

for f in $FILES
do
    filename=$(basename -- "$f")
    filewithoutExt="${filename%.*}"
    ./Reductor/main $filewithoutExt 
done 

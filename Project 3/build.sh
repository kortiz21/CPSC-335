#!/bin/bash

#Clear any previously compiled files
rm *.o

echo "compile exhaustive.cpp using g++ compiler standard 2017"
g++ -std=c++17 exhaustive.cpp -o exhaustive

echo "compile dynamic.cpp using g++ compiler standard 2017"
g++ -std=c++17 dynamic.cpp -o dynamic

echo "Using Dynamic Programming:"
echo "-----------------------------------------------------------------"

for i in `seq 6`
do
    ./dynamic < "$i.in"
    echo "-----------------------------------------------------------------"
done

echo "Using Exhaustive Search:"
echo "-----------------------------------------------------------------"

for i in `seq 6`
do
    ./exhaustive < "$i.in"
    echo "----------------------------------------------------------------"
done


# For cleaner working directory, remove all .o files
rm *.o

echo "Script file terminated."
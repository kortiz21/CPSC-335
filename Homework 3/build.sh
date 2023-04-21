#!/bin/bash

#Clear any previously compiled files
rm *.o

echo "compile main.cpp using g++ compiler standard 2017"
g++ -std=c++17 main.cpp -o main

echo "Run the main Program:"
./main

# For cleaner working directory, remove all .o files
rm *.o

echo "Script file terminated."
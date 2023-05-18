#!/bin/bash

rm main

echo "Compile main.cpp using g++ compiler"
g++ main.cpp -o main

echo "Run the Largest Sum Array program:"
./main < 1.in

echo "Build process completed"


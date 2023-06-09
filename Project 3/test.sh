#!/bin/bash
echo "-----------------------------------------------------------------"
echo "Algorithmic Efficieny Comparisons"
echo "-----------------------------------------------------------------"
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

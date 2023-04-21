// Kevin Ortiz
// Homework 3:
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// function prototype
// a daily ski rental price ski_rental_price > 0, purchase price purchase_price > 0, and number of days number_of_days>0
// @param: ski_rental_price - double - price per day to rent skis
// @param: purchase_price - double - price to buy skis
// @param: number_of_days - int - number of days to rent skis
// return: bool -returns True if it is cheaper to rent skis for number_of_days days at ski_rental_price dollars per day, or False if it is
// cheaper to buy skis for purchase_price dollars
bool ski_rental(double ski_rental_price, double purchase_price, int number_of_days);
// function prototype
// a list of integers list
// @param: list - vector<int> - list of integers
// return: vector<int> - returns a list of integers in reverse order
vector<int> list_reversal(vector<int> list);
// function prototype
// takes in two integers a and b where a < b and returns a list of all 
// Pythagorean triples with sides a, b, and c, such that 
// a <= x <= y <= z <= b and x2 + y2 = z2 or none if no such triples exist
// @param: a - int - first integer
// @param: b - int - second integer
// return: vector<vector<int>> - returns a list of all Pythagorean triples with sides a, b, and c, such that a <= x <= y <= z <= b and x2 + y2 = z2 or none if no such triples exist
vector<vector<int>> pythagorean_triples_problem(int a, int b);
// function prototype
// Given an array A of size N-1 that contains all integers in the 
// range of 1 to N, except one missing integer, design a pseudocode 
// for an efficient algorithm (the time complexity must be O(N) to 
// find the missing number. There are no duplicates in the list. 
// You may not create another array to solve this problem.
// @param: list - vector<int> - list of integers
// @param: N - int - range of 1 to N
// return: missing number
int find_missing_number(vector<int> list, int N);
// function prototype
// takes in two lists of integers L and R and returns a union of the two lists by reduction algorithm
// @param: L - vector<int> - list of integers
// @param: R - vector<int> - list of integers
// return: S - vector<int> - returns a union of the two lists
vector<int> setunion(vector<int> L, vector<int> R);
// function prototype
// takes in two lists of integers L and R and returns a difference L - R of the two lists by reduction algorithm
// @param: L - vector<int> - list of integers
// @param: R - vector<int> - list of integers
// return: S - vector<int> - returns a difference of the two lists
vector<int> setdifference(vector<int> L, vector<int> R);
// function prototype
// sorting algorithm whose time complexity is as follows:
// a - when the input happens to be already non-decreasing, the algorithm takes only O(n) time;
// b - when the input happens to be already non-increasing (i.e. reverse-sorted), the algorithm takes only O(n) time;
// c - but in any other situation, the algorithm may take O(n2) time.
// @param: arr - vector<int> - list of integers
// return: void
void sorting(vector<int> &array);

// main driver
int main()
{
    /*
    bool result = ski_rental(10, 100, 5);
    if (result == true)
        cout << "It is cheaper to rent skis" << endl;
    else
        cout << "It is cheaper to buy skis" << endl;

    cout << "" << endl;

    vector<int> list = { 1, 2, 3, 4, 5 };
    vector<int> reversed_list = list_reversal(list);
    for (int i = 0; i < reversed_list.size(); i++)
        cout << reversed_list[i] << endl;

    vector<vector<int>> pythagorean_triples = pythagorean_triples_problem(1, 2);
    if (pythagorean_triples.size() == 0)
        cout << "No Pythagorean triples exist" << endl;
    else
        for (int i = 0; i < pythagorean_triples.size(); i++)
            cout << pythagorean_triples[i][0] << " " << pythagorean_triples[i][1] << " " << pythagorean_triples[i][2] << endl;
    
    vector<int> list = { 1, 3, 4, 5 };
    int missing_number = find_missing_number(list, 5);
    cout << missing_number << endl;
    
    vector<int> L = { 3, 2, 1, 9, 4 };
    vector<int> R = { 4, 5, 6, 7, 8 };
    vector<int> S = setdifference(L, R);
    //vector<int> S = setunion(L, R);
    for (int i = 0; i < S.size(); i++)
        cout << S[i] << endl;
    cout << "" << endl;
    */
    vector<int> arr1 = {1, 2, 3, 4, 5}; // already sorted
    vector<int> arr2 = {5, 4, 3, 2, 1}; // already reverse-sorted
    vector<int> arr3 = {3, 5, 2, 1, 4}; // unsorted
    
    sorting(arr1);
    sorting(arr2);
    sorting(arr3);
    
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}
bool ski_rental(double ski_rental_price, double purchase_price, int number_of_days) {
    // variable declaration
    // rental_cost: type double - rental cost
    double rental_cost = ski_rental_price * number_of_days;
    // purchase_cost: type double - purchase cost
    double purchase_cost = purchase_price;
    // if rental_cost < purchase_cost
    if (rental_cost < purchase_cost)
        return true;
    else
        return false;
}
vector<int> list_reversal(vector<int> list) {
    // variable declaration
    // list_size: type int - size of list
    int list_size = list.size();
    // temp: type int - temporary variable
    int temp;
    // for loop
    for (int i = 0; i < list_size / 2; i++) {
        temp = list[i];
        list[i] = list[list_size - i - 1];
        list[list_size - i - 1] = temp;
    }
    return list;
}
vector<vector<int>> pythagorean_triples_problem(int a, int b) {
    // variable declaration
    // pythagorean_triples: type vector<vector<int>> - list of pythagorean triples
    vector<vector<int>> pythagorean_triples;
    // x: type int - x value
    int x;
    // y: type int - y value
    int y;
    // z: type int - z value
    int z;
    // for loop
    for (x = a; x <= b; x++) {
        for (y = x; y <= b; y++) {
            for (z = y; z <= b; z++) {
                if (x * x + y * y == z * z) {
                    vector<int> triple = { x, y, z };
                    pythagorean_triples.push_back(triple);
                }
            }
        }
    }
    return pythagorean_triples;
}
int find_missing_number(vector<int> list, int N) {
    // variable declaration
    // sum: type int - sum of all numbers in list
    int sum = 0;
    // for loop
    for (int i = 0; i < list.size(); i++)
        sum += list[i];
    // return N * (N + 1) / 2 - sum
    return N * (N + 1) / 2 - sum;
}
vector<int> setunion(vector<int> L, vector<int> R) {
    // preprocessing
    // n/a

    // sorting algorithm
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    // post processing

    // variable declaration
    // S: type vector<int> - union of L and R
    vector<int> S;
    // li: type int - index for L
    int li = 0;
    // ri: type int - index for R
    int ri = 0;
    // while loop
    while (li < L.size() && ri < R.size()) {
        if (L[li] < R[ri]) {
            S.push_back(L[li]);
            li++;
        }
        else if (L[li] > R[ri]) {
            S.push_back(R[ri]);
            ri++;
        }
        else {
            S.push_back(L[li]);
            li++;
            ri++;
        }
    }
    // while loop
    while (li < L.size()) {
        S.push_back(L[li]);
        li++;
    }
    // while loop
    while (ri < R.size()) {
        S.push_back(R[ri]);
        ri++;
    }
    return S;
}
vector<int> setdifference(vector<int> L, vector<int> R) {
    // preprocessing
    // n/a

    // sorting algorithm
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    // post processing

    // variable declaration
    // S: type vector<int> - difference of L and R
    vector<int> S;
    // li: type int - index for L
    int li = 0;
    // ri: type int - index for R
    int ri = 0;
    // while loop
    while (li < L.size() && ri < R.size()) {
        if (L[li] < R[ri]) {
            S.push_back(L[li]);
            li++;
        }
        else if (L[li] > R[ri]) {
            ri++;
        }
        else {
            li++;
            ri++;
        }
    }
    // while loop
    while (li < L.size()) {
        S.push_back(L[li]);
        li++;
    }
    return S;
}
void sorting(vector<int> &array) {
    int n = array.size();
    bool nonDec = true, nonInc = true;
    
    // Check if already non-decreasing or non-increasing
    for (int i = 1; i < n; i++) {
        if (array[i] < array[i-1]) {
            nonDec = false;
        }
        if (array[i] > array[i-1]) {
            nonInc = false;
        }
    }
    if (nonDec || nonInc) {
        return; // already sorted
    }
    
    // Otherwise, perform selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
}
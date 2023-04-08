#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
// merge all passed in vector and sort in ascending order
vector<vector<int>> merge(int size_of_vector, int size_of_array);
// print 2D vector
void print2D(vector<vector<int>> myVector);
// main driver
int main() {
    vector<vector<int>> merged_list;
    merged_list = merge(4,3);
    print2D(merged_list);
    return 0;
}
// print 2D vector
void print2D(vector<vector<int>> myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        cout << "[";
        for (int j = 0; j < myVector[i].size(); j++) {
            if(j+1 == myVector[i].size())
                cout << myVector[i][j] << "";
            else
                cout << myVector[i][j] << ", ";   
        }
        cout << "]" << endl;
    }
}
// merge all passed in vector and sort in ascending order
vector<vector<int>> merge(int size_of_vector, int size_of_array) {
    vector<vector<int>> fvector (size_of_vector);
    vector<vector<vector<int>>> list;
    // hold text file content
    string line;
    // read from the text file
    ifstream myfile("in2c.txt");
    // do while file is open
    if (myfile.is_open()) {
        // read the file line by line
        // keep track of vector order
        int vector_counter = -1;
        while (getline(myfile, line)) {
            string parse_line = "";
            int start_pos = 0;
            // set starting position for when to read in contents of vectors in file
            for (int i = 0; i < line.size(); i++){
                if (line[i] == '[' && line[i+1] == ' ') {
                    start_pos = i + 3;
                    vector_counter++;
                    break;
               }
               if (line[i] == '[' && line[i+1] != ' ') {
                    start_pos = i + 1;
                    vector_counter++;
                    break;
               }
            }
            // parse to keep int(s) only
            int number;
            for (int i = start_pos; i < line.size(); i++) {
                if (line[i] == '-') {
                    parse_line = "-";
                }
                if (isdigit(line[i])) {
                    parse_line += line[i];
                }
                if (line[i+1] == ',') {
                    number = stoi(parse_line);
                    fvector.at(vector_counter).push_back(number);
                    parse_line = "";
                }
                if (line[i] == ']' && line[i+1] == ',') {
                    break;         
                }
                if (line[i] == ']' && line[i+1] == ' ') {
                    number = stoi(parse_line);
                    fvector.at(vector_counter).push_back(number);
                    parse_line = "";
                    list.push_back(fvector);
                    fvector.clear();
                    vector_counter = -1;
                    fvector.resize(size_of_vector);
                    break;                       
                }
            }
        }
    }
    // close myfile
    myfile.close();
    vector<vector<int>> myVector;
    // vector of smallest numbers in myVector
    vector<vector<int>> smallest (size_of_array);
    // loop through myVector
    for (int k = 0; k < list.size(); k++) {
        myVector = list.at(k);
        for (int i = 0; i <= myVector.size(); i++) {
            // set min to first element in vector of vector
            int min = myVector[0][0];
            // track position of where min is found
            int pos = 0;
            // loop through first element of each vector
            for (int j = 1; j < myVector.size(); j++) {
                // if smallest set new small and track position
                if (min > myVector[j][0]) {
                    min = myVector[j][0];
                    pos = j;
                }
            }
            // insert smallest number into vector
            smallest.at(k).push_back(min);
            // delete that number from myVector
            myVector.at(pos).erase(myVector.at(pos).begin());
            // if vector is empty delete from vector of vector
            if(myVector.at(pos).empty()) {
                myVector.erase(myVector.begin() + pos);
            }
            // reset counter for first loop
            i = 0;
        }
    }
    return smallest;
}
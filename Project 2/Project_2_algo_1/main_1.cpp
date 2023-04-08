#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <map>
#include <iterator>

using namespace std;

// get indices of target words and actual words
map<int,map<int,string>>  get_target_indices();
// print map<int, map<int, string> > map of maps that is passed in by reference myMap
void print(map<int,map<int,string>> &myMap);
// main driver
int main() {
    map<int, map<int,string>> meeting_times;
    meeting_times = get_target_indices();
    cout << "The available meetings time are:" << endl;
    print(meeting_times);
    return 0;
}
// print map<int, map<int, string> > map of maps that is passed in by reference myMap
void print(map<int,map<int,string>> &myMap) 
{
    map<int, map<int,string>>::iterator itr1;
    map<int,string>::iterator itr2;
    // iterate through map to print out the key and value
    cout << endl;
    
    for (itr1 = myMap.begin(); itr1 != myMap.end(); ++itr1)
    {
        for(itr2 = itr1->second.begin(); itr2 != itr1->second.end(); ++itr2)
        {
            if (itr2 == itr1->second.begin())
                cout << "Output_order = [";
            if(next(itr2) == itr1->second.end())
                cout << "" << itr2->first << "";
            else
                cout << "" << itr2->first << ", ";
        }
        cout << "]" << endl;

        for(itr2 = itr1->second.begin(); itr2 != itr1->second.end(); ++itr2)
        {
            if (itr2 == itr1->second.begin())
                cout << "Output_array = [";
            if(next(itr2) == itr1->second.end())
                cout << "'" << itr2->second << "'";
            else
                 cout << "'" << itr2->second << "', ";               
        }
        cout << "]" <<endl << endl;
    }
}
// get indices of target words and actual words
map<int,map<int,string>> get_target_indices(){
    // declaring arrays to be used
    array<string,1>cities_1 = {""};
    array<string,1>cities_2 = {""};
    array<string,1>cities_3 = {""};
    array<string,4>target_1 = {"", "", "", ""};
    array<string,4>target_2 = {"", "", "", ""};
    array<string,4>target_3 = {"", "", "", ""};
    // hold text file content
    string line;
    // read from the text file
    ifstream myfile("in2a.txt");
    // do while file is open
    if (myfile.is_open()) {
        // read the file line by line
        // keep track of array order
        int array_counter = 0;
        while (getline(myfile, line)) {
            string parse_line = "";
            int start_pos = 0;
            // set starting position for when to read in contents of array in file
            for(int i = 0; i < line.size(); i++){
                if(line[i] == '[') {
                    start_pos = i;
                    array_counter++;
                    break;
               }
            }
            // parse to keep alpha only
            int comma_counter = 0;
            for(int i = start_pos; i < line.size(); i++) {
                if (isalpha(line[i]) && line[start_pos] == '[') {
                    parse_line += line[i];
                }
                // seperate parse with commas
                if (line[i+1] == ',') {
                    if(array_counter == 2)
                        target_1[comma_counter] = parse_line;
                    if(array_counter == 4)
                        target_2[comma_counter] = parse_line;
                    if(array_counter == 6)
                        target_3[comma_counter] = parse_line;
                    comma_counter++;
                    parse_line = "";
                }
                // if at end of line insert into arrays
                if (line[i] == ']') {
                    if (array_counter == 1) {
                        cities_1[0] = parse_line;
                        break;
                    }
                    if(array_counter == 2) {
                        target_1[comma_counter] = parse_line;
                        break;
                    }
                    if (array_counter == 3) {
                        cities_2[0] = parse_line;
                        break;
                    }
                    if(array_counter == 4) {
                        target_2[comma_counter] = parse_line;
                        break;
                    }
                    if (array_counter == 5) {
                        cities_3[0] = parse_line;
                        break;
                    }
                    if(array_counter == 6) {
                        target_3[comma_counter] = parse_line;
                        break;
                    }
                }
            }
        }
    }
    // close myfile
    myfile.close();
    // map to hold indices
    map<int,string> indices_1;
    map<int,string> indices_2;
    map<int,string> indices_3;
    // position of current index
    int index = 0;
    // find indicies of target words in cities array
    for (int i = 0; i < target_1.size(); i++) {
        if (cities_1[0].find(target_1[i])) {
            index = cities_1[0].find(target_1[i]);
            indices_1.insert(pair<int,string>(index, target_1[i]));
        }
        if (cities_2[0].find(target_2[i])) {
            index = cities_2[0].find(target_2[i]);
            indices_2.insert(pair<int,string>(index, target_2[i]));
        }
        if (cities_3[0].find(target_3[i])) {
            index = cities_3[0].find(target_3[i]);
            indices_3.insert(pair<int,string>(index, target_3[i]));
        }
    }
    map<int, map<int,string>> indices;
    indices.insert(pair<int,map<int,string>>(0,indices_1));
    indices.insert(pair<int,map<int,string>>(1,indices_2));
    indices.insert(pair<int,map<int,string>>(2,indices_3));
    return indices;
}
#include <iostream>
#include <string>

using namespace std;
// run length encoding to compress a string
string encoding(string n);
// main driver
int main() {
    string run1;
    run1 = "ddd";
    string run2;
    run2 = "heloooooooo there";
    string run3;
    run3 = "choosemeeky and tuition-free";
    cout << "String '" << run1 << "' becomes '" << encoding(run1) << "'" << endl << endl;
    cout << "String '" << run2 << "' becomes '" << encoding(run2) << "'" << endl << endl;
    cout << "String '" << run3 << "' becomes '" << encoding(run3) << "'" << endl << endl;
    return 0;
}
// run length encoding to compress a string
string encoding(string n) {
    string kx;
    string alphabet;
    // loop through every element in passed in string n
    for (int i = 0; i < n.size(); i++) {
        size_t found = alphabet.find(n[i]);
        int counter;
        counter = 1;
        // not found in our alphabet so adding to it
        if (found == string::npos) {
            alphabet += n[i];
        }
        // a space was found indicating a new word, resetting list
        if (n[i] == ' ') {
            alphabet = "";
        }
        // search for char in string n
        for (int j = i + 1; j < n.size(); j++) {
            //A space was found, breaking from loop
            if ( (n[j] == ' ') ) {
                break;
            }
            if ( n[i] == n[j]) {
                counter++;
            }
            //Next element is not the same, exiting loop
            if(n[j] != n[j+1]){
                break;
            }
        }
        if (counter == 1) {
            kx = kx + n[i];
        }
        else {
            kx = kx + to_string(counter) + n[i];
        }
        //move to next string position
        i += counter-1;
    }
    return kx;
}
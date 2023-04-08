// Kevin E Ortiz
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
// Submitted: 2/26/23

#include <iostream>
#include <array>

int get_index();

// main driver
int main() {

    int preferred_starting_city;
    preferred_starting_city = get_index();
    std::cout << "The preferred starting city is " << preferred_starting_city << std::endl;
    return 0;
}

// function to return index of preferred starting city
int get_index() {
    // create index for preferred starting city
    int index;
    index = 0;
    // create array for distance between neighboring cities
    std::array<int, 5> distances {5,25,15,10,15};
    // create array for gas available at each city
    std::array<int, 5> gas {1,2,1,0,3};
    // create variable for miles per gallon of the car
    int mpg;
    mpg = 10;
    // create variable for amount of gas in tank of the car
    int tank;
    tank = 0;
    // create variable for amount of miles left in the car
    int miles;
    miles = 0;
    // variable to end while loop
    int end;
    end = 0;
    // counter for while loop
    int counter;
    counter = 0;
    // while loop to run algorithmn, exits when last city is ran
    while(end != 1) {
        for (int i = 0; i < distances.size(); i++) {
            // gas in car before departure
            tank += gas[i];
            // miles in car before departure
            miles += (tank * mpg);
            // when not enough mileage to reach next city exit for loop
            if ( miles < distances[i]) {
                break;
            }       
            // miles in car after departure
            miles -= distances[i];
            // gas after departure
            tank -= gas[i];
            if ((i+1) == distances.size())
                index = counter;
        }
        // temporary array to hold distance array for moving on to next city
        std::array<int, 5> temp_distances;
        // temporary array to hold gas array for moving on to next city
        std::array<int, 5> temp_gas;
        // for loop to move over gas and distance array for next check
        for (int i = 0; i < distances.size(); i++) {
            temp_distances[i] = distances[i];
            temp_gas[i] = gas[i];
            // out of bounds check to loop back to beginning 
            if ((i+1) == distances.size()) {
                distances[i] = temp_distances[temp_distances.size() - i - 1];
                gas[i] = temp_gas[temp_gas.size() - i - 1];
                break;
            }
            // move city distances one over
            distances[i] = distances[i+1];
            // move city gas one over
            gas[i] = gas[i+1];
        }
        // increment city counter to move onto next
        counter++;
        // reset values for next city
        tank = 0;
        miles = 0;
        // exit while loop
        if (counter == distances.size())
            end = 1;
    } 
    // return preferred starting city
    return index;
}
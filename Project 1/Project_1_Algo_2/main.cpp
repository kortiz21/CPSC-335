// Kevin E Ortiz
// Algorithm 2: Matching Group Schedules
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
// Submitted: 2/26/23

#include <iostream>
#include <map>
#include <string>
#include <iterator>

// print map that is passed in by reference myMap
void print(std::map<std::string, std::string> &myMap);

// print map that is passed in by reference myMap
void printd(std::map<double, double> &myMap);

// convert string time to double time with parameter map
std::map<double, double> convert_time_to_double(std::map<std::string, std::string> map);

// convert double time  to string time with parameter map
std::map<std::string, std::string> convert_double_to_time(std::map<double, double> map);

// create a map of available meetings
std::map<std::string, std::string> available_meetings();

// main driver
int main()
{
    std::map<std::string, std::string> meeting_times;
    meeting_times = available_meetings();
    std::cout << "The available meetings time are:" << std::endl;
    print(meeting_times);
    return 0;
}

// print string map that is passed in by reference myMap
void print(std::map<std::string, std::string> &myMap)
{
    std::map<std::string, std::string>::iterator itr;
    std::cout << "[";
    // iterate through map to print out the key and value
    for (itr = myMap.begin(); itr != myMap.end(); ++itr)
    {
        std::cout << " ['" << itr->first << "', '" << itr->second << "']";
    }
    std::cout << " ]";
}

// print double map that is passed in by reference myMap
void printd(std::map<double, double> &myMap)
{
    std::map<double, double>::iterator itr;
    std::cout << "[";
    // iterate through map to print out the key and value
    for (itr = myMap.begin(); itr != myMap.end(); ++itr)
    {
        std::cout << " [" << itr->first << ", " << itr->second << "]";
    }
    std::cout << " ]";
}

// convert string time to double time with parameter map
std::map<double, double> convert_time_to_double(std::map<std::string, std::string> map)
{
    // declare variables to parse in string elements of map and convert to double
    std::string begin_time;
    begin_time = "";
    std::string end_time;
    end_time = "";
    int position_colon;
    position_colon = 0;
    int hour;
    hour = 0;
    double minute;
    minute = 0.0;
    double begin;
    begin = 0.0;
    double end;
    begin = 0.0;
    // iterator to loop through map element
    std::map<std::string, std::string>::iterator itr;
    std::map<double, double> temp;
    // for loop to iterate through map to the colon to parse into a double
    for (itr = map.begin(); itr != map.end(); ++itr)
    {
        begin_time = itr->first;
        for (int i = 0; i < begin_time.size(); i++)
        {
            // take into account colon position if at 1 or 2
            if (begin_time.at(i) == ':')
            {
                position_colon = i;
                if (position_colon == 1)
                {
                    // parse into string
                    hour = std::stoi(begin_time.substr(0));
                    minute = std::stoi(begin_time.substr(2, 2));
                    begin = hour + minute / 60;
                }
                else
                {
                    // parse into string
                    hour = std::stoi(begin_time.substr(0, 2));
                    minute = std::stoi(begin_time.substr(3, 2));
                    begin = hour + minute / 60;
                }
            }
        }
        end_time = itr->second;
        for (int i = 0; i < end_time.size(); i++)
        {
            if (end_time.at(i) == ':')
            {
                position_colon = i;
                if (position_colon == 1)
                {
                    // parse into string
                    hour = std::stoi(end_time.substr(0));
                    minute = std::stoi(end_time.substr(2, 2));
                    end = hour + minute / 60;
                }
                else
                {
                    // parse into string
                    hour = std::stoi(end_time.substr(0, 2));
                    minute = std::stoi(end_time.substr(3, 2));
                    end = hour + minute / 60;
                }
            }
        }
        temp.insert(std::pair<double,double>(begin,end));
    }
    return temp;
}

// convert double time  to string time with parameter map
std::map<std::string, std::string> convert_double_to_time(std::map<double, double> map) {
    // declare variables to parse in string elements of map and convert to double
    double begin_time;
    begin_time = 0.0;
    double end_time;
    end_time = 0.0;
    int colon;
    colon = 0;
    std::string hour;
    hour = "";
    int minute;
    minute = 0;
    std::string begin;
    begin = "";
    std::string end;
    begin = "";
    // iterator to loop through map element
    std::map<double, double>::iterator itr;
    std::map<std::string, std::string> temp;
    // for loop to iterate through map to the colon to parse into a double
    for (itr = map.begin(); itr != map.end(); ++itr)
    {
        begin_time = itr->first;
        end_time = itr->second;
        // convert double too string
        begin = std::to_string(begin_time);
        end = std::to_string(end_time);
        // take into account colon position if at 1 or 2
        for (int i = 0; i < begin.size(); i++)
        {
            if (begin.at(i) == '.')
            {
                colon = i;
                if (colon == 1)
                {
                    // parse into string
                    hour = begin.substr(0);
                    minute = std::stoi(begin.substr(2, 2));
                    if(begin.at(i+1) == '0'){
                        begin = hour + ":" + std::to_string(minute * 6 / 10) + "0";
                    }
                    else {
                        begin = hour + ":" + std::to_string(minute * 6 / 10);
                    }
                }
                else
                {
                    // parse into string
                    hour = begin.substr(0, 2);
                    minute = std::stoi(begin.substr(3, 2));
                    if(begin.at(i+1) == '0'){
                        begin = hour + ":" + std::to_string(minute * 6 / 10) + "0";
                    }
                    else {
                        begin = hour + ":" + std::to_string(minute * 6 / 10);
                    }
                }
            }
        }
        for (int i = 0; i < end.size(); i++)
        {
            if (end.at(i) == '.')
            {
                colon = i;
                if (colon == 1)
                {
                    // parse into string
                    hour = end.substr(0);
                    minute = std::stoi(end.substr(2, 2));
                    if(end.at(i+1) == '0'){
                        end = hour + ":" + std::to_string(minute * 6 / 10) + "0";
                    }
                    else {
                        end = hour + ":" + std::to_string(minute * 6 / 10);
                    }
                }
                else
                {
                    // parse into string
                    hour = end.substr(0, 2);
                    minute = std::stoi(end.substr(3, 2));
                    if(end.at(i+1) == '0'){
                        end = hour + ":" + std::to_string(minute * 6 / 10) + "0";
                    }
                    else {
                        end = hour + ":" + std::to_string(minute * 6 / 10);
                    }
                }
            }
        }
        // insert parsed string into map
        temp.insert(std::pair<std::string,std::string>(begin,end));
    }
    return temp;
}

// create a map of available meetings
std::map<std::string, std::string> available_meetings()
{
    // person 1 and person 2 schedules of daily activities when they are not available
    std::map<std::string, std::string> person1_Schedule = {{"7:00", "8:30"}, {"12:00", "13:00"}, {"16:00", "18:00"}};
    std::map<std::string, std::string> person2_Schedule = {{"9:00", "10:30"}, {"12:20", "14:30"}, {"14:00", "15:00"}, {"16:00", "17:00"}};
    // person 1 and person 2 daily availabilities
    std::map<std::string, std::string> person1_DailyAct = {{"9:00", "19:00"}};
    std::map<std::string, std::string> person2_DailyAct = {{"9:00", "18:30"}};
    // duration of desired meeting time
    double duration_of_meeting;
    duration_of_meeting = 30.0;
    // available meeting times
    std::map<std::string, std::string> meeting_timess;
    // convert all string maps to double maps
    std::map<double,double> new_person1_Schedule;
    new_person1_Schedule = convert_time_to_double(person1_Schedule);
    std::map<double,double> new_person2_Schedule;
    new_person2_Schedule = convert_time_to_double(person2_Schedule);
    std::map<double,double> new_person1_DailyAct;
    new_person1_DailyAct = convert_time_to_double(person1_DailyAct);
    std::map<double,double> new_person2_DailyAct;
    new_person2_DailyAct = convert_time_to_double(person2_DailyAct);

    // declare min and max of each persons availability
    double min1;
    min1 = 0.0;
    double max1;
    max1 = 0.0;
    double min2;
    min2 = 0.0;
    double max2;
    max2 = 0.0;

    // iterators to iterate through both person's map
    std::map<double, double>::iterator itr1;
    std::map<double, double>::iterator itr2;

    // get min and max range of available times
    for (itr1 = new_person1_DailyAct.begin(); itr1 != new_person1_DailyAct.end(); ++itr1) {
        min1 = itr1->first;
        max1 = itr1->second;
    }
    for (itr1 = new_person2_DailyAct.begin(); itr1 != new_person2_DailyAct.end(); ++itr1) {
        min2 = itr1->first;
        max2 = itr1->second;
    }
    // set min and max range of available times between both schedules
    if (min1 >= min2)
        min1 = min2;
    if (max1 >= max2)
        max1 = max2;

    // map to hold available meeting times for each person
    std::map<double,double> person1_available;
    std::map<double,double> person2_available;

    // find available meeting times for each person
    for (itr1 = new_person1_Schedule.begin(); itr1 != new_person1_Schedule.end(); ++itr1) {
        for (itr2 = new_person2_Schedule.begin(); itr2 != new_person2_Schedule.end(); ++itr2) {
            // declare variables for each time slot in map's via itr1 and itr2
            double begin1 = itr1->first;
            double end1 = itr1->second;    
            double begin2 = itr2->first;
            double end2 = itr2->second;
            // iterate next element in map
            auto next1 = std::next(itr1);
            auto next2 = std::next(itr2);
            // insert key values from next
            double start1 = next1->first;
            double start2 = next2->first;
            // if at begin element, set min time
            if ((itr1 == new_person1_Schedule.begin()) && (end1 < min1 && start1 != min1)) 
                person1_available.insert(std::pair<double,double>(min1, start1));      
            if ((itr2 == new_person2_Schedule.begin()) && (end2 < min1 && start2 != min1)) 
                person2_available.insert(std::pair<double,double>(min1, start2));         
            // add meeting times only if its not overlapping same time slot to avoid duplicate intervals
            if (end1 < start1 && begin1 >= min1) 
                person1_available.insert(std::pair<double,double>(end1, start1));   
            if (end2 < start2 && begin2 >= min1)
                person2_available.insert(std::pair<double,double>(end2, start2));    
            // if next element in map is end, set max time
            if (next1 == new_person1_Schedule.end())
                person1_available.insert(std::pair<double,double>(end1, max1));    
            if (next2 == new_person2_Schedule.end())
                person2_available.insert(std::pair<double,double>(end2, max1));    
        }
    }
    // map to hold overlapping meeting times
    std::map<double,double> overlap_meeting_times;

    // find available meeting times for each person
    for (itr1 = person1_available.begin(); itr1 != person1_available.end(); ++itr1) {
        for (itr2 = person2_available.begin(); itr2 != person2_available.end(); ++itr2) {
            // declare variables for each time slot in map's via itr1 and itr2
            double begin1 = itr1->first;
            double end1 = itr1->second;
            double begin2 = itr2->first;
            double end2 = itr2->second;
            // if available meetings overlap inset into new map
            if (begin1 < end2 && begin2 < end1) {
                double start = std::max(begin1, begin2);
                double end = std::min(end1, end2);
                // if available meeting times is at minimum duration_of_meeting insert into new array
                if ((end - start) >= (duration_of_meeting/60))
                    overlap_meeting_times.insert(std::pair<double,double>(start, end));
            }
        }
    }
    // insert available meeting times into map by conversion
    meeting_timess = convert_double_to_time(overlap_meeting_times);
    // return available meeting times
    return meeting_timess;
}
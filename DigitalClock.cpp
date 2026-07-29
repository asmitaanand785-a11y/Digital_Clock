
#include <iostream>
#include <chrono>
//include the cpp time library..fetches the current time from the system and cout to the console
#include <iomanip>
#include <windows.h>
//windows.h is a master wrapper.. windowsAPI library includes header files within it..required for window specific commands like sleep() ans system ("cls") 
//meaning programme will only run on windows because of this command 

//to run the programme on ios and linux comment out the following 


using namespace std;

//entering the clock loop

int main() {
    // while (true) { #code to be executed }  
    //is a syntax for infinity loop..itruns until the user manually close the console window
    while (true) {
        
        auto now = chrono :: system_clock::now();
        //captures exact same time from the computers internal clock .. auto tell cpp to figure out the data type on it own
       // now is the variable created which holds precise time.. it will now be used an argument being passed
       //auto is the data type.. now is the variable .. and the rest is the raw data from the system clock 
        
       time_t currentTime = chrono::system_clock::to_time_t(now);
        //time_t is the variable type.. currentTime variable stores.. now is the argument passed variable created in the last line 
        //system_clock its a clock class inside the chrono namespace.. real time global clock only cpp can translate into reable form
        //to_time_t(...) coverts high precision time to human readable form 

        tm* localTime = localtime(&currentTime);
        // translator between raw numbers to readle calender time.. currentTime is a huge number.. total seconds passed since 1970
        //tm* points to a struct tm
        //struct defined by user .. data type groups variables of diff data types under a single name
        //since tm* points to a variable.. we need the current time address to print its value
        //localtime(...) is the translator.. adjusts to system time zone and raw seconds to actual time components
        //&currentTime memory address of raw seconds

        system("cls");
        //clears out the terminal screen otherwise it prints all the time by seconds on the screen
        // cls is shortform for clearscreen.. window specific command 

        cout<< put_time(localTime, "%H:%M:%S")<<endl;
        //"%H:%M:%S" are format specifiers string.. telling how time should look

        
       Sleep(1000);
       //meaning the programme pauses for 1000 milliseconds aka 1 sec
       
    }


    return 0;

}





// for linux and mac




// #include <iostream>
// #include <chrono>
// #include <thread>
// //removed #include <windows.h>
// #include <iomanip>

// using namespace std;

// int main() {
//     while (true) {
//         auto now = chrono::system_clock::now();
//         time_t currentTime = chrono::system_clock::to_time_t(now);

//         tm* localTime = localtime(&currentTime);

//         // Clears screen on mac and linux.. clear instead of cls
//         system("clear");

//         cout << put_time(localTime, "%H:%M:%S") << endl;

//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }

//     return 0;
// }
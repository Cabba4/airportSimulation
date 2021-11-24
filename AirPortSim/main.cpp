// AirPortSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "airport.h"
#include "RANDOM.h"


using namespace std;

void initialize_main_1(int& end_time, int& queue_limit,
    double& arrival_rate, double& departure_rate)
    /*
    Pre:  The user specifies the number of time units in the simulation,
          the maximal queue sizes permitted,
          and the expected arrival and departure rates for the airport.
    Post: The program prints instructions and initializes the parameters
          end_time, queue_limit, arrival_rate, and departure_rate to
          the specified values.
    Uses: utility function user_says_yes
    */

{
    cout << "This program simulates an airport with only one runway." << endl
        << "One plane can land or depart in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
    cin >> queue_limit;

    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;

    bool acceptable;
    do {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;

        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated. " << endl;

    } while (!acceptable);
}

void initialize_main_2(int& end_time, int& queue_limit,
    double& arrival_rate, double& departure_rate)
    /*
    Pre:  The user specifies the number of time units in the simulation,
          the maximal queue sizes permitted,
          and the expected arrival and departure rates for the airport.
    Post: The program prints instructions and initializes the parameters
          end_time, queue_limit, arrival_rate, and departure_rate to
          the specified values.
    Uses: utility function user_says_yes
    */

{
    cout << "This program simulates an airport with two runway." << endl
        << "One plane can land and one can depart in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
    cin >> queue_limit;

    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;

    bool acceptable;
    do {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;

        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated. " << endl;

    } while (!acceptable);
}

void initialize_main_3(int& end_time, int& queue_limit,
    double& arrival_rate, double& departure_rate)
    /*
    Pre:  The user specifies the number of time units in the simulation,
          the maximal queue sizes permitted,
          and the expected arrival and departure rates for the airport.
    Post: The program prints instructions and initializes the parameters
          end_time, queue_limit, arrival_rate, and departure_rate to
          the specified values.
    Uses: utility function user_says_yes
    */

{
    cout << "This program simulates an airport with two runway and load balancing." << endl
        << "One plane can land and one can depart in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
    cin >> queue_limit;

    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;

    bool acceptable;
    do {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;

        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated. " << endl;

    } while (!acceptable);
}

void initialize_main_4(int& end_time, int& queue_limit,
    double& arrival_rate, double& departure_rate)
    /*
    Pre:  The user specifies the number of time units in the simulation,
          the maximal queue sizes permitted,
          and the expected arrival and departure rates for the airport.
    Post: The program prints instructions and initializes the parameters
          end_time, queue_limit, arrival_rate, and departure_rate to
          the specified values.
    Uses: utility function user_says_yes
    */

{
    cout << "This program simulates an airport with three runways." << endl
        << "One plane can land and one can depart in each unit of time and there is one extra runway which can be used on basis of queue." << endl;
    cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
    cin >> queue_limit;

    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;

    bool acceptable;
    do {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;

        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated. " << endl;

    } while (!acceptable);
}

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
    cout << time << ": Runway is idle." << endl;
}

int main_1()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize_main_1(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway small_airport(queue_limit);
    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests

        //cout << "STOOOOP " << number_arrivals << endl;
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (small_airport.can_land(current_plane) != success)
                current_plane.refuse();
        }

        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }

        Plane moving_plane;
        switch (small_airport.activity(current_time, moving_plane)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane.land(current_time);
            break;
        case takeof:
            moving_plane.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }
    }
    cout << endl << "Stats for Nerds => " << endl;
    small_airport.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    return 0;
}


int main_2()
{
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize_main_2(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway track_landing(queue_limit);
    Runway track_tackeoff(queue_limit);

    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests

        //cout << "STOOOOP " << number_arrivals << endl;
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (track_landing.can_land(current_plane) != success)
                current_plane.refuse();
        }

        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (track_tackeoff.can_depart(current_plane) != success)
                current_plane.refuse();
        }

        Plane moving_plane_1;
        Plane moving_plane_2;

        

        switch (track_landing.activity(current_time, moving_plane_1)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_1.land(current_time);
            break;
        case takeof:
            moving_plane_1.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }

        switch (track_tackeoff.activity(current_time, moving_plane_2)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_2.land(current_time);
            break;
        case takeof:
            moving_plane_2.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }
    }
    cout << endl << "Stats for Nerds => " << endl;
    cout << "Landing runway is now shutting down!" << endl;
    track_landing.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "Takeoff runway is now shutting down!" << endl;
    track_tackeoff.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

    

    return 0;
}

int main_3()
{
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize_main_3(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway track_landing(queue_limit);
    Runway track_tackeoff(queue_limit);

    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests

        //cout << "STOOOOP " << number_arrivals << endl;
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (track_landing.can_land(current_plane) != success)
            {
                if (track_tackeoff.can_land(current_plane) != success)
                    current_plane.refuse();
            }
                
        }

        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (track_tackeoff.can_depart(current_plane) != success)
            {
                if (track_landing.can_depart(current_plane) != success)
                    current_plane.refuse();
            }
                
        }

        Plane moving_plane_1;
        Plane moving_plane_2;



        switch (track_landing.activity(current_time, moving_plane_1)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_1.land(current_time);
            break;
        case takeof:
            moving_plane_1.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }

        switch (track_tackeoff.activity(current_time, moving_plane_2)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_2.land(current_time);
            break;
        case takeof:
            moving_plane_2.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }
    }
    cout << endl << "Stats for Nerds => " << endl;
    cout << "Landing runway is now shutting down!" << endl;
    track_landing.shut_down(end_time);

    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "Takeoff runway is now shutting down!" << endl;
    track_tackeoff.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;



    return 0;
}

int main_4()
{
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    int clear = 0;
    double arrival_rate, departure_rate;
    initialize_main_4(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway track_landing(queue_limit);
    Runway track_tackeoff(queue_limit);
    Runway extra(queue_limit);

    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests

        //cout << "STOOOOP " << number_arrivals << endl;
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (track_landing.can_land(current_plane) != success)
            {
                if (track_landing.landing_queue_check() != success)
                {
                    if (extra.can_land(current_plane) != success)
                        current_plane.refuse();
                }
                else
                {
                    clear = 1;
                }
            }

        }

        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (track_tackeoff.can_depart(current_plane) != success)
            {
                if (track_landing.landing_queue_check() ==  success)
                {
                    
                    if(extra.can_depart(current_plane)!=success)
                        current_plane.refuse();
                }                
            }

        }

        Plane moving_plane_1;
        Plane moving_plane_2;



        switch (track_landing.activity(current_time, moving_plane_1)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_1.land(current_time);
            break;
        case takeof:
            moving_plane_1.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }

        switch (extra.activity(current_time, moving_plane_1)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_1.land(current_time);
            break;
        case takeof:
            moving_plane_1.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }

        switch (track_tackeoff.activity(current_time, moving_plane_2)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane_2.land(current_time);
            break;
        case takeof:
            moving_plane_2.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }
    }
    cout << endl << "Stats for Nerds => " << endl;
    cout << "Landing runway is now shutting down!" << endl;
    track_landing.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "Extra runway is now shutting down!" << endl;
    extra.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "Takeoff runway is now shutting down!" << endl;
    track_tackeoff.shut_down(end_time);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;



    return 0;
}


int main()
{
    char answer;

    do
    {
        system("clear");
        //clrscr();
        cout << "Welcome to Airport Simulator, we have 4 types of simulations and each one is different" << endl;
        cout << "Here is the menu" << endl;
        int choice;

        cout << "Basic Airport sim, with one Runway....................1" << endl;
        cout << "Airport sim, with two Runways.........................2" << endl;
        cout << "Airport sim, with two Runways and Load balancing......3" << endl;
        cout << "Airport sim, with three Runways.......................4" << endl;
        cout << "No airports for me today..............................0" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            main_1();
            break;
        case 2:
            main_2();
            break;
        case 3:
            main_3();
            break;
        case 4:
            main_4();
            break;

        case 0:
            cout << "See you bye bye !" << endl;
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
        }

        cout << "Run another simulation? Y/y" << endl;
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');
    
}
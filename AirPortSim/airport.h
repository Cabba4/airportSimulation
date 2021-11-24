#pragma once
#include<iostream>
#include "utility.h"
#include "RANDOM.h"


using namespace std;

const int maxqueue = 10;

class Queue;
class Extended_queue;

class Plane {
public:
	Plane();
	Plane(int flt, int time, Plane_status status);
	void refuse() const;
	void land(int time) const;
	void fly(int time) const;
	int started() const;
	void set_fuel(double value);

private:
	int flt_num;
	double fuel;
	int clock_start;
	Plane_status state;
};


typedef Plane Queue_entry;

class Queue {
public:
	Queue();
	bool empty() const;
	Error_code append(const Queue_entry& x);
	Error_code serve();
	Error_code retrieve(Queue_entry& x) const;
	// Additional members will represent queue data.

protected:

	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};


class Extended_queue : public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry& item);
};


class Runway {
public:
	Runway(int limit);
	Error_code can_land(const Plane& current);
	Error_code can_depart(const Plane& current);
	Runway_activity activity(int time, Plane& moving);
	Error_code landing_queue_check();
	Error_code takeoff_queue_check();
	void shut_down(int time) const;

private:
	Extended_queue landing;
	Extended_queue takeoff;
	int queue_limit;
	int num_land_requests;        //  number of planes asking to land
	int num_takeoff_requests;     //  number of planes asking to take off
	int num_landings;             //  number of planes that have landed
	int num_takeoffs;             //  number of planes that have taken off
	int num_land_accepted;        //  number of planes queued to land
	int num_takeoff_accepted;     //  number of planes queued to take off
	int num_land_refused;         //  number of landing planes refused
	int num_takeoff_refused;      //  number of departing planes refused
	int land_wait;                //  total time of planes waiting to land
	int takeoff_wait;             //  total time of planes waiting to take off
	int idle_time;                //  total time runway is idle
};
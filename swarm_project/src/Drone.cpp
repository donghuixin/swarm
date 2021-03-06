#include "Drone.h"

Drone::Drone()
{
}

Drone::~Drone()
{
}

Drone::Drone(int _sysID )
{
	sysID = _sysID;
}

void Drone::heartbeat()
{
	
}
Drone::Drone(int _sysID,Geopoint _position)
{
	sysID = _sysID;
	position = _position;
}
void Drone::update_position(Geopoint &_position){
	position = _position;
}

void Drone::setAltitude(float altitude){
	this->altitude  = altitude;
	
}
float Drone::getBaroAltitude(){
	return altitude;
}

double Drone::getDistance(Drone drone){
	return position.getDistance(drone.position);
}

Geopoint Drone::getPosition() {
	return position;
}

Drone* Drone::clone(){
	Drone *clone  = new Drone();
	clone->sysID = sysID;
	clone->position.setlat(position.getlat());
	clone->position.setlon(position.getlon());
	clone->position.setalt(position.getalt());
	return clone;
}

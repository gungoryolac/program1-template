#ifndef HEADER_DG
#define HEADER_DG
#include "Star.h"
#include <cstdlib>
#include <cstdio>

Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;

}

Star::~Star(){
	free(planets);
}

int Star::addPlanet(){
	int curr_num = this->current_planets;

	Planet ** new_arr [curr_num + 1];
	for(int i = 0; i < curr_num; i++){
		new_arr[i] = this->planets[i];
	}
	
	Planet * new_planet = Planet(rand() % 3001);
	this->current_planets += 1;
	std::cout << "Planet ID: ",id << endl;

}

bool Star::removePlanet(int id){


}

Planet Star::getFurthest(){
	int index = this->current_planets;
	int maxIndex = 0;
	int furthest = 0;
	for(int j = 0; j < index; j ++){
		int distance = this->planets[j].getDistance();
		if(distance > furthest){
			furthest = distance;
			maxIndex = j;
		}
	}

	return this->planets[maxIndex];
}

void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		this->planets[i].orbit();
	}
}

void Star::printStarInfo(){
	printf("The star currently has %d planets.\n", this->current_planets);
		printf("The star can support up ot %d planets.\n", this->max_planets);
		printf("Planets:\n");
	for(int i = 0; i < this->current_planets; i++){
		printf("Planet %d is %d million miles away at position %d around the star.", i, this->planets[i].getDistance(), this->planets[i].getPos());
	}
}

int Star::getCurrentNumPlanets(){
	return this->current_planets;
}

int Star::getMaxPlanets(){
	return this->max_planets;
}


#endif

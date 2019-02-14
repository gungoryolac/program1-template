#include "Star.h"
#include <iostream>
#include <cstdlib>

Planet::Planet(int distance){
	this->id = this;
	this->distance = distance;
  	this->position = rand() % 360;
	int random = rand() % 3;
	switch(random){
		case 0:
			this->type = 'h';
		case 1:
			this->type = 'g';
		case 2:
			this->type = 'r';
	}			
}

int Planet::orbit(){
	if(this->position == 359){
		this->position = 0;
	}
	else this->position = (this->position +1);
	return this->position;
}




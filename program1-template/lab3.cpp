#include "Star.h"
#include "Star.h"
#include "Planet.h"
#include "Planet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define NUM_PLANETS_TO_TEST 500

int main(){
    srand(time(NULL));
    int all_ids[NUM_PLANETS_TO_TEST] = {0};

    cerr << "\n\tTEST #1: Test Planet Hill Creation with 0 planets" << endl;
    Star * sun = new Star();
    assert(sun->getCurrentNumPlanets() == 0);
    delete sun->planets;
    delete sun;
    sun = NULL;

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #2: Test Add 1 Planet " << endl;

    sun = new Star();
    all_ids[0] = sun->addPlanet();
    assert(sun->getCurrentNumPlanets() == 1);
    Planet * p = sun->getPlanet(all_ids[0]);
    int pos = p->getPos();
    assert(p->orbit() - 1 == pos);
    assert(p->orbit() >= 0 && p->orbit() < 360);

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #3: Add Many Planets" << endl;
    //add 499 more planets
    int prev_id = -1;
    for(int i = 1; i < NUM_PLANETS_TO_TEST; i++){
        all_ids[i] = sun->addPlanet();
        assert(sun->getCurrentNumPlanets() == i+1);
        prev_id = all_ids[rand() % i];
        assert(all_ids[i] != prev_id);
    }

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #4: Delete Planets" << endl;
    //delete the first 10 planets in the sun
    for(int i = 0; i < 10; i++){
        assert(sun->getCurrentNumPlanets() == (NUM_PLANETS_TO_TEST-i));
        assert(sun->removePlanet(all_ids[i]) == true);
        all_ids[i] = -1;
        assert(sun->getCurrentNumPlanets() == (NUM_PLANETS_TO_TEST-i-1));
    }
    //delete 10 random planets in the sun
    for(int i = 0; i < 10; i++){
        int rand_id = (rand() % (NUM_PLANETS_TO_TEST - 10)) + 10;
        int num_planets = sun->getCurrentNumPlanets();
        if(sun->removePlanet(all_ids[rand_id]) == true){
            all_ids[rand_id] = -1;
            assert(sun->getCurrentNumPlanets() == --num_planets);
        }else{
            assert(sun->getCurrentNumPlanets() == num_planets);
        }
    }
    assert(sun->removePlanet(-1) == false);
    cerr << "\n\t========================PASS========================\n" << endl;


    cerr << "\n\tTEST #5: Orbit Planets Still Works" << endl;

    //After calling orbit the planet's pos should be incremented by 1'
    for(int i = 0; i < NUM_PLANETS_TO_TEST; i++){
        Planet * temp = sun->getPlanet(all_ids[i]);
        if(temp == NULL) continue;
        int pos = temp->getPos();
        sun->orbit();
        int new_pos = temp->getPos();
        (pos == 359) ? assert(new_pos == 0) : assert(new_pos == pos + 1);
    }

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #6: Print Hill Information and Free Memory" << endl;

    sun->printStarInfo();
    delete sun;
    sun = NULL;

    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit your commit hash to MyCourses!\n" << endl;
    return 0;
}

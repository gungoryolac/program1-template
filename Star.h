#ifndef HEADER_DGH
#define HEADER_DGH


class Star{
	private:
        int current_planets;
        int next_id;
	public:
        Planet ** planets = NULL;
        Star();
		~Star();
        int addPlanet();
		bool removePlanet(int);
        Planet getFurthest();
        void orbit();
        void printStarInfo();
        inline int getCurrentNumPlanets(){ return current_planets;}
        inline int getMaxPlanets(){ return max_planets;}
};

#endif

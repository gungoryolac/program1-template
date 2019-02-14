#ifndef HEADER_DG
#define HEADER_DG

class Planet{
	private:
		long int id;
		int position;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
    	int orbit();
		inline long int getID(){ return id;}
	    inline int getDistance(){ return distance;}
	    inline int getPos(){ return position;}
		inline char getType(){return type;}
};

#endif

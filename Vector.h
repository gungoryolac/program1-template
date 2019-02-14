#ifndef HEADER_DG
#define HEADER_DG

class Vector{
	private:
		int numElements;
		int size;
	public:
		Vector();
		~Vector();
		void insert(int, Planet*);
		Planet* read(int);
		bool remove(int)
		unsigned size();
};



#endif

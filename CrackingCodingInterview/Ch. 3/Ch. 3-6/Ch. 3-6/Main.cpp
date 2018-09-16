#include "Main.h"



Main::Main()
{
}


Main::~Main()
{
}

struct Animal {
	int type; //1 for dog and 2 for cat

	Animal(int catOrDog) {
		type = catOrDog;
	}
	int getType() {
		return type;
	}
};

template <class T>
void dequeueDog(Queue<T>&);

template <class T>
void dequeueCat(Queue<T>&);

template <class T>
void dequeue(Queue<T>&);


int main() {
	Queue<Animal>* shelterQueue = new Queue<Animal>();

	

}

template<class T>
void dequeue(Queue<T>& queue, int choice) {
	

}

template <class T>
void dequeueDog(Queue<T>& queue) {
	dequeue(queue, 1);
}

template <class T>
void dequeueCat(Queue<T>& queue) {
	dequeue(queue, 2);
}


//lang::CwC
#pragma once

#include "object.h"
#include "string.h"
#include <iostream>
class Queue : public Object {
public:
	size_t back; // the tail of the queue
	size_t front; // the head of the queue
	size_t size; // maximum number of items the queue can hold
	size_t num_objects; // how many total elements there are enqueued
    Object** objects; // pointer to an array of objects our queue holds

	// Default constructor
	Queue() : Object() {}

	// Constructs Queue of the given size
	Queue(size_t size) : Object() {
		this->back = -1; // unitialized
		this->front = 0;
		this->num_objects = 0;
		this->size = size;
		this->objects = new Object*[size]; // allocate space here?
	}

	// Destructor
	virtual ~Queue() {
		// for (int n=this->front; n<num_objects;n++) {
		// 	delete this->objects[n];
		// 	n = (n + this->num_objects - 1) % this->num_objects;
		// }
		// delete[] this;
		delete [] this->objects;
	}

	// Determines if this Queue is equal to the given queue
	virtual bool equals(Object* that) {
		Queue* other_q = dynamic_cast<Queue*>(that);
		if (other_q == nullptr) { return 0; }
		if (this->num_objects != other_q->num_objects) { return 0; }
		else {
			bool equal = true;
			for (int n=this->front; n<num_objects; n++) {
				equal &= (this->objects[n]->equals(other_q->objects[n]));
				n = (n + this->size - 1) % this->size;
			}
			return equal;
		}
	}

	// Hashes the queue 
	virtual size_t hash() {		
		size_t hash = 0;
		// for (int n=this->front; n<num_objects; n++) {
		// 	std::cout << this->objects[n] << "\n";
		// 	hash += (this->objects[n]->hash());
		// 	n = (n + 1) % this->size;
		// }
		for (int i = 0; i < this->size; i++) {
			int index = (i + this->front) % size;
			std::cout << "queue: " << this << "\n";
			std::cout << "front: " << this->front << "\n";
			std::cout << "size: " << this->size << "\n";
			std::cout << "index: " <<  index << "\n";
			std::cout << "object: " <<  this->objects[index] << "\n";
		 	hash += (this->objects[index]->hash());
		}
		return hash;


	}

	// Adds the given Object to the Queue
	virtual void enqueue(Object* o) {
		if (this->isFull()) {
			exit(1); 
		}
		else {
			this->back = (this->back + 1) % this->size;
			this->objects[this->back] = o;
			this->num_objects++;
		}
	}

	// Gets and removes the next Object from the Queue
	virtual Object* dequeue() {
		if (this->isEmpty()) {
			exit(2);
		}

		else {
			Object* front_item = this->objects[this->front];
            this->front = (this->front + 1) % this->size;
            this->num_objects--;
			return (front_item);
		}
	}

	// Gets the next Object from the Queue without removing it
	virtual Object* peek() {
		if (this->num_objects == 0) {
			exit(3);
		}
		return this->objects[this->front];
	}

	// Gets the allocated size of the Queue
	virtual size_t allocated_size() {
		return this->size;
	}

	// Gets the totala number of elements in the Queue
	virtual size_t current_size() {
		return this->num_objects;
	}

	// Determines if the Queue is full
	virtual bool isFull() {
		return (this->size == this->num_objects);

	}

	// Determines if the Queue is empty
	virtual bool isEmpty() {
		return (this->num_objects == 0);
	}

	// Clears the queue of all elements
	virtual void clear() {
		for (int i = 0; i < this->current_size(); ++i) {
			this->num_objects--;
			this->objects[i] = nullptr;
		}
	}
};

class StrQueue: public Queue {
	public:	
    String** objects; // pointer to an array of strings our queue holds

    // Default constructor
	StrQueue() : Queue() {}	


	// Constructs Queue of the given size
	StrQueue(size_t size) : Queue(size) {
		this->back = -1; // unitialized
		this->front = 0;
		this->num_objects = 0;
		this->size = size;
		this->objects = new String*[size]; // allocate space here?
	}

	// Destructor
	~StrQueue() {
		// for (int n=this->front; n<size; n++) {
		// 	 delete this->objects[n];
		// 	n = (n + this->size - 1) % this->size;
		// }
		delete [] this->objects;	
	}
 
  	// Adds the given String to the Queue
	void enqueue(String* o) {
		Queue::enqueue(o);
	}
  
  	// Gets and removes the next String from the Queue
	String* dequeue() {
		Queue::dequeue();
		// dynamic_cast<String*>(Queue::dequeue());
	}
  
  	// Gets the next String from the Queue without removing it
	String* peek() {
		Queue::peek();
	}

	// Hashes the queue 
	virtual size_t hash() {
		Queue::hash();
		// size_t hash = 0;
		// //std::cout << this->peek() << "\n";
		// //std::cout << this->peek() << "\n";
		// Object* s = this->objects[this->front];
		// this->peek();
		// std::cout << "String objects:" << this->objects << "\n";
		// std::cout << s << "\n";
		// //std::cout << this->peek() << "\n";

		// for (int n=this->front; n<num_objects; n++) {
		// 	hash = 0;
		// 	String* tmp = this->objects[this->front];
		// 	// std::cout << tmp << "\n";
		// 	// hash += (this->objects[n]->hash());
		// 	n = (n + this->size - 1) % this->size;
		// }
		// return hash;
	}
};
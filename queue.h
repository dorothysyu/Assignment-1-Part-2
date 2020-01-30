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
		for (int n=this->front; n<size; n++) {
			 delete this->objects[n];
			n = (n + this->size - 1) % this->size;
		}
		delete [] this;
	}

	// Determines if this Queue is equal to the given queue
	virtual bool equals(Object* that) {

	}

	// Hashes the queue 
	virtual size_t hash() {
	}

	// Adds the given Object to the Queue
	virtual void enqueue(Object* o) {
		if (this->isFull()) {
			exit(1); 
		}
		else {
			this->back = (this->back + 1) % this->size;
			std::cout << this->back << "\n";
			this->objects[this->back] = o;
			std::cout << "added object to array of object ponters" << "\n";
			this->num_objects++;
		}
	}

	// Gets and removes the next Object from the Queue
	virtual Object* dequeue() {
		if (this->isEmpty()) {
			exit(1);
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
			exit(1);
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
			delete this->objects[i];
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
		for (int n=this->front; n<size; n++) {
			 delete this->objects[n];
			n = (n + this->size - 1) % this->size;
		}
		delete [] this;	
	}
 
  	// Adds the given String to the Queue
	void enqueue(String* o) {
		Queue::enqueue(o);
	}
  
  	// Gets and removes the next String from the Queue
	String* dequeue() {
		Queue::dequeue();
	}
  
  	// Gets the next String from the Queue without removing it
	String* peek() {
		Queue::peek();
	}

	// Hashes the queue 
	virtual size_t hash() {
		size_t hash = 0;
		for (int n=this->front; n<size; n++) {
			hash += this->objects[n]->hash();
        	n=(n+1) % this->num_objects;
    	}
	}
};
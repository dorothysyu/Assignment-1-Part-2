//lang::CwC
#pragma once
#include "object.h"
#include <string.h>
/*
 * These implementations were taken from @166 on Piazza.
 */
class String : public Object {
public:                                                                                                                                                        
  char* val_; // data                                                            
  size_t size_; // number of characters (excluding \0)  
	
	// Default constructor
	String() : Object() {
	}

	String(const char* value) : Object() {
		size_ = strlen(value);   
		char* res = new char[strlen(value) + 1];                                         
		strcpy(res, value);                                                              
		val_ = res;              
	}

	// Destructor
	virtual ~String() {
		delete[] val_; 
	}

	virtual bool equals(Object* that) {    
		if (that == nullptr) return false;                                          
		String* tgt = dynamic_cast<String*>(that);                                  
		if (tgt == nullptr) return false;                                            
		return compare(tgt)== 0;      
	}

	/** Returns 0 if strings are equal, >0 if this string is larger,               
	 *  <0 otherwise */                                                            
	int compare(String* tgt) { return strcmp(val_, tgt->val_); }
		virtual size_t hash() {
	}

	const char* get_string() {
		return this->val_;
	}

	size_t get_length() {
		return this->size_;
	}
};

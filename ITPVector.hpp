// ITP 365 Spring 2018
// HW5 Vector and Poker Hands
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac
//
// ITPVector.hpp
// Defines and implements the ITPVector collection
//
#pragma once
#include <sstream>
#include <ostream>
#include "error.h"
#include <iostream>

template <typename T>
class ITPVector
{
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
    

    
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_SIZE and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	ITPVector()
	{
        mCapacity = INITIAL_CAPACITY;
        mSize = 0;
        mData = new T[mCapacity];
        
	}

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~ITPVector()
	{
       
        delete[] mData;
            
        
        mSize = 0;
	}

	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
        return mCapacity;
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{
        return mSize;
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
		// TODO: Implement
        //T* newT;
        if (index >= mSize){
            //call error function
            error("Out of bounds index");
            //newT = new T;
            //newT = mData[0];
            //returns an empty new t
            //return newT;
        }
        else if (index < 0){
            //call error function
            error("Vector is empty");
            //newT = new T;
           // newT = mData[0];
            //return newT;
        }
        return mData[index];
        
		
	}

	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const
	{
        //T newT;
        if (index >= mSize){
            //call error function
            error("Out of bounds index");
           // newT = new T;
            //returns an empty new t
            //return newT;
        }
        else if (index < 0){
            //call error function
            error("Vector is empty");
          //  newT = new T;
            //return newT;
        }
        return mData[index];
		
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the ITPVector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void insert_back(const T& value)
	{
        //check to make sure the size is less than the capacity
        if (mSize < mCapacity){
            mData[mSize] = value;
            mSize = mSize + 1;
        }
        //if the size is equal to the capacity need to make more capacity before I add the value
        else if(mSize == mCapacity){
            //creates a temporary vector
            T* tempData;
            mCapacity = (mCapacity * 2);
            tempData = new T[mCapacity];
            for (int i = 0; i<mSize; i++){
                tempData[i] = mData[i];
            }
            //move temporary vector to main vector
            mData = tempData;
            mData[mSize] = value;
            mSize = mSize + 1;
            
        }
        
	}

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& get_back()
	{
        if (mSize != 0){
            return mData[mSize-1];
        }
        else {
            error("Vector is empty");
        }
        return mData[mSize-1];
	}

	// Function: remove_back
	// Purpose: Removes the last element from the ITPVector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void remove_back()
	{
        if (mSize != 0){
            mSize = (mSize - 1);
        }
        else {
            error("Vector is empty");
        }
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
	{
        os << "{" ;
        for (int i =0; i<vector.size(); i++){
            //checks to see if last element so it can change the format
            if (i == vector.size()-1){
                os << vector[i] << "}";
            }
            else{
                os << vector[i] << ", ";
            }
            //os << vector[i] << ", ";
        }
        

		return os;
	}
private:
    unsigned int mCapacity;
    unsigned int mSize;
    T* mData;
    
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// NOTE: Do not edit code below this line!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Disallow assignment and copy construction
	ITPVector<T>& operator=(const ITPVector<T>& other)
	{

	}

	ITPVector(const ITPVector<T>& other)
	{

	}
};

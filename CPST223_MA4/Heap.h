//*************************//
//**
//**  Simple Heap implementation
//**
//*************************//

#ifndef __HEAP_H
#define __HEAP_H

#include <vector>
#include <stdexcept>      // std::out_of_range
#include <math.h>         // pow()
#include <string>

/**
 *  Declaring Heap class
 */
template<typename T>
class Heap
{

private:
    std::vector<T> _items;    // Main vector of elements for heap storage. The first item in the array is a placeholder.

    /***********************/
    /******* Start Microassignment zone ********/

       /**
        *  Percolates the item specified at by index down
         *   into its proper location within a heap.
        *  Used for dequeue operations and array to heap conversions
        *  MA TODO: Implement percolateDown
        */
        // Recursive heapify-down algorithm.
    void percolateDown(int hole)
    {
        int leftChildIndex = hole * 2 + 1;
        int rightChildIndex = hole * 2 + 2;
        int newIndex = 0;

        //End of heap, right child not found
        if (rightChildIndex >= _items.size() && leftChildIndex >= _items.size()) {
            return;
        }
        //Left child found = Last child
        else if (rightChildIndex >= _items.size() && leftChildIndex < _items.size()) {
            newIndex = leftChildIndex;
        }

        //Not at the end of the heap: obtain the child with the minimum value
        else if (rightChildIndex < _items.size()) {
            //Left child value <= right child value
            if (_items[leftChildIndex] <= _items[rightChildIndex]) {
                newIndex = leftChildIndex; //Lesser child
            }
            //Left child value > right child value
            else {
                newIndex = rightChildIndex; //Lesser child

            }
        }
        if (_items[hole] > _items[newIndex]) {
            T temp = 0;

            temp = _items[newIndex]; //Put value of lesser child into temp
            /*Swap items*/
            _items[newIndex] = _items[hole]; //Current item bubbled down
            _items[hole] = temp; //lesser of the two children moved up

            percolateDown(newIndex); //Repeat until properties of heap satisfied
        }
    }


    /**
     *  Add a new item to the end of the heap and percolate up this item to fix heap property
     *  Used in inserting new nodes into the heap
     *  MA TODO: Implement percolateUp
     */
    void percolateUp(T item)
    {
        //calculate positions
        int current_position = _items.size();
        int parent_position = (current_position - 1) / 2;

        //insert element (note: may get erased if we hit the WHILE loop)
        _items.push_back(item);

        //get parent element if it exists
        T* parent = nullptr;
        if (parent_position >= 0)
        {
            parent = &_items[parent_position];
        }

        //only continue if we have a non-null parent
        if (parent != nullptr)
        {
            //bubble up
            while (current_position > 0 && item < *parent)
            {
                _items[current_position] = *parent; //swap
                current_position = parent_position; //position changed
                parent_position = (current_position - 1) / 2;
                if (parent_position >= 0)
                {
                    parent = &_items[parent_position]; //pointer
                }
            }

            //after finding the correct location, we can finally place our item
            _items[current_position] = item;
        }
    }

    /******** End Microassigment zone *******/

public:
    /**
     *  Default empty constructor
     */
    Heap() {
        _items.push_back(std::numeric_limits<T>::min()); // Push a placeholder for the first item in the array
    }


    /**
     *  Adds a new item to the heap
     */
    void push(T item)
    {
        percolateUp(item);
    }

    /**
     *  Removes minimum value from heap
     */
    T pop()
    {
        long unsigned int last_index = _items.size() - 1;  // Calc last item index
        int root_index = 1;                      // Root index (for readability)

        if (size() == 0) {
            throw std::out_of_range("pop() - No elements in heap");
        }

        T minItem = _items[root_index];

        _items[root_index] = _items[last_index]; // Move last item to root
        _items.pop_back();          // Erase last element entry

        if (size() > 0) {       // Only runs if the heap isn't empty now
            percolateDown(1);       // Fix heap property
        }
        return minItem;
    }


    /**
     *  Returns true if heap is empty, else false
     *  Consider the first placeholder in the array
     */
    bool empty() const
    {
        if (_items.size() == 1) {
            return true;
        }
        else {
            return false;
        }
    }


    /**
     *  Returns current quantity of elements in heap (N)
     *  Consider the first placeholder in the array
     */
    long unsigned int size() const
    {
        return _items.size() - 1;
    }


    /**
     *  Return heap data in order from the _items vector
     */
    std::string to_string() const
    {
        std::string ret = "";
        for (unsigned int i = 1; i < _items.size(); i++)
        {
            ret += std::to_string(_items[i]) + " ";
        }
        return ret;
    }
};

#endif
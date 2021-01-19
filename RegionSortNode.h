//
//  RegionSortNode.h
//  Exam
//
//  Created by kizzy on 19/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
#pragma once
#include <iostream>
#include <fstream>      // file stream
#include <string>       // getline(), stoi(), stod()
#include <sstream>
#include <functional>
#include <algorithm>
#include "Node.h"
#include "Order.h"

using namespace std;

/// @brief outputnode
template <class T>
class RegionSortNode : public Node<T> {
    
private:
    T output;
    
public:
    void setData(string data)
    {
        
    }
    
    void process(T& orders) override {
        for( Order order : orders )
        {
            
        }
    }
    
    
    list<Order> getOutput()
    {
        return this->output;
    }
};


//
//  OutputNodeHTML.h
//  Exam
//
//  Created by kizzy on 17/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
//
//  InputNode.h
//  Exam
//
//  Created by kizzy on 17/01/2021.
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
class OutputNode : public Node<T> {
    
private:
    string output;
    
public:
    void setData(string data)
    {
        this->output = data;
    }
    
    void process(T& orders) override {
        //cout << this->output;
    }
    
    
    string getOutput()
    {
        return this->output;
    }
};


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
//#include <sstream>
//#include <functional>
//#include <algorithm>
#include <list>
#include "Node.h"

using namespace std;

/// @brief read from file node
template <class T>
class InputNode : public Node<T> {
    
private:
    string data;
    
public:
    void setData(string data)
    {
        this->data = data;
    }
    
    void process( T& orders )
    {
        //string fileLocation = "/Users/kizzy/OneDrive - Dundalk Institute of Technology/Year3/Algorithms and Data Structures/exam/sales_100.txt";
        string fileLocation = this->data;
        
        ifstream inStream(fileLocation); //
        
        string data = "";
        string tempData;
        
        if( inStream.good() )
        {
            while (getline (inStream, tempData)) {
                data+= tempData + "\n";
            }
            inStream.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
        
        
        if (this->getNext() != nullptr)
            this->getNext()->setData(data);
            this->getNext()->process(orders);
        
    }
};

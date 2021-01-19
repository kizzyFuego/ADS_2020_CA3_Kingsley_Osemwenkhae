//
//  FilterNode.h
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
#include <list>
//#include <sstream>
//#include <functional>
//#include <algorithm>
#include "Node.h"

using namespace std;

/// @brief filter node
template <class T>
class FilterNode : public Node<T> {
private:
    string data;

public:
    
    void setData(string data)
    {
        this->data = data;
        cout << data << endl;
    }
    
    void process(T& orders )
    {

        stringstream dataStream( this->data ); //create string stream from the string
        
        string line = "";
        while ( getline( dataStream, line) )   // read a line until false returned , getline() from <string> library
        {
            stringstream lineStream( line );
            
            
            string name, country, region, currency, orderDate, deliveryDate;
            double price;
            int quantity;
            
            
            try
            {
                getline(lineStream, name, ',');
                
                string priceString;
                getline(lineStream, priceString, ',');
                price = stoi(priceString); // string to int (throws exceptions)
                
                string quantityString;
                getline(lineStream, quantityString, ',');
                quantity = stoi(quantityString); // string to int (throws exceptions)
                
                getline(lineStream, country, ',');
                getline(lineStream, region, ',');
                getline(lineStream, currency, ',');
                getline(lineStream, orderDate, ',');
                getline(lineStream, deliveryDate, ',');
                
                orders.push_back(Order(name, price, quantity, country, region, currency, orderDate, deliveryDate));
                //lineStream.close();
            }
            catch (std::invalid_argument const& e)
            {
                cout << "Bad input: std::invalid_argument thrown" << '\n';
            }
            catch (std::out_of_range const& e)
            {
                cout << "Integer overflow: std::out_of_range thrown" << '\n';
            }
            
            
        }
        //strStream.close();
        
       
        
        if (this->getNext() != nullptr)
            cout << "END" << endl;
            this->getNext()->process(orders);
        
        
    }
};

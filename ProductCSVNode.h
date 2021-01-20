//
//  PriceNode.h
//  Exam
//
//  Created by kizzy on 19/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
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
//#include <utility>
#include "Node.h"
#include "Order.h"
#include "CustomClasses.h"

using namespace std;

/// @brief outputnode
template <class T>
class ProductCSVNode : public Node<T> {
    
private:
    T output;
    
public:
    void setData(string data) override
    {
        
    }
    
    
    bool compare(Region region1, Region region2)
    {
        return (region1.region < region2.region);
    }
    
    
    
    void process(T& orders) override {
        
        list<ProductCSV> products;
        //int count = 0;
        
        for( Order order : orders )
        {
            products.push_back( ProductCSV(order.name, order.region, order.orderDate, order.price, order.quantity) );
        }
        
        products.sort();
        
        string csv = "Name,Region,Order Date,Price,Quantity\n";
        for( ProductCSV product : products )
        {
            csv += product.name+","+product.region+","+product.orderDate+","+to_string(product.price)+","+to_string(product.quantity)+"\n";
        }
        
        
        if (this->getNext() != nullptr)
            this->getNext()->setData(csv);
            this->getNext()->process(orders);
        
    }
    
    
    list<Order> getOutput()
    {
        return this->output;
    }
};



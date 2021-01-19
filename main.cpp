//
//  main.cpp
//  Exam
//
//  Created by kizzy on 16/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//

#include <iostream>
#include <string>

#include "File.h"
#include "InputNode.h"
#include "FilterNode.h"
#include "OutputNodeHTML.h"
#include "Order.h"
#include "RegionSortNode.h"
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string fileLocation = "/Users/kizzy/OneDrive - Dundalk Institute of Technology/Year3/Algorithms and Data Structures/exam/sales_100.txt";
    
    list<Order> orders;
    //auto inputNodeAtt = [upperPriceLimit](Bike bike) { return bike.price < upperPriceLimit; };
    InputNode<list<Order>>* inputNode = new InputNode<list<Order>>();
    
    
    FilterNode<list<Order>>* filterNode = new FilterNode<list<Order>>();
    
    //OutputNodeHTML<list<Order>>* outputNode = new OutputNodeHTML<list<Order>>();
    //OutputNodeHTML<list<Order>> outputNode = new OutputNodeHTML<list<Order>>();
    //output
    RegionSortNode<list<Order>>* regionSort = new RegionSortNode<list<Order>>();
    
    
    OutputNodeHTML<list<Order>>* outputNode = new OutputNodeHTML<list<Order>>();
    
    inputNode->setNext(filterNode)->setNext(regionSort)->setNext(outputNode);
    
    inputNode->process(orders);
    
    
    //for(Order order : outputNode->getOutput())
    //{
        //cout << order << endl;
    //}
    
    return 0;
}

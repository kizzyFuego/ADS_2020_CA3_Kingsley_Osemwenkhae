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
#include "OutputNode.h"
#include "Order.h"
#include "RegionSortNode.h"
#include "PopularProductSortNode.h"
#include "ProductCSVNode.h"
#include <list>

using namespace std;

string menu ()
{
    cout << "========================================== MENU ====================================" << endl;
    cout << "Option 1: Demonstrate Reading Data, Filter, Sort by Region and output HTML file" << endl;
    cout << "Option 2: Demonstrate Reading Data, Filter, Sort by Product Quantity and output HTML file" << endl;
    cout << "Option 3: Demonstrate Reading Data, Filter, Sort by Product Total Sales Value and output CSV file" << endl;
    cout << "Option 0: Exit" << endl;
    cout << "\nChoose An Option: ";
    string option;
    cin >> option;
    return option;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string option = menu();
    while(  option != "0")
    {
        if( option =="1" )
        {
            string fileLocation;
            cout << "Input Complete File Path? (y/n): ";
            string option;
            cin >> option;
            if( option == "y" or option == "yes" )
            {
                cout << "File Directory> ";
                cin >> fileLocation;
            }
            else
            {
                string fileLocation = "/Users/kizzy/OneDrive - Dundalk Institute of Technology/Year3/Algorithms and Data Structures/exam/sales_100.txt";
            }
            
            list<Order> orders;
            //auto inputNodeAtt = [upperPriceLimit](Bike bike) { return bike.price < upperPriceLimit; };
            InputNode<list<Order>>* inputNode = new InputNode<list<Order>>();
            FilterNode<list<Order>>* filterNode = new FilterNode<list<Order>>();
            RegionSortNode<list<Order>>* regionSort = new RegionSortNode<list<Order>>();
            //PopularProductSortNode<list<Order>>* regionSort = new PopularProductSortNode<list<Order>>();
            //ProductCSVNode<list<Order>>* regionSort = new ProductCSVNode<list<Order>>();
            
            OutputNode<list<Order>>* outputNode = new OutputNode<list<Order>>();
            
            //connecting the node
            inputNode->setNext(filterNode)->setNext(regionSort)->setNext(outputNode);
            
            inputNode->setData(fileLocation);
            //process the node
            inputNode->process(orders);
            
            // write output to html file
            ofstream outfile;
            outfile.open("/Users/kizzy/Desktop/productsByRegion.html");
            outfile <<  outputNode->getOutput() << endl;
            cout << "\n============= DONE =============\n" << endl;
        }
        
        else if( option == "2" )
        {
            string fileLocation;
            cout << "Input Complete File Path? (y/n): ";
            string option;
            cin >> option;
            if( option == "y" or option == "yes" )
            {
                cout << "File Directory> ";
                cin >> fileLocation;
            }
            else
            {
               fileLocation = "/Users/kizzy/OneDrive - Dundalk Institute of Technology/Year3/Algorithms and Data Structures/exam/sales_100.txt";
            }

            list<Order> orders;
            //auto inputNodeAtt = [upperPriceLimit](Bike bike) { return bike.price < upperPriceLimit; };
            InputNode<list<Order>>* inputNode = new InputNode<list<Order>>();
            FilterNode<list<Order>>* filterNode = new FilterNode<list<Order>>();
            //RegionSortNode<list<Order>>* sortNode = new RegionSortNode<list<Order>>();
            PopularProductSortNode<list<Order>>* sortNode = new PopularProductSortNode<list<Order>>();
            //ProductCSVNode<list<Order>>* sortNode = new ProductCSVNode<list<Order>>();

            OutputNode<list<Order>>* outputNode = new OutputNode<list<Order>>();

            //connecting the node
            inputNode->setNext(filterNode)->setNext(sortNode)->setNext(outputNode);
            
            //send date
            inputNode->setData(fileLocation);
            //process the node
            inputNode->process(orders);

            // write output to html file
            ofstream outfile;
            outfile.open("/Users/kizzy/Desktop/productByQuantity.html");
            outfile <<  outputNode->getOutput() << endl;
            cout << "\n============= DONE =============\n" << endl;
        }
        else if( option == "3" )
        {
            string fileLocation;
            cout << "Input Complete File Path? (y/n): ";
            string option;
            cin >> option;
            if( option == "y" or option == "yes" )
            {
                cout << "File Directory> ";
                cin >> fileLocation;
            }
            else
            {
               fileLocation = "/Users/kizzy/OneDrive - Dundalk Institute of Technology/Year3/Algorithms and Data Structures/exam/sales_100.txt";
            }
           
            list<Order> orders;
            //auto inputNodeAtt = [upperPriceLimit](Bike bike) { return bike.price < upperPriceLimit; };
            InputNode<list<Order>>* inputNode = new InputNode<list<Order>>();
            FilterNode<list<Order>>* filterNode = new FilterNode<list<Order>>();
            //RegionSortNode<list<Order>>* regionSort = new RegionSortNode<list<Order>>();
            //PopularProductSortNode<list<Order>>* regionSort = new PopularProductSortNode<list<Order>>();
            ProductCSVNode<list<Order>>* sortNode = new ProductCSVNode<list<Order>>();

            OutputNode<list<Order>>* outputNode = new OutputNode<list<Order>>();

            //connecting the node
            inputNode->setNext(filterNode)->setNext(sortNode)->setNext(outputNode);
            //process the node
            inputNode->setData(fileLocation);
            inputNode->process(orders);

            // write output to html file
            ofstream outfile;
            outfile.open("/Users/kizzy/Desktop/productsByTotalSale.csv");
            outfile <<  outputNode->getOutput() << endl;
            cout << "\n============= DONE =============\n" << endl;
        }
        else
        {
            cout << "Invalid Option\n" << endl;
        }
        option = menu();
    }
    
    
    
    return 0;
}

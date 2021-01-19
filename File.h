//
//  File.cpp
//  Exam
//
//  Created by kizzy on 16/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
#pragma once
#include <iostream>
#include <fstream>      // file stream
#include <string>       // getline(), stoi(), stod()
#include <sstream>
#include <list>
#include "Order.h"

using namespace std;


void parseLine(const string& str, list<Order *> & orders) {

    //list<Order> orders = orders;
    stringstream strStream( str ); //create string stream from the string
    
    
    string name, country, region, currency, orderDate, deliveryDate;
    double price;
    int quantity;
    
    
    try
    {
        getline(strStream, name, ',');
        
        string priceString;
        getline(strStream, priceString, ',');
        price = stoi(priceString); // string to int (throws exceptions)
        
        string quantityString;
        getline(strStream, quantityString, ',');
        quantity = stoi(quantityString); // string to int (throws exceptions)
        
        getline(strStream, country, ',');
        getline(strStream, region, ',');
        getline(strStream, currency, ',');
        getline(strStream, orderDate, ',');
        getline(strStream, deliveryDate, ',');
        
        orders.push_back(new Order(name, price, quantity, country, region, currency, orderDate, deliveryDate));
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


list<Order *> processFile()
{
    string line;
    list<Order *> orders;
    
    ifstream inStream("/Users/kizzy/OneDrive - Dundalk Institute of Technology/Year3/Algorithms and Data Structures/exam/sales_100.txt"); // open file as input file stream

    if ( inStream.good() )  // if file opened successfully, and not empty
    {
        while ( getline( inStream, line) )   // read a line until false returned , getline() from <string> library
        {
            parseLine( line, orders );
        }
        inStream.close();
        
        cout << "--- Bug Board Has Been Initialised (data read from file) ---" << endl;
        
    }
    else
        cout << "Unable to open file, or first time openning program." << endl;
    return orders;
    
};



/*


void openInputFileStream( vector<Bug *>& bugsPointer) {

    string line;
    ifstream inStream("bugs.txt"); // open file as input file stream

    if ( inStream.good() )  // if file opened successfully, and not empty
    {
        while ( getline( inStream, line) )   // read a line until false returned , getline() from <string> library
        {
            parseLine( line, bugsPointer );
        }
        inStream.close();
        cout << "--- Bug Board Has Been Initialised (data read from file) ---" << endl;
    }
    else
        cout << "Unable to open file, or first time openning program." << endl;
}

*/

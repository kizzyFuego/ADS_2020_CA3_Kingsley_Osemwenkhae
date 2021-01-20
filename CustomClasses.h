//
//  Region.h
//  Exam
//
//  Created by kizzy on 19/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//

#pragma once
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class Region
{
    public:
    string region;
    int salesVolume;
    double salesValue;
    double totalProductPrice;
    //list<pair<string, list<double>>> avgYearlyPrice;
    
    Region()
    {
        this->region = "";
        this->salesVolume = 0;
        this->salesValue = 0;
        this->totalProductPrice = 0;
        
    }
    
    void print()
    {
        cout << this->region << " " << this->salesVolume << " " << this->salesValue << " " << this->totalProductPrice << endl;
    }
    
    
    bool operator <(Region a) const
    {
        return region < a.region;
    }
    
    
};


class PopularProduct
{
    public:
    string name;
    string region;
    map<string, int> countryMap;
    
    PopularProduct()
    {
        this->name = "";
        this->region = "";
        
        
    }
    
    bool operator <(PopularProduct a) const
    {
       return region < a.region;
    }
    
   
    
};



class ProductCSV
{
    public:
    string name;
    string region;
    string orderDate;
    double price;
    int quantity;
    
    
    ProductCSV( string name, string region, string orderDate, double price, int quantity )
    {
        this->name = name;
        this->region = region;
        this->orderDate = orderDate;
        this->price = price;
        this->quantity = quantity;
    }
    
    bool operator <(ProductCSV a) const
    {
        return price * quantity < a.price * a.quantity;
    }
    
   
    
};

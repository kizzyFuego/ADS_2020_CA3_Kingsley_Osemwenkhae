//
//  Region.h
//  Exam
//
//  Created by kizzy on 19/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
//
//  Order.h
//  Exam
//
//  Created by kizzy on 16/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
#pragma once
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string.h>
#include <algorithm>
using namespace std;


class Region
{
    public:
    string region;
    int salesVolume;
    double salesValue;
    double totalProductPrice;
    list<pair<string, list<double>>> avgYearlyPrice;
    
    Region()
    {
        this->region = "";
        this->salesVolume = 0;
        this->salesValue = 0;
        this->totalProductPrice = 0;
        
    }
    
    void setRegion(string region)
    {
        this->region = region;
    }
    void setVolume(int volume)
    {
        this->salesValue = volume;
    }
    void setSalesValue(double value)
    {
        this->salesValue = value;
    }
    void setTotalProductPrice(double price)
    {
        this->totalProductPrice = price;
    }
    
    void print()
    {
        cout << this->region << " " << this->salesVolume << " " << this->salesValue << " " << this->totalProductPrice << endl;
    }
    
    
    bool operator <(Region a) const
    {
        //return (strncmp(region, a.region));
        // If values are the same then
        // return true
        //return a.region < b.region;
        //if (a.region < b.region) {
            //return true;
        //}
        return false;
    }
    
    
};

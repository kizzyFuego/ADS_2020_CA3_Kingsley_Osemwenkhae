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
class RegionSortNode : public Node<T> {
    
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
    
    bool cmp(const Region &a, const Region &b)
    {
        return a < b;
    }
    
    
    
    void process(T& orders) override {
        
        list<Region> regions;
        //int count = 0;
        
        for( Order order : orders )
        {
            bool regionPresent = false;
            
            for( Region &region : regions )
            {
                if( region.region == order.region )
                {
                    //count++;
                    regionPresent = true;
                    
                    region.salesVolume = region.salesVolume + 1;
                    
                    region.salesValue = region.salesValue + (order.price * order.quantity);
                    
                    region.totalProductPrice = region.totalProductPrice + order.price;
                    
                    //if( region.avgYearlyPrice )
                    //{
                    //}
                    break;
                }
            }
            
            if (!regionPresent)
            {
                Region region = Region();
                region.region = order.region;
                region.salesVolume += 1;
                region.salesValue += order.price * order.quantity;
                region.totalProductPrice += order.price;
                regions.push_back(region);
                //
            }
            //cout << "total region: " << count << endl;
        }
        
        
        //int n = sizeof(regions) / sizeof(regions[0]);
        //sort(regions, regions + n, regionComparator);
        //Region comp = Region();
        
        //sort(regions.begin(), regions.end() [](Region().region a, Region().region b){return a < b});
        //sort(regions.begin(), regions.end(), this->cmp );
        regions.sort();
        
        string html = "<html><h2>Region Sorting</h2>";
        for( Region region : regions )
        {
            double avg = region.totalProductPrice / region.salesVolume;
            //region.print();
            html += "<h4>"+region.region+"</h4>";
            html += "<p><li>Sales Volume: "+to_string(region.salesVolume) + "</li></p>";
            html += "<p><li>Sales Value: "+to_string(region.salesValue) + "</li></p>";
            html += "<p><li>Avg Product Price: "+to_string(avg) + "</li></p></html>";
        }
        
        
        if (this->getNext() != nullptr)
            this->getNext()->setData(html);
            this->getNext()->process(orders);
        
    }
    
    
    list<Order> getOutput()
    {
        return this->output;
    }
};


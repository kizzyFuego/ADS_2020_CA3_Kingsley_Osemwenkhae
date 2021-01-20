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
class PopularProductSortNode : public Node<T> {
    
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
        
        list<PopularProduct> products;
        //int count = 0;
        
        for( Order order : orders )
        {
            bool productPresent = false;
            
            for( PopularProduct &product : products )
            {
                if( product.name == order.name )
                {
                    //count++;
                    productPresent = true;
                    
                    product.countryMap[order.country] = product.countryMap[order.country] + order.quantity;
                    //if( product.countryMap[order.country] != 0 )
                    
                    //if( region.avgYearlyPrice )
                    //{
                    //}
                    break;
                }
            }
            
            if (!productPresent)
            {
                PopularProduct product = PopularProduct();
                product.name = order.name;
                product.region = order.region;
                product.countryMap[order.country] = order.quantity;
                products.push_back(product);
                //
            }
            //cout << "total region: " << count << endl;
        }
        
        
        //int n = sizeof(regions) / sizeof(regions[0]);
        //sort(regions, regions + n, regionComparator);
        //Region comp = Region();
        
        //sort(regions.begin(), regions.end() [](Region().region a, Region().region b){return a < b});
        //sort(regions.begin(), regions.end() );
        
        string html = "<html><h2>Popular Product Sorting</h2>";
        for( PopularProduct product : products )
        {
            //double avg = region.totalProductPrice / region.salesVolume;
            //region.print();
            html += "<h4>"+product.name+"</h4>";
            for (map<string,int>::iterator it=product.countryMap.begin(); it!=product.countryMap.end(); ++it)
                html += "<p><li>"+it->first+": "+to_string(it->second) + "</li></p>";
               //std::cout << it->first << " => " << it->second << '\n';
            
            html += "<html>";
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



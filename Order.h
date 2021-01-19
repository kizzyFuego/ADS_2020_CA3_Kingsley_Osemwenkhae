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
#include <string>
#include <algorithm>
using namespace std;


class Order
{
    public:
    string name;
    double price;
    int quantity;
    string country;
    string region;
    string currency;
    string orderDate;
    string deliveryDate;
    
    
    public:
    Order( string name,
    double price,
    int quantity,
    string country,
    string region,
    string currency,
    string orderDate,
    string deliveryDate )
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->country = country;
        this->region = region;
        this->currency = currency;
        this->orderDate = orderDate;
        this->deliveryDate = deliveryDate;
    }
    
    void clean()
    {
        
    }

    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Name: " << order.name;
        os << "\nPrice: " << order.price;
        os << ", Quantity: " << order.quantity;
        os << ", Country: " << order.country;
        os << ", Region: " << order.region;
        os << ", Currency: " << order.currency;
        os << ", Order Date: " << order.orderDate;
        os << ", Delivery Date: " << order.deliveryDate;
        return os;
    }
    
    /*
    pair<int, int> position;
    int direction;
    int size;
    //bugs are initialised with alive status
    bool alive = true;
    list<pair<int,int>> path;
    
    public:
    
    virtual string toString() = 0;
    virtual void move() = 0;
    
    virtual bool isWayBlocked() = 0;
    
    virtual string getHistory() = 0;
    virtual string getFormatedHistory() = 0;
     */
    
};

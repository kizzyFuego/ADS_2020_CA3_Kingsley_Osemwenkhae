//
//  Node.h
//  Exam
//
//  Created by kizzy on 16/01/2021.
//  Copyright © 2021 kizzy. All rights reserved.
//
#pragma once
enum class NodeType {
    Input,
    Filter,
    Sort,
    Transform,
    Copy,
    Output
};

/// @brief Abstract parent class for a 1-to-1 Node object
/// @tparam T C++ or User-defined type (e.g. int, string, vector<float>, list<Student*>)
template <class T>
class Node {
private:
    Node<T>* pNext = nullptr;

public:

    Node() {};
    ~Node() {};

    Node<T>* setNext(Node<T>* pNext) {
        this->pNext = pNext;
        return this->pNext;
    }

    Node<T>* getNext() {
        return this->pNext;
    }

    virtual void process(T& data) = 0;
    
    virtual void setData(string s) = 0;
    
        
    
};

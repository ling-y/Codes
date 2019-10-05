//
//  Sequence.hpp
//  proj2
//
//  Created by Lingyan Dou on 4/17/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h
#include <iostream>
#include <string>

using ItemType = std::string;

class Sequence
{
public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& other);                    
    Sequence& operator=(const Sequence& other);
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump() const;
    
private:
    int m_size;
 
    struct Node{
        ItemType data;
        Node * next;
        Node * prev;
    };
    
     Node* head;
    
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */

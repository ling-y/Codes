//
//  Sequence.cpp
//  proj2
//
//  Created by Lingyan Dou on 4/17/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//

#include "Sequence.h"

///constructor

Sequence::Sequence()
: m_size(0),  head(nullptr)
{
   
}


// destructor
Sequence::~Sequence(){
    Node *p = head;
    while(p !=nullptr){
        Node* n=p->next;
        delete p;
        p=n;
    }
}


// copy constructor
Sequence::Sequence(const Sequence& other) {
     m_size = other.m_size;
// if empty
    if (other.m_size ==0)
    {
        head = nullptr;
    }
    
    else {
    head = new Node;
    head->data = other.head->data;
    head->prev = nullptr;
    
    Node *p;
    p = head;
    Node *q = other.head->next;
//copy
   while (q != nullptr)
    {
        Node *md = new Node;
        md->data = q->data;
        p->next = md;
        md->prev = p;
        q = q->next;
        p = md;
    }
  // end pointer
        p->next = nullptr;
        
    }
    

}



//
//Assignment constructor
Sequence& Sequence::operator=(const Sequence& rhs) {
    if (this != &rhs)
    {
        Sequence temp = rhs;
        swap(temp);
        return *this;
      
    }
      return *this;
}

    
    
    
    
bool Sequence::empty() const
    {
        if (m_size == 0){
            return true;
        }
        return false;

    } // Return true if the sequence is empty, otherwise false.
    
    
int Sequence::size() const
    {
        return m_size;
        
    }    // Return the number of items in the sequence.


int Sequence::insert(int pos, const ItemType& value)
{

    if (pos < 0  ||  pos > m_size)
        return -1;
    m_size++;
// no nodes in sequence
    if (pos == 0)
    {
        Node* p = new Node;
        p->data = value;
        p->next = head;
        p->prev = nullptr;
        if (head != nullptr)
        head->prev = p;
        head = p;
    }
    else{
       Node* p = head;
    for (int i=0; i<pos-1; i++)
    {    p = p->next;
    }
    Node* newGuy = new Node;
    newGuy -> data = value;
    newGuy -> prev = p;
        if (p->next ==nullptr)
        { newGuy -> next =nullptr;}
        else
        {   newGuy -> next = p->next;
            p->next->prev = newGuy;
        }
    p -> next = newGuy;
    }
    return pos;
    }




int Sequence::insert(const ItemType& value)
{
//    if (head == nullptr)
//    {
//        m_size++;
//        head = new Node;
//        head->data = value;
//        head->next = nullptr;
//        head->prev = nullptr;
//        return 0;
//    }

    Node* p = head;
    int pos = m_size;
    for (int i=0; i<m_size; i++)
    {
        if (value <= p->data)
        {
            pos = i;
            break;
        }
        p = p->next;
    }

    insert(pos, value);

    return pos;

}





bool Sequence::erase(int pos)
{
    if (0 <= pos && pos < m_size && head != nullptr)
    {
       if (pos==0)
        {
            if (head -> next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
            Node* p = head;
            head = head -> next;
            head -> prev = nullptr;
            delete p;
            }
        }
    else{
    Node* p = head;
    Node* del = head;
    for (int i=0; i<pos-1; i++)
    {  p = p->next;}
//    for (int i=0; i<pos; i++)
//    {   del = del->next;}
        del = p->next;
    if (del->next != nullptr)
    {   p->next = del -> next;
        del -> next -> prev = p;
    }
    else
    {
        p ->next = nullptr;
    }
            delete del;
        }
        m_size--;
        return true;
    }
    return false;
    

}





int Sequence::remove(const ItemType& value)
{
    int i = 0;
    
    while( find(value) != -1)
    {
        int pos = find(value);
        erase(pos);
        i++;
    }
  
    return i;
}






bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= m_size)
        return false;
    
    Node* p;
    int i =0;
    
    for(p = head; p != nullptr && i< pos; i++){
        p= p->next;
    }

    value = p->data;
    return true;
    
}






bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= m_size)
        return false;
    Node* p = head;
    for (int i=0; i<pos; i++)
        p = p->next;
    p -> data = value;
    return true;
}






int Sequence::find(const ItemType& value) const
{
    int pos = 0;
    Node* p=head;
    for (int i = 0; i< m_size; i++)
    {
        if(p->data == value)
        {
            break;
        }
        p = p->next;
        pos ++;
    }
    if(p == nullptr )
    {return -1;}
    return pos;
    
}



void Sequence::swap(Sequence& other)
{
 
    int temp = m_size;
    m_size = other.m_size;
    other.m_size = temp;
    
    ///// exchange heads
    Node *temphead = head;
    head =other.head;
    other.head = temphead;
}


int subsequence(const Sequence& seq1, const Sequence& seq2)
{
//    if (&seq1==&seq2)
//    {
//        return 0;
//    }
    
    // check if empty
    if (!seq1.empty() && !seq2.empty())
    {
    ItemType value1, value2;
    int n = seq2.size() - 1;
    
  // first loop to find the same element
    for (int k = 0; k + n < seq1.size(); k++)
    {
          int i = 0;
        seq2.get(i, value1);
        seq1.get(i + k, value2);
        while (value1 == value2 && i != n)
        {
            // second to find if the later elements match if not return to the first loop
            i++;
         seq2.get(i, value1);
         seq1.get(i + k, value2);
        }

        if (i == n && value1 == value2)
            return k;
    }
    }
      
return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    Sequence temp;
    //same size
    if (seq1.size()==seq2.size())
    {
        for (int i=0; i<seq1.size();i++)
        {
            ItemType value1,value2;
            seq1.get(i, value1);
            seq2.get(i, value2);
            temp.insert(temp.size(), value1);
            temp.insert(temp.size(), value2);
        }
    }
    /// 1 is larger
    else if (seq1.size() > seq2.size())
    {
        int k=0;
        for (int i=0; i<seq2.size();i++)
        {
            ItemType value1,value2;
            seq1.get(i, value1);
            seq2.get(i, value2);
            temp.insert(temp.size(), value1);
            temp.insert(temp.size(), value2);
            k++;
        }
        for (;k<seq1.size();k++)
        {
            ItemType value;
            seq1.get(k, value);
            temp.insert(temp.size(), value);
        }

    }
    //// 2 is larger
    else if (seq1.size() < seq2.size())
    {
        int k = 0;
        for (int i=0; i<seq1.size();i++)
        {
            ItemType value1,value2;
            seq1.get(i, value1);
            seq2.get(i, value2);
            temp.insert(temp.size(), value1);
            temp.insert(temp.size(), value2);
            k++;
        }
        for (;k<seq2.size();k++)
        {
            ItemType value;
            seq2.get(k, value);
            temp.insert(temp.size(), value);
        }

    }

    result.swap(temp);
}

void Sequence::dump() const
{
    Node* p = head;
    while (p != nullptr)
    {
        std::cerr<<p->data<<" ";
        p=p->next;
    }
    std::cerr<<std::endl;

}

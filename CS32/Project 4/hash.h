// CPP program to implement hashing with chaining
#ifndef a_hpp
#define a_hpp


#include<iostream>
#include <list>
using namespace std;

const int SIZE=53;

struct BUCKET{
    string seq="";
    int pos;
};


class Hash
{
private:
    list<BUCKET>* table[SIZE];
    
    
    
public:
    Hash()
    {
       for(int i=0;i<SIZE;i++)
          table[i]=nullptr;
    }
    
    ~Hash(){
        for(int i=0;i<SIZE; i++)
        {
            if(table[i] != nullptr)
            {
                delete table[i];
                table[i]=nullptr;
            }
        

        }

    }
  
    
    // inserts a bucket into the hash table
    void insertItem(BUCKET b){
        
            int pos=0;
            string s = b.seq;
            if(search(s, pos))
                return;
        
            int index = hashFunc(s);
           if(table[index]==nullptr)
               table[index]=new list<BUCKET>;
        
              table[index]->push_back(b);
        
    }
    
    
    // hash function to map values to key
    int hashFunc(string seq) const
    {
      //  string seq=b.seq;
        int i, total=0;
        for (i=0;i<seq.length(); i++)
            total = total + (i+1) * seq[i];
        total = (total*100) % SIZE;
        return(total);
    }
    
    // search if a sequence is already in the table and if it is, get the offset(pos), then return true
    bool search(string seq,int& pos)
    {
        
        int key = hashFunc(seq);
        
         if (table[key] == nullptr)
                return false;
       
       
        for (list<BUCKET>::iterator i=table[key]->begin(); i!=table[key]->end();i++)
                {
                    if (i->seq==seq)
                    {
                        pos=i->pos;
                        return true;
                    }
                }
            
                return false;


    }
  
  //  void displayHash();
};









#endif /* a_hpp */


//  main.cpp
//  pj4
//
//  Created by Lingyan Dou on 5/30/19.
//  Copyright © 2019 Lingyan Dou. All rights reserved.
//
#include "hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>
using namespace std;

#include <utility>
#include <functional>
#include <string>
#include <vector>



 int N=8;

// two helper function
bool getInt(istream& inf, int& n)
{
    char ch;
    if (!inf.get(ch)  ||  !isascii(ch)  ||  !isdigit(ch))
        return false;
    //  cout<<ch;
    inf.unget();
    inf >> n;
    return true;
}

bool getCommand(istream& inf, char& cmd, int& length, int& offset)
{
    if (!inf.get(cmd))
    {
        cmd = 'x';  // signals end of file
        return true;
    }
    char ch;
    switch (cmd)
    {
        case 'A':
            return getInt(inf, length) && inf.get(ch) && ch == ':';
        case 'C':
            return getInt(inf, length) && inf.get(ch) && ch == ',' && getInt(inf, offset);
        case '\r':
        case '\n':
            return true;
    }
    return false;
}






// apply diff file to create new file
bool applyDiff(istream& fold, istream& fdiff, ostream& fnew){
    
    string output="";
    char cmd=' ';
    int offset;
    int length;
    
    // while the diff file has more characters, get them, and apply command according to them
    do{
        if(getCommand(fdiff, cmd, length,offset))
        {
            // deal with command A
            if (cmd == 'A')
            {
                for (int i=0;i<length;i++)
                {
                    char k;
                    if(fdiff.get(k))
                    {
                          output += k;
                      //  cout<<output<<'\n';
                    }
                    else
                        return false;
                }
            }
            // deal with command C
            if (cmd=='C')
            {
                // use get funciton to find the corrent position in the old file
                for(int i=0;i<offset;i++)
                {
                    char k;
                    if (!fold.get(k))
                    {
                        return false;
                    }
                }
                
                // continue getting the following characters according to the length
                for (int i=0;i<length;i++)
                {
                    char k;
                    if(fold.get(k))
                    {
                        output += k;
                        // cout<<i<<"-"<<output<<'\n';
                    }
                    else{
                        
                        return false;
                        
                    }
                }
                // clear the old file condition
                fold.clear();
                fold.seekg(0);
                
            }
            
        }
        
        else{
            
            return false;}
        
        
    }while (cmd != 'x');
    
    
    fnew<<output;
    return true;
    
    
}


// helper function which transfers a file into a string, and return that string
string ToString(istream& file){
    char c;
    string s="";
    
    
    while (file.get(c))
    {
        s+=c;
    }
    
    return s;
}



// helper function that seperates the first N characters from the input string and return true.
// If the input string has less than N characters, do nothing and return false
bool chop(string& s,string& n){
    if((s.size())<=N){
    
        return false;
    }
    n=s.substr(0,N);
   s=s.substr(N,s.size()-N);
    return true;
}



// helper funciton that takes in a string and inserts all the sequences into the hash table
void CreatHT(string& s, Hash& ht){
    string seq;
    int i=0;
    // use chop() to create sequences, use them to create BUCKET object and keep insert the BUCKETS when chop() returns true
   while(chop(s, seq))
   {
       BUCKET b = {seq,i};
       ht.insertItem(b);
       i+=N;
   }
  //   when chop() returns false (there are less than N characters in the string)
    // insert the last sequence (might be N characters or less)
     BUCKET b ={s,i};
     ht.insertItem(b);
    
  //  ht.display();
    return;

}


// helper function that organizes all the A commands in the newly created diff string
// transfer "A1:BA1:LA1:AA1:H" to "A4:BLAH"
void organizeA(string s,string& ns){
    for(int i=0;i<s.size();i++)
    {
         string k="";
        char c=s[i];
        if(c=='A'){
           char add;
            if( s[i+1] == '1' && s[i+2] == ':' )
            {
               add=s[i+3];
                k+=add;
            }
            while((s.size()-i+1)>8 && s[i+1] == '1' && s[i+2] == ':'  && s[i+4] == 'A'&& s[i+5] == '1' && s[i+6] == ':' )
                {
                    add=s[i+7];
                    k += add;
                    i=i+4;
                }
                string size=to_string(k.size());
                ns+='A'+size+':'+k;
                i+=3;
            
        }
        else{
                ns+=c;
        }
    }
}


// create command helper function
// use of multiple different Ns to test and to find a better diff (the one creates the shortest diff string)
void createCommand(istream& fold, istream& fnew, vector<string>& vstring)
{
    // set the initial N to 8 and transfer two files to string

   
    N=8;
    string oldstr=ToString(fold);
    string newstr=ToString(fnew);

    // while loop to test 
    while(N!=64)
    {
     // create a new hash table and use createHT to insert the old string as sequence
         Hash ht;
        string copy=oldstr;
        string diff="";
        CreatHT(copy,ht);
    
     //  ht.display();
        // loop through the new file string
        for (int i=0;i<newstr.size();i++)
        {
            //   cerr<<i<<" "<<newstr[i]<<endl;
            string nseq=newstr.substr(i,N);
    //        cout<<nseq<<endl;
            int pos=-1;
            // search the first sequence of N in the new string in the hash table
             // if returns true then use COPY COMMAND
            if (ht.search(nseq, pos))
            {
               
              ///  cout<<"sdfjldsjf"<<endl;
                unsigned long size=nseq.size();
                int sizebefore=0;
                //  cerr<<" {{{ "<<newstr[i+N]<<"  "<<oldstr[pos+N]<<" }}} ";
                int extension=pos;
                int deduction=pos;
                int i2=i;
                // Determine how long the match goes on
                    // goes before the match
                if (pos>0)
                {
                    while(deduction>0 && i2>0&&newstr[i2-1] == oldstr[deduction-1] )
                    {
                        sizebefore++;
                        i2--;
                        deduction--;
                    }
                }
                
                    // goes after the match
                while(newstr[i+N] == oldstr[extension+N])
                {
                    if (newstr[i+N]=='\0')
                        break;
                    //      cout<<newstr[i+N]<<"-count after!"<<endl;
                    size++;
                    i++;
                    extension++;
                }
                
                
                // find if it is worth is to use command Copy for those same characters that are found before the match of N
                if(sizebefore>0){
                    // if before this command Copy is command Add
                    // delete the Add command and increment Copy command's size by one, also Copy command's index-1
                    while (diff.size()>=4 && diff[diff.size()-2]==':' && diff[diff.size()-3]=='1' && diff[diff.size()-4]=='A'&& sizebefore>0){
                        diff=diff.substr(0,diff.size()-4);
                        sizebefore--;
                        size+=1;
                        pos--;
                        
                    }
                    //  cout<<"sizetotal:"<<size<<endl;
                    diff+="C"+to_string(size)+","+to_string(pos);
                }
                else
                    diff+="C"+to_string(size)+","+to_string(pos);
                
                // increment i to the correct position after the match happened
                i+=N-1;
                
            }
            
            // ADD COMMAND
            else
            {
                diff+="A1:";
                char add=newstr[i];
                diff+=add;
            }
        }
     
        // organize the command and push the result command into a vector
        string command="";
        organizeA(diff,command);
                //    cout<<command<<endl;
        vstring.push_back(command);
        
     //   ht.displayHash();
      //  cout<<command<<endl;
        
        // increment N to try building different commands
        if(N<24)
            N=N+1;
        else if (N>24&&N<40)
            N=N+2;
        else
            N=N+4;


    }
}

// helper function to find the shortest string in a vector of strings
string findshortest(vector<string> v){
    string shortest="";
    vector<string>::iterator i=v.begin();
    shortest=*i;
    string compare="";
    
    while(i!=v.end()-1)
    {
        i++;
        compare=*i;
        //cout<<compare<<endl;
        if(shortest.size()>compare.size())
            shortest=compare;
    }
    return shortest;
}


// create diff file
void createDiff(istream& fold, istream& fnew, ostream& fdiff)
    {
        // use createCommand to get a vector of possible results (command strings)
        vector<string> vstring;
        createCommand(fold, fnew, vstring);
        // find the shortest command
        string shortest=findshortest(vstring);
        // put that shortest command into the file
        fdiff<<shortest;

}



////
//////
////int main(){
////    string test="";
////    string fml;
////    ifstream infile("/Users/lingyandou/Desktop/p4test/greeneggs1.txt");
////    ifstream infile2("/Users/lingyandou/Desktop/p4test/greeneggs2.txt");
////    ofstream file1("/Users/lingyandou/Desktop/p4test/greeneggstest.txt");
////    ofstream file2("/Users/lingyandou/Desktop/p4'test/greeneggs_new.txt");
////    createDiff(infile, infile2, file1);
////
////
////
////
////
//// //  cout<<test;
////}
//

bool runtest(string oldName, string newName, string diffName, string newName2)
{
    if (diffName == oldName  ||  diffName == newName  ||
        newName2 == oldName  ||  newName2 == diffName  ||
        newName2 == newName)
    {
        cerr << "Files used for output must have names distinct from other files" << endl;
        return false;
    }
    ifstream oldFile(oldName, ios::binary);
    if (!oldFile)
    {
        cerr << "Cannot open " << oldName << endl;
        return false;
    }
    ifstream newFile(newName, ios::binary);
    if (!newFile)
    {
        cerr << "Cannot open " << newName << endl;
        return false;
    }
    ofstream diffFile(diffName, ios::binary);
    if (!diffFile)
    {
        cerr << "Cannot create " << diffName << endl;
        return false;
    }
    createDiff(oldFile, newFile, diffFile);
    diffFile.close();

    oldFile.clear();   // clear the end of file condition
    oldFile.seekg(0);  // reset back to beginning of the file
    ifstream diffFile2(diffName, ios::binary);
    if (!diffFile2)
    {
        cerr << "Cannot read the " << diffName << " that was just created!" << endl;
        return false;
    }
    ofstream newFile2(newName2, ios::binary);
    if (!newFile2)
    {
        cerr << "Cannot create " << newName2 << endl;
        return false;
    }
    assert(applyDiff(oldFile, diffFile2, newFile2));
    newFile2.close();

    newFile.clear();
    newFile.seekg(0);
    ifstream newFile3(newName2, ios::binary);
    if (!newFile)
    {
        cerr << "Cannot open " << newName2 << endl;
        return false;
    }
    if ( ! equal(istreambuf_iterator<char>(newFile), istreambuf_iterator<char>(),
                 istreambuf_iterator<char>(newFile3), istreambuf_iterator<char>()))
        {

            cerr << newName2 << " is not identical to " << newName
            << "; test FAILED" << endl;
            return false;
        }
        return true;
        }

        int main()
        {

            assert(runtest("/Users/lingyandou/Desktop/p4test/warandpeace1.txt", "/Users/lingyandou/Desktop/p4test/warandpeace2.txt", "/Users/lingyandou/Desktop/p4test/warandpeacetest.txt","/Users/lingyandou/Desktop/p4test/warandpeace_new.txt"));
            cerr << "Test PASSED" << endl;
        }



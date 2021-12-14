#include "data.h"
#include "main.h"
/*
void data::take_data(string s,int n)
{   regex a("([0-9]+\\.+[0-9]+)"); // float
    regex b("\\d+$"); // int
    // regex c("\\d+A$"); // address
    // if (regex_match(s,c)) // Address
    // { this->type = ADDRESS;
    //   s.pop_back();
    //   if(s.front() == '0' && s.size()!= 1)throw InvalidOperand(n);
    //   this->x = stoi(s);}
    if (regex_match(s,a)){ // Float
     this->type = FLOAT;
     if(s[0] == '0' && s[1] != '.' && s.size()!= 1)throw InvalidOperand(n);
     this->y = stof(s);
    }
    else if(regex_match(s,b)){ // Int
        if(s.front() == '0' && s.size()!= 1)throw InvalidOperand(n);
        this->x = stoi(s);
        this->type = INT;
    }
    
}*/
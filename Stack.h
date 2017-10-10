#ifndef STACK_H
#define STACK_H

#include "vector.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using std::string;
using std::cout;
using pep::vector;
using std::istream_iterator;

class Stack{

public:

    vector<double> stack;




    bool empty(){
        return stack.empty();


    }


    double pop(){
        double elementToReturn = stack[0];
        stack.erase(stack.begin() + 0);
        return elementToReturn;


    }


    void push(double toPush){

        stack.insert(stack.begin(), double (toPush));

    }

    double getFirstElement(){
        double elementToReturn = stack[0];
        return  elementToReturn;
    }

};

    double evaluate(string s){

        Stack stack;



        std::istringstream iss(s);
        vector<string> tokens{istream_iterator<string>{iss},
                              istream_iterator<string>{}};

        for(int i = 0; i < tokens.size(); i++) {

            if (tokens[i] == "+"){
                double first = stack.pop();
                double second = stack.pop();
                double toPush = (second + first);
                stack.push(toPush);

            }
            else if (tokens[i] == "-"){
                double first = stack.pop();
                double second = stack.pop();
                double toPush = (second - first);
                stack.push(toPush);
            }
            else if (tokens[i] == "*"){
                double first = stack.pop();
                double second = stack.pop();
                double toPush = (second * first);
                stack.push(toPush);
            }
            else if (tokens[i] == "/"){
                double first = stack.pop();
                double second = stack.pop();
                double toPush = (second / first);
                stack.push(toPush);
            }

            else{
                double toPush = std::stod(tokens[i]);
                stack.push(toPush);
            }

        }


        return stack.getFirstElement();
    }


// Do not write anything below this line

#endif

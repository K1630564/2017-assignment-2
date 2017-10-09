
#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
#include "vector.h"
#include <iostream>
#include <iterator>
#include <algorithm>
using std::vector;
using std::cout;
using std::min_element;
using std::max_element;
using std::distance;




    int maximumGates(vector<int> arrives, vector<int> departs) {

        int gatesInUse = 0;
        int maxGates = 0;
        int departSmallestIndex = distance(departs.begin(), min_element(departs.begin(), departs.end()));
        int departSmallestValue = departs[departSmallestIndex];

        for (int i = 0; i < arrives.size(); i++) {

            if(arrives[i] < departSmallestValue){
                gatesInUse++;
            }

            if(arrives[i] > departSmallestValue){
                gatesInUse --;


            }

            if(gatesInUse >= maxGates){

                maxGates = gatesInUse;
            }



        }


        return maxGates;
    }




// Do not write any code below this line


#endif

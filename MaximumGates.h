
#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include "vector.h"
#include <iostream>
#include <iterator>
#include <algorithm>
using std::vector;
using std::sort;

    int maximumGates(vector<int> arrives, vector<int> departs) {

        int gatesInUse = 0;
        int maxGates = 0;

        sort (departs.begin(), departs.begin() + departs.size());

        for (int i = 0; i < arrives.size(); i++){


                if(arrives[i] < departs[0]){
                    gatesInUse++;
                }
                else if (arrives[i] > departs[0]){
                    gatesInUse--;
                    departs.erase(departs.begin() + 0);
                    i--;
                }


            if(gatesInUse >= maxGates){

                maxGates = gatesInUse;
            }

        }

        return maxGates;
    }

// Do not write any code below this line


#endif

#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"
#include "vector.h"
#include <iostream>
using pep::vector;
using std::cout;
using std::endl;

class MapOfItems{
private:

    vector<Item> visitedItems;
public:


    void addItem(Item item){
        visitedItems.insert(visitedItems.end(), item);


    }

    int size(){
       int size = visitedItems.size();
        return size;
    }

    vector<Item> getTour(float speed){

        vector<Item> copyVisitedItems = visitedItems;

        vector<Item> toReturn;

        int fifteenMinInSec = (15*60);

        int currentTourTime = 0;

        Item nextToVisit = visitedItems[0];

        Item startItem = visitedItems[0];

        int smallestVisitTime = 50000;

        int index = 0;

        int tlcount = 0;

        int loopcount = 0;







        visitedItems.erase(visitedItems.begin());
        addItem(startItem);
        toReturn.insert(toReturn.end(), startItem);
        currentTourTime = startItem.getTime();


        for(int z = visitedItems.size(); z > 1; z--) {
            smallestVisitTime = 50000;
            tlcount = 0;
            loopcount = 0;
            // locate next visit
            for (int i = z-2; i >= 0; i--) {

                loopcount ++;


                Item currentItem = visitedItems[visitedItems.size()-1];
                Item itemToCheck = visitedItems[i];


                int visit = (currentItem.distanceTo(itemToCheck) / speed) + currentTourTime;


                if (visit > (itemToCheck.getTime() + fifteenMinInSec)) { // if visit(I) is too late we cant visit that item

                    tlcount++;

                }

                else if (visit < itemToCheck.getTime()) { // if visit(I) is too early we have to wait

                    visit = itemToCheck.getTime();


                } else{
                    visit = visit;
                }


                if (smallestVisitTime > visit ) { //update next visit (the smallest)
                    smallestVisitTime = visit;
                    index = i;
                    nextToVisit = itemToCheck;


                }



            }

            currentTourTime = smallestVisitTime;

            if(loopcount == tlcount+1 && tlcount!= 0){
               break;
           }



            else if (currentTourTime >= (3600)) {
                break;
            }

            else {

                visitedItems.erase(visitedItems.begin() + index);
                addItem(nextToVisit); // add next item to visit in tour
                toReturn.insert(toReturn.end(), nextToVisit);

            }
        }



        visitedItems = copyVisitedItems;


        return toReturn;



    }
};




// don't write any code below this line

#endif


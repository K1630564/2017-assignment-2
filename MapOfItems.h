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

        int count = 0;

        int index = 0;








        visitedItems.erase(visitedItems.begin());
        addItem(startItem);
        toReturn.insert(toReturn.end(), startItem);
        currentTourTime = startItem.getTime();


        for(int z = visitedItems.size(); z > 1; z--) {


            count = 0;

            // locate next visit
            for (int i = z-2; i >= 0; i--) {


                Item currentItem = visitedItems[visitedItems.size()-1];
                Item itemToCheck = visitedItems[i];


                int visit = (currentItem.distanceTo(itemToCheck) / speed) + currentTourTime;


                if (visit > itemToCheck.getTime() + fifteenMinInSec) { // if visit(I) is too late we cant visit that item
                    visit = 100000;

                }

                if (visit < itemToCheck.getTime()) { // if visit(I) is too early we have to wait

                    visit = itemToCheck.getTime();

                }


                if (smallestVisitTime > visit ) { //update next visit (the smallest)
                    count++;
                    smallestVisitTime = visit;
                    index = i;
                    nextToVisit = itemToCheck;


                }



            }

            if(count == 0){
               cout << "Too late for all remaining items. Tour has ended." << endl;
               break;
           }

            currentTourTime = smallestVisitTime;

            if (currentTourTime >= (3600)) {
                cout << "Out of time" << endl;
                break;
            }



            visitedItems.erase(visitedItems.begin() + index);
            addItem(nextToVisit); // add next item to visit in tour
            toReturn.insert(toReturn.end(), nextToVisit);

            smallestVisitTime = 50000;


        }



        visitedItems = copyVisitedItems;


        return toReturn;



    }
};




// don't write any code below this line

#endif


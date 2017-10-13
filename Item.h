#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::ostream;

class Item{

private:
    double latitude;
    double longitude;
    string id;
    int time;

public:
    Item(double latitude, double longitude, string id, int time)
            : latitude(latitude), longitude(longitude), id(id), time(time){


    }
    friend ostream& operator<<(ostream& os, const Item it)
    {
        os << "{" << it.latitude <<", " << it.longitude << ", " << "\""<< it.id << "\", " << it.time << "}" ;
        return os;
    }

    int getTime(){
        return time;
    }

    double distanceTo (Item item){


        Item OrgIt = Item(latitude, longitude, id, time);

        double radLatItem = item.latitude * (3.14159265359 /180);
        double radLongItem = item.longitude * (3.14159265359 /180);
        double radLatOrgIt = OrgIt.latitude * (3.14159265359 /180);
        double radLongOrgIt = OrgIt.longitude * (3.14159265359 /180);


        int r = 6373000;

        double dlon = radLongItem - radLongOrgIt;
        double dlat = radLatItem - radLatOrgIt;

        double a = pow((sin(dlat/2)), 2) + cos(radLatOrgIt) * cos(radLatItem) * pow((sin(dlon/2)), 2);

        double c = 2 * atan2( sqrt(a), sqrt(1-a));

        double distance = r * c;

        return  distance;





    }
};



// don't write any code below this line

#endif


#include <iostream>
#include <list>
using namespace std;
#include "Configuration.h"
#include "Placement.h"
#include "Filler.h"

int main( )
{
   Configuration C("input.txt");
   C.forbid(4,2);
   list<Placement> canDo = C.getPossiblePlacements(3);
   for( Placement P : canDo ) cout << P << endl;
   C.placeTileAt( 2, 3 , true, 3 );
   Square::setChars('-','+');
   C.dumpToScreen( );
   cout << endl;
//   Square::setChars('~', '#');
   Filler F("input.txt");
   F.greedyFill(3);
   F.dumpToScreen( );
}

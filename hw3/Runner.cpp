// Jacob Kaufmann
// Runner.cpp

#include "Configuration.h"

int main() {
    cout << "Enter number of rows and cols for board: ";
    int r, c;
    cin >> r >> c;

    Configuration C(r, c);

    cout << "Enter forbidden square: ";
    int fr, fc;
    cin >> fr >> fc;
    C.forbid(fr, fc);

    int count = 0;
    while(count < 3)
    {
	int row, col, len;
	bool horiz;
	cout << "Enter tile info: ";
	cin >> row >> col;
	cin >> boolalpha >> horiz;
	cin >> len;
	C.placeTileAt(row, col, horiz, len);
	count++;
    }
    C.dumpToScreen();
    return 0;
}

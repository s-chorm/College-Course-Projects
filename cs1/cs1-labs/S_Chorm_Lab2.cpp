/*
Samantha Chorm CSE 110 - Lab 2
Due Date: 2/15/26
Instructor: Dr. Anne C. Pinder
Description: This program computes gross receipts using floor and balcony tickets sold
Requirements:

1. Write the pseudocode for the program as comment lines below main.
2. Develop a program to determine the number of floor tickets sold and the number of balcony tickets sold, the gross receipts for each section, the total gross receipts, and the profit based on the total gross receipts.
3. The user will enter the total number of tickets sold, and the program will compute all of the values.
4. If no balcony tickets have been sold (tickets sold is less than or equal to 200), the output for the balcony tickets sold and balcony ticket receipts must be assigned zero. Do not rely on the compiler to do this.

Test-suit: This is to check multiple parts of the program. Example: Normal: if the user types a number that works as a radius(not less then or equal to zero)should calculate everything.Rating:SuccessExample: Boundary: Should loop if the radius is less than or equal to zero.Rating:SuccesExample:  Extreme: types in a big number like 1000 and works.Rating:Success
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int ticketsSold;
    int floorTicketsSold;
    int balconyTicketsSold;
    double floorReceipts;
    double balconyReceipts;
    double grossReceipts;
    double eventProfit;

    cout << "Enter the number of tickets sold: ";
    cin >> ticketsSold;

    if (ticketsSold > 200) {
        floorTicketsSold = 200;
        balconyTicketsSold = ticketsSold - 200;
    } else {
        floorTicketsSold = ticketsSold;
        balconyTicketsSold = 0;
    }

    floorReceipts = floorTicketsSold * 29.0;
    balconyReceipts = balconyTicketsSold * 19.0;
    grossReceipts = floorReceipts + balconyReceipts;
    eventProfit = grossReceipts - 1450;

    cout << fixed << setprecision(2);

    cout << endl << "Floor tickets sold = " << floorTicketsSold << endl;
    cout << "Floor ticket receipts = $" << floorReceipts << endl << endl;
    cout << "Balcony tickets sold = " << balconyTicketsSold << endl;
    cout << "Balcony ticket receipts = $" << balconyReceipts << endl << endl;
    cout << "Gross receipts = $" << grossReceipts << endl;
    cout << "Profit = $" << eventProfit << endl;

    cin.ignore();
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

/*
PSEUDOCODE:

1. Declare variables:
   - ticketsSold (total tickets entered by user)
   - floorTicketsSold, balconyTicketsSold
   - floorReceipts, balconyReceipts, grossReceipts, eventProfit

2. Prompt user to enter total number of tickets sold

3. Input ticketsSold from user

4. Determine floor and balcony tickets:
   IF ticketsSold > 200 THEN
      floorTicketsSold = 200
      balconyTicketsSold = ticketsSold - 200 (Finds exact number of balcony tickets after all floor tickets are sold)
   ELSE
      floorTicketsSold = ticketsSold
      balconyTicketsSold = 0 (No balcony tickets sold)

5. Calculate receipts:
   floorReceipts = floorTicketsSold * 29.00
   balconyReceipts = balconyTicketsSold * 19.00
   grossReceipts = floorReceipts + balconyReceipts

6. Calculate profit:
   eventProfit = grossReceipts - 1450.00

7. Set output formatting (fixed, 2 decimal places)

8. Display results:
   - Floor tickets sold
   - Floor ticket receipts
   - Balcony tickets sold
   - Balcony ticket receipts
   - Total gross receipts
   - Profit
*/

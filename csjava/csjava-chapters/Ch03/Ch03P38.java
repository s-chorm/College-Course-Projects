// NAME: Samantha Chorm 	LAB: Ch03P38

/*
   PSEUDOCODE:
   
   START
      Declare Constants:
         MAIN_FLOOR_MAX = 200
         MAIN_FLOOR_PRICE = 29.50
         BALCONY_PRICE = 19.50
         MATINEE_COST = 1200.00
         EVENING_COST = 1450.00
         
      Declare Variables:
         Integer ticketsSold
         Integer mainTickets
         Integer balconyTickets
         String timeCode
         Double mainSales
         Double balconySales
         Double totalSales
         Double eventCost
         Double profit

      Display "Enter the tickets sold "
      Input ticketsSold
      
      Display "Enter \"M\" for Matinee, \"E\" for Evening "
      Input timeCode

      If ticketsSold <= MAIN_FLOOR_MAX Then
         mainTickets = ticketsSold
         balconyTickets = 0
      Else
         mainTickets = MAIN_FLOOR_MAX
         balconyTickets = ticketsSold - MAIN_FLOOR_MAX
      EndIf

      mainSales = mainTickets * MAIN_FLOOR_PRICE
      balconySales = balconyTickets * BALCONY_PRICE
      totalSales = mainSales + balconySales

      If timeCode equals "M" or "m" Then
         eventCost = MATINEE_COST
      Else
         eventCost = EVENING_COST
      EndIf

      profit = totalSales - eventCost

      Display "Main Floor ticket sales: $" + mainSales
      Display "Balcony ticket sales: $" + balconySales
      Display "Total sales: $" + totalSales
      Display "Event cost: $" + eventCost
      Display "Profit from the event: $" + profit
   END
*/

package packageCh03P38;

import java.util.Scanner;

public class Ch03P38 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		// Constants
		
		final int MAIN_FLOOR_MAX = 200; // Lets program know when to start selling balcony tickets
		final double MAIN_FLOOR_PRICE = 29.50;
		final double BALCONY_PRICE = 19.50;
		final double MATINEE_COST = 1200.00;
        final double EVENING_COST = 1450.00;
		
		// Variables
		
		int ticketsSold;
		int mainTickets;
		int balconyTickets;
		String timeCode;
		double mainSales;
		double balconySales;
		double totalSales;
		double eventCost;
		double profit;
		
		// Gets user input
		
		System.out.print("Enter the tickets sold ");
		ticketsSold = in.nextInt();
		System.out.print("Enter \"M\" for Matinee, \"E\" for Evening ");
		timeCode = in.next();
		
		System.out.println(); // Blank line separating sections
		
		// Calculates all sales, the event cost, and profit
		
		if (ticketsSold <= MAIN_FLOOR_MAX) {
			mainTickets = ticketsSold;
			balconyTickets = 0;
		}
		else {
			mainTickets = MAIN_FLOOR_MAX;
			balconyTickets = ticketsSold - MAIN_FLOOR_MAX;
		}
		
		mainSales = mainTickets * MAIN_FLOOR_PRICE;
		balconySales = balconyTickets * BALCONY_PRICE;
		totalSales = mainSales + balconySales;
		
		if (timeCode.equalsIgnoreCase("M")) {
			eventCost = MATINEE_COST;
		}
		else {
			eventCost = EVENING_COST;
		}
		
		profit = totalSales - eventCost;
		
		// Output
		
		System.out.printf("Main Floor ticket sales: $%.2f%n", mainSales);
        System.out.printf("Balcony ticket sales: $%.2f%n", balconySales);
        System.out.printf("Total sales: $%.2f%n", totalSales);
        System.out.printf("Event cost: $%.2f%n", eventCost);
        System.out.printf("Profit from the event: $%.2f%n", profit);
		
		if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

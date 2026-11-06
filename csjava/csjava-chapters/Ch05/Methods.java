// NAME: Samantha Chorm 	LAB: Ch05P32

package packageCh05P32;

import java.util.Scanner;

public class Methods {
	
	// METHOD 1 obtains and returns the price of a purchased item (double)
	
	public static double methodOne(Scanner in) {
		
		double userItemPrice;
		
		System.out.print("Enter the price of the item ");
		userItemPrice = in.nextDouble();
		
		return userItemPrice;
	}
		
		// METHOD 2 obtains and returns the quantity of a purchased item (integer)
	
	public static int methodTwo(Scanner in) {
		
		int userItemQuantity;
		
		System.out.print("Enter the number of items ");
		userItemQuantity = in.nextInt();
		
		return userItemQuantity;
	}
		
		// METHOD 3 computes and returns total price for all items (double)
	
	public static double methodThree(double price, int quantity) {
		
		double totalPrice;
		
		totalPrice = price * quantity;
		
		return totalPrice;
	}
		
		// METHOD 4 computes and returns tax amount at 7% (0.07) for the purchase (double)
	
	public static double methodFour(double total) {
		
		final double TAX_AMOUNT = 0.07;
		double salesTax;
		
		salesTax = total * TAX_AMOUNT;
		
		return salesTax;
	}
		
		// METHOD 5 displays all information
	
	public static void methodFive(double price, int quantity, double subtotal, double tax) {
		
		double totalSale = subtotal + tax;
		
		System.out.println();
		
		// %-11s left-aligns
		// %5.2f prints 5 extra spaces for doubles and rounds to 2 decimal places
		// %6d prints 6 extra spaces for integers
		// %n is \n (newline)
		
		System.out.printf("%-11s$%5.2f%n", "Price", price);
	    System.out.printf("%-11s%6d%n", "Quantity", quantity);
	    System.out.printf("%-11s$%5.2f%n", "Subtotal", subtotal);
	    System.out.printf("%-11s$%5.2f%n", "Sales tax", tax);
	    System.out.println("------------------");
	    System.out.printf("%-11s$%5.2f%n", "Total Sale", totalSale);
		
	}
		
}

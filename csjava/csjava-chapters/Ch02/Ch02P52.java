// NAME: Samantha Chorm 	LAB: Ch02P52

package packageCh02P52;

import java.util.Scanner;

public class Ch02P52 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		final double TIP_RATE = 0.20;
		final double TAX_RATE = 0.05;
		double userPrice;
		double tipPrice;
		double taxPrice;
		double finalPrice;
		
		System.out.print("Enter the meal price $");
		userPrice = in.nextDouble();
		
		tipPrice = userPrice * TIP_RATE;
		taxPrice = userPrice * TAX_RATE;
		finalPrice = userPrice + tipPrice + taxPrice;
		
		System.out.printf("Total cost is $%.2f", finalPrice);

		if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("\n\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

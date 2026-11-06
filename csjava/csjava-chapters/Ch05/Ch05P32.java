// NAME: Samantha Chorm 	LAB: Ch05P32

package packageCh05P32;

import java.util.Scanner;

public class Ch05P32 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		// Call methodOne to get price
        double price = Methods.methodOne(in);
        
        // Call methodTwo to get quantity
        int quantity = Methods.methodTwo(in);
        
        // Call methodThree and pass price and quantity
        double subtotal = Methods.methodThree(price, quantity);
        
        // Call methodThree and pass subtotal
        double tax = Methods.methodFour(subtotal);
        
        // Call methodThree, pass all values and display output
        Methods.methodFive(price, quantity, subtotal, tax);
        
        if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

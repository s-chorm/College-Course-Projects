// NAME: Samantha Chorm 	LAB: Ch04P26

package packageCh04P26;

import java.util.Scanner;

public class Ch04P26 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int userInput;
		
		// Prompts user
		
		System.out.print("Enter a negative integer: ");
		userInput = in.nextInt();
		
		// Input validation
		
		while(userInput >= 0) {
			System.out.println("Invalid input");
			System.out.print("Enter another number: ");
			userInput = in.nextInt();
		}
		
		// Prints if userInput is a negative number
		
		System.out.println("Thank you");
		
		if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

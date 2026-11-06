// NAME: Samantha Chorm 	LAB: Ch06P29

package packageCh06P29;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Ch06P29 {
	
	// Display method
	
	public static void display(ArrayList<String> contacts) {
		System.out.println(String.join(", ", contacts)); // String.join includes commas between each item in the ArrayList
	}

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		ArrayList<String> contacts = new ArrayList<>(Arrays.asList("Allison", "Dillon", "Colleen")); // Initializes ArrayList with the names
		
		// a. Call the display method to display initial ArrayList
		
		display(contacts);
		
		// b. Add "Olivia", then display
		
		contacts.add("Olivia");
		
		display(contacts);
		
		// c. Replace "Colleen" with "Reece", then display
		
		contacts.set(2, "Reece");
		
		display(contacts);
		
		// d. Remove "Dillon", then display
		
		contacts.remove("Dillon");
		
		display(contacts);

		if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("Press Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

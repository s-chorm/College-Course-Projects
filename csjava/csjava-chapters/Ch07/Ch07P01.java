// NAME: Samantha Chorm 	LAB: Ch07P01

package packageCh07P01;

import java.util.Scanner; // Imported to read file
import java.io.File; // Imported to get file
import java.io.FileNotFoundException; // Imported to throw exception if file isn't found

public class Ch07P01 {

	public static void main(String[] args) {
		
		// Variables for while loop
		String name = "";
		String id = "";
		double hourlyRate = 0.0;
		double hoursWorked = 0.0;
		double grossPay = 0.0;
		
		// Table header (Left alignment, spaces, and strings included)
		System.out.printf("%-17s %-8s %s%n", "Employee", "ID#", "Gross Pay");
		System.out.println("------------------------------------");
		
		try (Scanner inFile = new Scanner(new File("csjava/csjava-chapters/Ch07/employee_data.txt"))) {

			// This loop reads items in order: name, ID, hourly rate, hours worked
			while (inFile.hasNext()) {
				name = inFile.next();
				id = inFile.next();
				hourlyRate = inFile.nextDouble();
				hoursWorked = inFile.nextDouble();
				
				// Calculates gross pay
				grossPay = hourlyRate * hoursWorked;
				
				// Prints each row in the proper format
				System.out.printf("%-17s %-8s $%.2f%n", name, id, grossPay);
			}
			
			// Try-with-resources automatically closes inFile, therefore inFile.close() isn't written
		}
		catch (FileNotFoundException e) {
			System.out.println("ERROR: Input file cannot be opened.");
			e.printStackTrace();
		}

		Scanner in = new Scanner(System.in);

		System.out.println("\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

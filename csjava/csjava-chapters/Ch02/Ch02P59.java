// NAME: Samantha Chorm 	LAB: Ch02P59

package packageCh02P59;

import java.util.Scanner;

public class Ch02P59 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		final double PI = 3.14159;
		double userRadius;
		String userUnit;
		double surfaceArea;
		double volume;
		double circumference;
		
		System.out.print("Enter the radius: ");
		userRadius = in.nextDouble();
		in.nextLine();
		System.out.print("Enter the units (feet, miles, etc.): ");
		userUnit = in.nextLine();
		
		// Surface Area = 4πr²
		surfaceArea = 4 * PI * (Math.pow(userRadius, 2));
		
		// Volume = 4π(r³/3)
		volume = 4 * PI * (Math.pow(userRadius, 3) / 3.0);
		
		// Circumference = 2πr
		circumference = 2 * PI * userRadius;
		
		System.out.printf("%nThe surface area is %.3f square %s%n", surfaceArea, userUnit);
		System.out.printf("The volume is %.3f cubic %s%n", volume, userUnit);
		System.out.printf("The circumference is %.3f %s", circumference, userUnit);

		if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

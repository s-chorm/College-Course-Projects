// NAME: Samantha Chorm 	LAB: Ch04P02

package packageCh04P02;

import java.util.Scanner;

public class Ch04P02 {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		// Constants
		
		final double WATER_LEVEL_MAX = 3.3;
		final int FLOOD_GATE_MIN = 1;
		final double WATER_PER_MINUTE = 0.03;
		
		// Variables
		
		double userWaterLevel;
		double dischargeRate; // Calculated for simulation loop
		double waterAmount; // Used in simulation loop
		int userFloodGate;
		int minuteCount = 0; // Used in simulation loop
		
		// Gets user input
		
		System.out.print("Enter the water level (> 3.3) ");
		userWaterLevel = in.nextDouble();
		
		// Input validation for water level
		
		while (userWaterLevel <= WATER_LEVEL_MAX) {
			System.out.println("Invalid input");
			System.out.println("Enter another number for the water level (> 3.3) ");
			userWaterLevel = in.nextDouble();
		}
		
		System.out.print("Enter the gate opening in one foot increments ");
		userFloodGate = in.nextInt();
		
		// Input validation for gate opening
		
		while (userFloodGate < FLOOD_GATE_MIN) {
			System.out.println("Invalid input");
			System.out.println("Enter another number for the gate opening in one foot increments ");
			userFloodGate = in.nextInt();
		}
		
		System.out.println(); // Blank line to separate sections
		
		// Calculations
		
		dischargeRate = WATER_PER_MINUTE * userFloodGate;
		waterAmount = userWaterLevel;
		
		// Simulation of discharging water
		// Stops until water level has reached 3.3 feet

		while (waterAmount > WATER_LEVEL_MAX) {
			minuteCount++;
			waterAmount = waterAmount - dischargeRate;
			System.out.printf("Minutes:%4d   Water Level:%5.2f\t\n", minuteCount, waterAmount);
		}
		
		System.out.println();
		
		System.out.println("The water level is now at 3.3 feet.");

		if (in.hasNextLine()) {
            in.nextLine(); 
        }
		System.out.println("\nPress Enter to exit...");
		in.nextLine();

		in.close();

		System.exit(0);
	}

}

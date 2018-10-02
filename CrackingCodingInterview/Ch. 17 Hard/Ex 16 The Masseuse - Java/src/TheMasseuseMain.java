import java.net.Inet4Address;
import java.util.ArrayList;

import javafx.util.Pair;

/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 *
 *The Masseuse: A popular masseuse receives a sequence of back-to-back appointment requests
and is debating which ones to accept. She needs a lS-minute break between appointments and
therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appointment
requests (all multiples of 1 S minutes, none overlap, and none can be moved), find the optimal
(highest total booked minutes) set the masseuse can honor. Return the number of minutes.
EXAMPLE
Input {30, 15, 60, 75, 45, 15, 15, 45}
Output: 180 minutes ({30, 60,45, 45}).
 *
 *
 *Solution : recursive solution to look for the optimal mintues 
 *
 */
public class TheMasseuseMain {

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int appointments [] = {30, 15, 60, 75, 45, 15, 15, 45};
		
		Pair<ArrayList<Integer>, Integer> result = maxMins(appointments);
		System.out.println("Max amount : ");
		for(Integer appointment : result.getKey()) {
			System.out.print(appointments[appointment] + "  ");
		}
		System.out.println("  =  " + result.getValue());
		
		System.exit(0);
	}
	
	public static Pair<ArrayList<Integer>, Integer> maxMins(int appointment []) {
		ArrayList<Integer> appointmentsIndex = new ArrayList<>();
		int mins = 0;
			
//			appointmentsIndex = (ArrayList<Integer>) maxMinsRecurse(appointment,new ArrayList<Integer>(),new ArrayList<Integer>(), 0).clone();
//			if(countMins(max, appointment) < countMins(appointmentsIndex, appointment)) {
//				max = appointmentsIndex;
//			}
		
		appointmentsIndex = maxMinsFromBook(appointment, new ArrayList<>(), 0);
		
		mins = countMins(appointmentsIndex, appointment);
		return new Pair<ArrayList<Integer>, Integer> (appointmentsIndex, mins); 
	}
	
	public static ArrayList<Integer> maxMinsFromBook(int appointments [] , ArrayList<Integer> currList, 
														int index){
		if(index > appointments.length-1) {
			return currList;
		}
		ArrayList<Integer> temp;
		ArrayList<Integer> withCurrentIndex = (ArrayList<Integer>) currList.clone();
		
		withCurrentIndex.add(index);
		temp = maxMinsFromBook(appointments, withCurrentIndex, index+2);
		
		ArrayList<Integer> withoutCurrentIndex = maxMinsFromBook(appointments, currList, index+1);
		
		
		if(countMins(temp, appointments) > countMins(withoutCurrentIndex, appointments)) {
			System.out.println(temp.toString());
			return temp;
		}
		else {
			System.out.println(withoutCurrentIndex.toString());
			return withoutCurrentIndex;
		}
		
	}
	
	public static ArrayList<Integer> maxMinsRecurse(int appointments [],
									ArrayList<Integer>currList, 
									ArrayList<Integer> max, int index){
		if(!currList.isEmpty() && index < currList.get(currList.size()-1)) {
			return currList;
		}
		
		System.out.println("currList : ");
		printArray(currList.stream().mapToInt(Integer::intValue).toArray(), appointments);
		ArrayList<Integer> temp = new ArrayList<>();
		for(int i = index; i < appointments.length; i += 1) {
			if(currList.isEmpty()) {
				currList.add(index);
				index++;
			}
			int testIndex = Math.abs(currList.get(currList.size()-1) - i);
			
			if(i - (currList.get(currList.size()-1)) > 1  ) {				
			currList.add(i);
			
			
			temp = maxMinsRecurse(appointments,  currList, max, i);
			
			if(countMins(max, appointments) < countMins(temp, appointments)) {
				System.out.println("max List:");
				max = (ArrayList<Integer>) temp.clone();
				printArray(max.stream().mapToInt(Integer::intValue).toArray(), appointments);

			}
		
				currList.remove(currList.size()-1);				

			}
			
		}
		if(countMins(max, appointments) > countMins(currList, appointments)) {
			
		
			return max;
		}
		
		return currList;
	}
	
	public static void printArray(int appointmentIndex [],int [] appointment) {
		for(Integer index : appointmentIndex) {
			if(index < appointment.length) {
				System.out.print( appointment[index]+ "  ");
			}
		}
		System.out.println();
	}

	public static int countMins(ArrayList<Integer> appointmentIndex, int appointment []) {
		int totalMins = 0;
		
		for(Integer index: appointmentIndex) {
			if(index < appointment.length) {
				totalMins += appointment[index];
			
			}
		}
		return totalMins;
	}

}

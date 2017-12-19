import java.util.HashMap;
import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		HashMap<String, String> hashmap = new HashMap<String, String>();//[1]
		//System.out.println("こんにちは");
		int n = scanner.nextInt();
		while (scanner.hasNext()) {
			String command = new String();
			command = scanner.next();
			String operand = new String();
			operand = scanner.next();
			switch (command.charAt(0)) {
			case 'a':
				hashmap.put(operand, "a");
				break;

			case 'r':
				hashmap.remove(operand);
				break;
			case 'f':
				if (hashmap.get(operand) == null) {
					System.out.println("no");
				} else {
					System.out.println("yes");
				}
				break;
			}
		}
	}
}

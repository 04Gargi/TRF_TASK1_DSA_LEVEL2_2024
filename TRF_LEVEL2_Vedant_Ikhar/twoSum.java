import java.util.Scanner;
import java.util.HashMap;

public class question1 {
    static Scanner scan = new Scanner(System.in);
    static HashMap<Integer, Integer> myMap = new HashMap<Integer, Integer>();
    public static void main(String[] args) {
        int size, target, x;
        System.out.print("Enter size of array: ");
        size = scan.nextInt();
        int[] arr = new int[size];
        int[] index = new int[2];
        System.out.print("Enter array: ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scan.nextInt();
        }
        System.out.print("Enter target value: ");
        target = scan.nextInt();
        
/*  [1 2 4 6] target is 6 */

        for (int i = 0; i < arr.length; i++) {
            x = target - arr[i];
            if (myMap.containsKey(x)) {
                index[0] = arr[i];
                index[1] = x;
                System.out.printf("%d %d",index[0], index[1]);
                System.out.println();
            }
            else {
                myMap.put(arr[i], i);
            }
        }
    }
}

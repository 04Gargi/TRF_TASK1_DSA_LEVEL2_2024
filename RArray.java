import java.util.Arrays;
import java.util.Scanner;

public class RArray {
    private int[] arr;
    private int targetSum;

    public RArray(int arrSize) {
        arr = new int[arrSize];
        targetSum = 0;
    }

    public void getData() {
        System.out.println("Enter Array Elements: ");
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter Target sum:");
        targetSum = sc.nextInt();
        System.out.println("Array is: " + Arrays.toString(arr));
    }

    public void findTargetSum(int[] arr, int targetSum) {
        int arrSize = arr.length;


        System.out.println("Pairs that sum to the target:");
        for (int i = 0; i < arrSize; i++) {
            for (int j = i + 1; j < arrSize; j++) {
                if (arr[i] + arr[j] == targetSum) {
                    System.out.println(Arrays.toString(new int[]{arr[i], arr[j]}));
                }
            }
        }


        System.out.println("Triplets that sum to the target:");
        for (int i = 0; i < arrSize; i++) {
            for (int j = i + 1; j < arrSize; j++) {
                for (int k = j + 1; k < arrSize; k++) {
                    if (arr[i] + arr[j] + arr[k] == targetSum) {
                        System.out.println(Arrays.toString(new int[]{arr[i], arr[j], arr[k]}));
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Enter the array size:");
        Scanner sc = new Scanner(System.in);
        int arrSize = sc.nextInt();

        RArray obj = new RArray(arrSize);
        obj.getData();
        System.out.println("Target sum is: " + obj.targetSum);

        obj.findTargetSum(obj.arr, obj.targetSum);
        sc.close();
    }
}

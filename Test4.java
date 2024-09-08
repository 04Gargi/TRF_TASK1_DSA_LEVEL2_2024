import java.util.Scanner;

class Numbers {
    public static boolean isEven(int number) {
        int remainder = number;

        while (remainder > 1) {
            remainder /= 2;
        }

        return remainder == 0;
    }
}

public class Test4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number ");
        int number = sc.nextInt();

        boolean result = Numbers.isEven(number);
        if (result) {
            System.out.println("The given number " + number + " is even");
        } else {
            System.out.println("The given number " + number + " is odd");
        }

        sc.close();
    }
}

import java.lang.*;
import java.util.*;

class Node{
    int data;
    Node next;
    Node(int data, Node next){
        this.data = data;
        this.next = next;
    }
}
public class Linkedlistadd {
    public static void main(String[] args){
        System.out.println("Enter 1st number : ");
        Scanner sc =new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println("Enter 2nd number : ");
        int y = sc.nextInt();
        Node l1 = convertList(x);
        Node l2 = convertList(y);
        Node ans = addList(l1, l2);
        System.out.println("Addition Output in linked list Reverse Format ");
        printList(ans);

    }

    public static Node convertList(int num){
        Node l = null;
        while(num != 0){
            l = new Node(num%10, l);
            num = num/10;
        }
        return l;
    }
    public static int toInteger(Node l){
        Node curr = l;
        int ans = 0;
        while(curr != null){
            ans = ans*10 + curr.data;
            curr = curr.next;
        }
        return ans;
    }
    public static Node reverse(Node head){
        Node prev = head;
        Node current = head.next;
        while(current != null){
            Node next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head.next = null;
        head = prev;
        return head;
    }

    public static Node addList(Node l1, Node l2){
        l1 = reverse(l1);
        printList(l1);
        l2 = reverse(l2);
        printList(l2);
        int num1 = toInteger(l1);
        int num2 = toInteger(l2);
        int sum = num1 + num2;
        Node l3 = convertList(sum);
        l3 = reverse(l3);
        return l3;
    }

    public static void printList(Node ans){
        Node curr = ans;
        while(curr != null){
            System.out.print(curr.data+"->");
            curr = curr.next;
        }
        System.out.println("null");

}}

package Library_Management_System.system;

import java.util.Scanner;

public class Book{
    public int S_no;
    public String Book_Name;
    public String Author;
    public int BookQty;
    public int BookQty_Copy;
    Scanner sc = new Scanner(System.in);
    public Book(){
        System.out.println("Enter the Serial No. of BOOK: ");
        this.S_no = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the name of BooK: ");
        this.Book_Name = sc.nextLine();
        System.out.println("Enter Name of Author: ");
        this.Author = sc.nextLine();
        System.out.println("Enter Quantity of BooK: ");
        this.BookQty = sc.nextInt();
        BookQty_Copy = this.BookQty;
    }
}

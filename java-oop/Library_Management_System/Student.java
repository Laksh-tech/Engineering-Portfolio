package Library_Management_System;
import  java.util.Scanner;

import Library_Management_System.system.Book;

public class Student{
    public String studentName;
    public String regNum;

    Book borrowedBooks[] = new Book[3];
    public int booksCount = 0;
     // Creating object of Scanner class to
    // take input from user
    Scanner sc = new Scanner(System.in);

    // Constructor
    public Student()
    {
        // Print statement
        System.out.println("Enter Student Name:");

        // This keywords refers to current instance
        this.studentName = sc.nextLine();

        // Print statement
        System.out.println("Enter Registration Number:");
        this.regNum = sc.nextLine();
    }
}

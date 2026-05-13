package Library_Management_System;
import java.util.Scanner;

import Library_Management_System.system.Book;

public class Books {
    Book theBooks[] = new Book[50];
    public static int count;
    Scanner sc = new Scanner(System.in);
    public int compareBooks(Book Book1, Book Book2){
        if(Book1.Book_Name.equalsIgnoreCase(Book2.Book_Name)){
            // Printing book exists
            System.out.println(
                "Book of this Name Already Exists.");
            return 0;
        }
        if(Book1.S_no == Book2.S_no){
            // Printing book exists
            System.out.println(
                "Book of this Serial.No Already Exists.");
            return 0;
        }
        return 1;
    }
     // Method 2
    // To add book
    public void addBook(Book b)
    {

        for (int i = 0; i < count; i++) {

            if (this.compareBooks(b, this.theBooks[i])
                == 0)
                return;
        }
        if (count < 50) {

            theBooks[count] = b;
            count++;
        }
        else {

            System.out.println(
                "No Space to Add More Books.");
        }
    }
    public void searchBySno()
    {

        // Display message
        System.out.println(
            "\t\t\t\tSEARCH BY SERIAL NUMBER\n");

        // Class data members
        int sNo;
        System.out.println("Enter Serial No of Book:");
        sNo = sc.nextInt();

        int flag = 0;
        System.out.println(
            "S.No\t\tName\t\tAuthor\t\tAvailable Qty\t\tTotal Qty");

        for (int i = 0; i < count; i++) {
            if (sNo == theBooks[i].S_no) {
                System.out.println(
                    theBooks[i].S_no + "\t\t"
                    + theBooks[i].Book_Name + "\t\t"
                    + theBooks[i].Author + "\t\t"
                    + theBooks[i].BookQty_Copy + "\t\t"
                    + theBooks[i].BookQty);
                flag++;
                return;
            }
        }
        if (flag == 0)
            System.out.println("No Book for Serial No "
                               + sNo + " Found.");
    }
    public void searchByAuthor(){
        System.out.println(
            "\t\t\t\tSEARCH BY AUTHOR'S NAME");

        sc.nextLine();
        System.out.println("Enter Author Name:");
        String authorName = sc.nextLine();
        int flag = 0;

        System.out.println(
            "S.No\t\tName\t\tAuthor\t\tAvailable Qty\t\tTotal Qty");

        for (int i = 0; i < count; i++){
            // if author matches any of its book
            if (authorName.equalsIgnoreCase(
                    theBooks[i].Author)) {

                // Print below corresponding credentials
                System.out.println(
                    theBooks[i].S_no + "\t\t"
                    + theBooks[i].Book_Name + "\t\t"
                    + theBooks[i].Author + "\t\t"
                    + theBooks[i].BookQty_Copy + "\t\t"
                    + theBooks[i].BookQty);
                flag++;
            }
        }

        // Else no book matches for author
        if (flag == 0)
            System.out.println("No Books of " + authorName
                               + " Found.");
    }
    public void showAllBooks()
    {

        System.out.println("\t\t\t\tSHOWING ALL BOOKS\n");
        System.out.println(
            "S.No\t\tName\t\tAuthor\t\tAvailable Qty\t\tTotal Qty");
            for(int i = 0 ; i<count;i++){
                System.out.println(
                theBooks[i].S_no + "\t\t"
                + theBooks[i].Book_Name + "\t\t"
                + theBooks[i].Author + "\t\t"
                + theBooks[i].BookQty_Copy + "\t\t"
                + theBooks[i].BookQty);
            }
    }
    public void upgradeQty(){
        System.out.println("\t\t\t\tUPGRADE QUANTITY OF A BOOK\n");
        System.out.println("Enter Serial No of Book");
        int sNo = sc.nextInt();
        for (int i = 0; i < count; i++) {
            if(sNo == theBooks[i].S_no){
                 // Display message
                System.out.println(
                    "Enter No of Books to be Added:");

                int addingQty = sc.nextInt();
                theBooks[i].BookQty += addingQty;
                theBooks[i].BookQty_Copy += addingQty;
                return;
            }
        }
    }
    
    // Method 7
    // To create menu
    public void dispMenu()
    {

        // Displaying menu
        System.out.println(
            "----------------------------------------------------------------------------------------------------------");
        System.out.println("Press 1 to Add new Book.");
        System.out.println("Press 0 to Exit Application.");
        System.out.println(
            "Press 2 to Upgrade Quantity of a Book.");
        System.out.println("Press 3 to Search a Book.");
        System.out.println("Press 4 to Show All Books.");
        System.out.println("Press 5 to Register Student.");
        System.out.println(
            "Press 6 to Show All Registered Students.");
        System.out.println("Press 7 to Check Out Book. ");
        System.out.println("Press 8 to Check In Book");
        System.out.println(
            "-------------------------------------------------------------------------------------------------------");
    }

    // Method 8
    // To search the library
    public int isAvailable(int sNo)
    {

        for (int i = 0; i < count; i++) {
            if (sNo == theBooks[i].S_no) {
                if (theBooks[i].BookQty_Copy > 0) {

                    System.out.println(
                        "Book is Available.");
                    return i;
                }
                System.out.println("Book is Unavailable");
                return -1;
            }
        }

        System.out.println("No Book of Serial Number "
                           + " Available in Library.");
        return -1;
    }

    // Method 9
    // To remove the book from the library
    public Book checkOutBook()
    {

        System.out.println(
            "Enter Serial No of Book to be Checked Out.");
        int sNo = sc.nextInt();

        int bookIndex = isAvailable(sNo);

        if (bookIndex != -1) {
            theBooks[bookIndex].BookQty_Copy--;
            return theBooks[bookIndex];
        }
        return null;
    }

    // Method 10
    // To add the Book to the Library
    public void checkInBook(Book b)
    {
        for (int i = 0; i < count; i++) {
            if (b.equals(theBooks[i])) {
                theBooks[i].BookQty++;
                return;
            }
        }
    }
}





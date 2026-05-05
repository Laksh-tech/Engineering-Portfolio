/*Problem: Reverse String Inplace 
 Pattern : Two Pointer ,String 
 Time Complexity: O(N) where N is size of string.
 Space Complexity: O(1) where we use inplace swap
*/
#include <iostream>
#include <string>
using namespace std;

string ReverseStringInplace(string a) {
    // char temp; // char temp for holding element 
    int left = 0;
    int right = a.size() - 1;

    while (left < right) { 
        // temp = a[left];
        // a[left] = a[right];
        // a[right] = temp;
        swap(a[right],a[left]); //using built-in swap() ; we could also use temp for manual swap
        left++;
        right--;
    }
    return a;
}
int main(){
    string a = "SUMO";
    cout<<"Reversed String: "<<ReverseStringInplace(a); //Calling Function
    return 0;
}
//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class RemoveDuplicateElementsFromSortedArray_GFG {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0)
        {
            int N = sc.nextInt();
            int a[] = new int[N];
            for(int i=0; i<N; i++)
                a[i] = sc.nextInt();
            
            Solution g = new Solution();
            int n = g.remove_duplicate(a,N);
            
            for(int i=0; i<n; i++)
                System.out.print(a[i]+" ");
            System.out.println();
            T--;
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int remove_duplicate(int A[],int N) {
        // O(N) time complexity && O(N) Space complexity
        int prev = -1;
        ArrayList<Integer> newArr = new ArrayList<Integer>();
        for(int i = 0; i < N; i++) {
            if(A[i] != prev) {
                newArr.add(A[i]);
            }
            prev = A[i];
        }
        for(int i = 0; i < newArr.size(); i++) {
            A[i] = newArr.get(i);
        }
        return newArr.size();

        // O(N) time complexity && O(1) space complexity
        int prev = A[0], index = 1;
        for(int i = 1; i < N; i++) {
            if(A[i] != prev) {
                A[index] = A[i];
                index++;
                prev = A[i]; 
            } else {
                prev = A[i];
            }
        }
        return index;
    }
}
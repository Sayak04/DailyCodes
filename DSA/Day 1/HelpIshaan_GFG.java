//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class HelpIshaan_GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.NthTerm(N);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public Boolean isPrime(int n) {
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    public int NthTerm(int N)
    {
        if(N == 1) return 1;
        int abovePrime = -1, belowPrime = -1;
        for(int i = N; i <= 1000000; i++) {
            if(isPrime(i) == true) {
                abovePrime = i;
                break;
            }
        }
        for(int i = N - 1; i >= 2; i--) {
            if(isPrime(i) == true) {
                belowPrime = i;
                break;
            }
        }
        if(abovePrime - N < N - belowPrime) {
            return Math.abs(abovePrime - N);
        }
        return Math.abs(N - belowPrime);
    }
}
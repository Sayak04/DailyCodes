class 1328_BreakAPalindrome {
    public String breakPalindrome(String palindrome) {
        if(palindrome.length() == 1) return "";
        int n = palindrome.length();
        String ans = new String();
        boolean found = false;
        for(int i = 0; i < n/2; i++) {
            if(palindrome.charAt(i) != 'a') {
                palindrome = palindrome.substring(0, i) + "a" + palindrome.substring(i+1);
                found = true;
                break;
            }
        }
        if(found == false) {
            palindrome = palindrome.substring(0, n-1) + "b";
        }
        return palindrome;
    }
}
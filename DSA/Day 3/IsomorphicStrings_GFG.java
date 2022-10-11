//{ Driver Code Starts
    import java.io.BufferedReader;
    import java.io.InputStreamReader;
    import java.io.IOException;
    import java.util.Arrays;
    import java.util.*;
    
    
    public class Driver {
        
        public static void main(String[] args)throws IOException {
           
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int tc = Integer.parseInt(br.readLine());
            while(tc-->0)
            {
                String s1 = br.readLine();
                String s2 = br.readLine();
                
                Solution obj = new Solution();
                
                boolean a = obj.areIsomorphic(s1,s2);
                if(a)
                System.out.println(1);
                else
                System.out.println(0);
            }
        }
        
    }
    
    // } Driver Code Ends
    
    
    class IsomorphicStrings_GFG
    {
        //Function to check if two strings are isomorphic.
        public static boolean areIsomorphic(String str1,String str2)
        {
            if(str1.length() != str2.length()) return false;
            boolean isDone[] = new boolean[26];
            for(int i = 0; i < 26; i++) isDone[i] = false;
            HashMap<Character, Character> map = new HashMap<Character, Character>();
            for(int i = 0; i < str1.length(); i++) {
                if(map.containsKey(str1.charAt(i))) {
                    if(map.get(str1.charAt(i)) != str2.charAt(i)) return false;
                } else {
                    map.put(str1.charAt(i), str2.charAt(i));
                    if(isDone[str2.charAt(i) - 'a'] == true) return false;
                    isDone[str2.charAt(i) - 'a'] = true;
                }
            }
            return true;
        }
    }

    // Check if also one charcter which is already assigned to one, if not assignedto different
    // like  p -> f
    // again y -> f

    // p i j t h b s f y
    // f v l a d z p b f
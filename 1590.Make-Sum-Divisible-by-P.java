//JAVA

import java.util.*;

class Solution {
    public int minSubarray(int[] nums, int p) {
        long total = 0;
        for (int x : nums) total += x;

        int target = (int)(total % p);
        if (target == 0) return 0; // already divisible

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);  // prefix mod 0 before array starts

        long prefix = 0;
        int ans = nums.length;

        for (int i = 0; i < nums.length; i++) {
            prefix = (prefix + nums[i]) % p;
            int need = (int)((prefix - target + p) % p);

            if (map.containsKey(need)) {
                ans = Math.min(ans, i - map.get(need));
            }

            // store prefix mod (if already exists, keep smallest index only)
            map.put((int)prefix, i);
        }

        return ans == nums.length ? -1 : ans;
    }
}

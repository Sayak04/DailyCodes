class 2432_TheEmployeeThatWorkedOnTheLongestTask {
    public int hardestWorker(int n, int[][] logs) {
        int start = 0, maxi = 0, ans = 1000000;
        for(int i = 0; i < logs.length; i++) {
            int duration = logs[i][1] - start;
            if(duration == maxi) {
                ans = Math.min(logs[i][0], ans);
            } else if(duration > maxi) {
                maxi = duration;
                ans = logs[i][0];
            }
            start += duration;
        }
        return ans;
    }
}
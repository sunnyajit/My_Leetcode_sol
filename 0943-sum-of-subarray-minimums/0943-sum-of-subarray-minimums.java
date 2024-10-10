 class Solution { // code written by sunny
    public int sumSubarrayMins(int[] arr) {
        int mod = 1000000007;
        int n = arr.length;
        long ans = 0;

        int[] left = new int[n];
        int[] right = new int[n];

        for(int i=0; i<n; i++){
            int j=i-1;
            while(j>=0 && arr[j] >= arr[i]){
                j = left[j];
            }
            left[i] = j;
        }  

        for(int i=n-1; i>=0; i--){
            int j = i+1;
            while(j<n && arr[j]> arr[i]){
                j = right[j];
            }
            right[i] = j;
        }

        for(int i=0; i<n; i++){
            ans = (ans+(long) arr[i]*(i-left[i])*(right[i]-i))%mod;
        }

        return (int)ans;
    }
}
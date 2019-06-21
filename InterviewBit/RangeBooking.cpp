/*
Range booking

Meghan is looking to book hotel rooms for an incoming delegation of engineers. She is allowed to spend anywhere between B and C (B and C inclusive) for these bookings. She needs to book rooms consecutively as the delegates would prefer to stay as close to each other as possible.

Meghan has been given the pricing of the rooms in order in the form of an array A 
( Needless to say, the prices are non negative integers ). 
You need to find out the number of options Meghan has for booking the rooms. 
Note that there is no restriction on the number of rooms she can book 
( She can book as less as 1 room, or she can book all the room if the budget 
constraints are satisfied ). 
*/

int numSub(vector<int>& A, int C) {
    int i = 0, j = 0, cnt = 0, sum = 0;
    while(j < A.size()) {
        sum += A[j];
        while(sum > C && i <= j) {
            sum -= A[i];
            i++;
        }
        cnt += (j - i + 1);
        j++;
    }
    return cnt;
}

int Solution::numOptions(vector<int> &A, int B, int C) {
    if(B > C)
        return numOptions(A, C, B);
    return numSub(A, C) - numSub(A, B - 1);    
}


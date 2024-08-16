//
// Created by Robert Rochlin on 8/14/24.
//
#include <iostream>
#include <vector>
#include <deque>
#include <string>

#include <bit

int multiple_of_3_or_5(){
    // find all multiples of 3 or 5 below 1000 and add them together
    int three=0, five=0, sum=0;
    while(five<1000){
        sum+=five;
        if(three%5) sum+=three;
        three+=3;
        five+=5;
    }
    while(three<1000){
        if(three%5) sum+=three;
        three+=3;
    }
    return sum;
}

int even_fib_number_sum(){
    // sum the first x fib terms
    int sum=0;
    int first=1;
    int second=2;
    while(second<4000000){
        if(second%2==0) sum+=second;
        int temp=first+second;
        first=second;
        second=temp;
    }
    return sum;
}

long largest_prime_factor(){
    long num = 600851475143;
    long divisor = 2; // start with 2 search for an even divisor then determine if its prime.
    while(divisor<num/2){
        if(num%divisor==0){
            long factor = num/divisor;
            // check if factor is prime if so return
            bool isprime=true;
            for(int i=2; i<factor/2; i++){
                if(factor%i==0) {
                    isprime= false;
                    break;
                }
            }
            if(isprime) return factor;
        }
        divisor+=1;
    }
    return -1;
}

int longest_palindrome_3_digit(){
    // do i decrease both at once or one at a time
    int x=999,y;
    std::vector<int> nums;
    for (; x > 99; x--) {
        y=x;
        for (; y > 99; y--) {
            nums.push_back(x * y);
        }
    }
    std::sort(nums.begin(), nums.end());
    for(auto it=nums.rbegin(); it!=nums.rend(); it++){
        std::string r = std::to_string(*it);
        std::reverse(r.begin(), r.end());
        if(std::to_string(*it) == r) return *it;
    }
    return -1;
}

long smallest_clean_num(){
    // can't be an odd number
    // can't be a number not ending in 0;
    long num=2520;
    while(true){
        int div = 20;
        while(true){
            if(div==1) return num;
            if(num%div--!=0) break;
        }
        num+=20;
    }
}

long sum_square_diff(){
    long sum_sqs = 0;
    long sq_sum = 0;
    for(int i = 1; i<=100; i++){
        sum_sqs+=i*i;
        sq_sum+=i;
    }
    return sq_sum*sq_sum - sum_sqs;
}

long prime_10001(){
    int prime=6, start=15;
    while(prime<10001){
        //primes have to be odd
        start+=2;
        int divisor=1;
        while(true){
            // divisor also has to be odd.
            divisor+=2;
            if(start%divisor==0) break;
            if(divisor>start/2) {prime++; break;}
        }
    }
    return start;
}

long greatest_4_consecutive_product() {
    std::string num =
    "73167176531330624919225119674426574742355349194934"
    "96983520312774506326239578318016984801869478851843"
    "85861560789112949495459501737958331952853208805511"
    "12540698747158523863050715693290963295227443043557"
    "66896648950445244523161731856403098711121722383113"
    "62229893423380308135336276614282806444486645238749"
    "30358907296290491560440772390713810515859307960866"
    "70172427121883998797908792274921901699720888093776"
    "65727333001053367881220235421809751254540594752243"
    "52584907711670556013604839586446706324415722155397"
    "53697817977846174064955149290862569321978468622482"
    "83972241375657056057490261407972968652414535100474"
    "82166370484403199890008895243450658541227588666881"
    "16427171479924442928230863465674813919123162824586"
    "17866458359124566529476545682848912883142607690042"
    "24219022671055626321111109370544217506941658960408"
    "07198403850962455444362981230987879927244284909188"
    "84580156166097919133875499200524063689912560717606"
    "05886116467109405077541002256983155200055935729725"
    "71636269561882670428252483600823257530420752963450";
    long product = 1;
    long max = 0;
    int pointer=0;
    std::deque<int> numbers;
    // biggest 4 adjacent numbers cannot have a 0 in them.
    while(pointer<1001){
        if (num[pointer]=='0') {
            numbers.clear();
            product=1;
            pointer++;
            continue;
        }
        product*=(num[pointer]-48);
        numbers.push_back(num[pointer++]-48);
        if(numbers.size()>13){
            product/=numbers.front();
            numbers.pop_front();
        }
        if(product>max) max = product;
    }
    return max;
}

int main() {
    std::cout<<greatest_4_consecutive_product();
//    std::cout<<prime_10001();
//    std::cout<< sum_square_diff();
//    std::cout<< smallest_clean_num();
//    std::cout<<multiple_of_3_or_5();
//    std::cout<<even_fib_number_sum();
//    std::cout<<largest_prime_factor();
//    std::cout << longest_palindrome_3_digit();
}

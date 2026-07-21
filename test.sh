
#!/bin/bash
echo
echo "===== VALID INPUT ====="

echo "TEST 1: ./push_swap 1 2 3"
./push_swap 1 2 3

echo "TEST 2: ./push_swap \"1 2 3\""
./push_swap "1 2 3"

echo "TEST 3: ./push_swap --complex 1 2 3"
./push_swap --complex 1 2 3

echo "TEST 4: ./push_swap --complex \"1 2 3\""
./push_swap --complex "1 2 3"

echo "TEST 5: ./push_swap"
./push_swap

echo "TEST 6: ./push_swap 42"
./push_swap 42

echo "TEST 7: ./push_swap -42"
./push_swap -42

echo "TEST 8: ./push_swap +42"
./push_swap +42

echo "TEST 9: ./push_swap 0"
./push_swap 0

echo "TEST 10: ./push_swap +0"
./push_swap +0

echo "TEST 11: ./push_swap -0"
./push_swap -0

echo "TEST 12: ./push_swap 3 2 1"
./push_swap "3 2 1"

echo "TEST 13: ./push_swap  3 2 1"
./push_swap " 3 2 1"

echo "TEST 14: ./push_swap 3 2 1 "
./push_swap "3 2 1 "

echo "TEST 15: ./push_swap 3   2     1"
./push_swap "3   2     1"

echo "TEST 16: ./push_swap 3 0 1"
./push_swap "3 0 1"

echo "TEST 17: ./push_swap 2147483647"
./push_swap 2147483647

echo "TEST 18: ./push_swap -2147483648"
./push_swap -2147483648

echo "TEST 19: ./push_swap +2147483647"
./push_swap +2147483647

echo "TEST 20: ./push_swap 1 0 2"
./push_swap 1 0 2

echo "TEST 21: ./push_swap -10 2 3"
./push_swap -10 2 3

echo "TEST 22: ./push_swap 10 2 3"
./push_swap 10 2 3

echo
echo "===== DUPLICATES ====="

echo "TEST 23: ./push_swap 3 2 3"
./push_swap 3 2 3

echo "TEST 24: ./push_swap 3 2 3"
./push_swap "3 2 3"

echo "TEST 25: ./push_swap 0 -0"
./push_swap 0 -0

echo "TEST 26: ./push_swap 42 -42"
./push_swap 42 +42

echo "TEST 27: ./push_swap 0 +0"
./push_swap 0 +0

echo "TEST 28: ./push_swap 00 0"
./push_swap 00 0

echo "TEST 29: ./push_swap 01 1"
./push_swap 01 1

echo
echo "===== INVALID SYNTAX ====="

echo "TEST 30: ./push_swap 1 abc 3"
./push_swap 1 abc 3

echo "TEST 31: ./push_swap 1 --2"
./push_swap "1 --2"

echo "TEST 32: ./push_swap +"
./push_swap "+"

echo "TEST 33: ./push_swap"
./push_swap ""

echo
echo "===== OVERFLOW ====="

echo "TEST 33: ./push_swap 2147483648"
./push_swap 2147483648

echo "TEST 33: ./push_swap -2147483649"
./push_swap -2147483649

echo

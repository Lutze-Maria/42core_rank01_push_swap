
#!/bin/bash

echo "TEST 1: ./push_swap 1 2 3"
./test_parser 1 2 3

echo "TEST 2: ./push_swap \"1 2 3\""
./test_parser "1 2 3"

echo "TEST 3: ./push_swap --complex 1 2 3"
./test_parser --complex 1 2 3

echo "TEST 4: ./push_swap --complex \"1 2 3\""
./test_parser --complex "1 2 3"

echo "TEST 5: ./push_swap"
./test_parser

echo "TEST 6: ./push_swap 42"
./test_parser 42

echo "TEST 7: ./push_swap -42"
./test_parser -42

echo "TEST 8: ./push_swap +42"
./test_parser +42

echo "TEST 9: ./push_swap 0"
./test_parser 0

echo "TEST 10: ./push_swap +0"
./test_parser +0

echo "TEST 11: ./push_swap -0"
./test_parser -0

echo "TEST 12: ./push_swap 3 2 1"
./test_parser "3 2 1"

echo "TEST 13: ./push_swap  3 2 1"
./test_parser " 3 2 1"

echo "TEST 14: ./push_swap 3 2 1 "
./test_parser "3 2 1 "

echo "TEST 15: ./push_swap 3   2     1"
./test_parser "3   2     1"

echo "TEST 16: ./push_swap 3 0 1"
./test_parser "3 0 1"

echo "TEST 17: ./push_swap 2147483647"
./test_parser 2147483647

echo "TEST 18: ./push_swap -2147483648"
./test_parser -2147483648

echo "TEST 19: ./push_swap +2147483647"
./test_parser +2147483647

echo "TEST 20: ./push_swap 1 0 2"
./test_parser 1 0 2

echo "TEST 21: ./push_swap -10 2 3"
./test_parser -10 2 3

echo "TEST 22: ./push_swap 10 2 3"
./test_parser 10 2 3

echo

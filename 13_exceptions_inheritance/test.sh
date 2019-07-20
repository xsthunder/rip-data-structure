clear && g++ -std=c++11 *.cpp -g
./a.out simple.txt test.output
diff test.output output_simple.txt

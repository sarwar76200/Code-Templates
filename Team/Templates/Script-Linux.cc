for((i = 1; i <= 1000; ++i)); do
    echo Testing $i
    ./gen > in.txt
    ./main < in.txt > out1.txt
    ./brute < in.txt > out2.txt
    diff -w out1.txt out2.txt || break
done

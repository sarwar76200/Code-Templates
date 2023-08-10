@echo off
color F
echo Starting Test

for /l %%x in (1, 1, 1000000) do (
    echo echo|set /p="Testing %%x... "

    gen > in.txt
    main < in.txt > out1.txt
    brute < in.txt > out2.txt
    
    fc out1.txt out2.txt > diagnostics.txt || color C && echo failed! && exit /b
    echo passed!
)
color 2
echo All Tests Passed!!!
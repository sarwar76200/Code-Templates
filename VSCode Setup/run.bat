@echo off
set file_name=%1
set file_name_without_ext=%2


for /f %%i in (build_configuration) do (
    if %%i == release (
        call :release
    ) else (
        call :debug
    )
    call :run_file
    exit /b
)

exit /b

:debug
g++ -std=c++20 -DLOCAL %file_name% -o %file_name_without_ext%
exit /b 0

:release
g++ -std=c++20 -DLOCAL -O2 %file_name% -o %file_name_without_ext%
exit /b 0


:run_file
%file_name_without_ext% < in.txt > out.txt 2>err.txt
exit /b 0







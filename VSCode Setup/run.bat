@echo off
set file_name=%1
set file_name_without_ext=%2

set exit_code=0
set config=null

for /f %%i in (build_configuration) do (
    if %%i == release (
        set %config=release
    ) 
    if %%i == debug (
        set %config=debug
    ) 
)

call :compile
call :run
exit /b %exit_code%

:compile
if %config% == release (
    echo [release] g++ -Wl,--stack,2147483648 -std=c++20 -DLOCAL -O2 %file_name% -o %file_name_without_ext%
    g++ -Wl,--stack,2147483648 -std=c++20 -DLOCAL -O2 %file_name% -o %file_name_without_ext%
)
if %config% == debug (
    echo [debug] g++ -Wl,--stack,2147483648 -Wall -std=c++20 -DLOCAL %file_name% -o %file_name_without_ext%
    g++ -Wl,--stack,2147483648 -Wall -std=c++20 -DLOCAL %file_name% -o %file_name_without_ext%
)
exit /b 0

:run
%file_name_without_ext% < in.txt > out.txt 2>err.txt
set /a exit_code=%ErrorLevel%+0
exit /b 0
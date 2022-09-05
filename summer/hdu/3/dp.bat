@echo off  
:loop  
    rand.exe>data.txt  
    1002std.exe<data.txt>1002std.out  
    1002.exe<data.txt>1002.out  
    fc 1002std.out 1002.out  
if not errorlevel 1 goto loop  
pause  
goto loop
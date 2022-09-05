@echo off  
:loop  
    rand.exe>data.txt  
    1008.exe<data.txt>1008.out  
    1008std.exe<data.txt>1008std.out  
    fc 1008.out 1008std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
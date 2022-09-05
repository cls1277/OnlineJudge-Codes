@echo off  
:loop  
    rand.exe>data.txt  
    1001.exe<data.txt>1001.out  
    1001std.exe<data.txt>1001std.out  
    fc 1001.out 1001std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
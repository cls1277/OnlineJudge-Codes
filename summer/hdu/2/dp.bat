@echo off  
:loop  
    rand.exe>data.txt  
    1011.exe<data.txt>1011.out  
    1011std.exe<data.txt>1011std.out  
    fc 1011.out 1011std.out  
if not errorlevel 1 goto loop  
pause  
goto loop
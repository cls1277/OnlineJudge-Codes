@echo off  
:loop  
    python rand.py
    std.exe<data.txt>std.out  
    G.exe<data.txt>G.out  
    fc std.out G.out  
if not errorlevel 1 goto loop  
pause  
goto loop
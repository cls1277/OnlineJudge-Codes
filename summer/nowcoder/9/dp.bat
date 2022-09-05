@echo off  
:loop  
    python rand.py>data.txt  
    G.exe<data.txt>G.out  
    Gg.exe<data.txt>Gg.out  
    fc G.out Gg.out  
if not errorlevel 1 goto loop  
pause  
goto loop
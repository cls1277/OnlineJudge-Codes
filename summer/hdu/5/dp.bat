@echo off  
:loop  
    rand.exe>data.txt  
    1012__.exe<data.txt>1012__.out  
    1012_.exe<data.txt>1012_.out  
    fc 1012__.out 1012_.out  
if not errorlevel 1 goto loop  
pause  
goto loop
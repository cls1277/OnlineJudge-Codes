@echo off  
:loop  
    rand.exe > data.txt
    A.exe < data.txt > A.txt
    Astd.exe < A.txt > lAstd.txt
    fc lAstd.txt Astd.txt
if not errorlevel 1 goto loop  
pause  
goto loop
@echo off
cd /d "C:\Users\jakub\OneDrive\Desktop\škola\6G\-kola-c-projekty\bashScripts"

rem Get the current date and time
set tdate=%date%
set ttime=%time%

echo To which file do you wish to write current date and time?
set /p file=Enter the file name: 

rem Write date and time to the specified file
echo %tdate% %ttime% >> %file%

echo Time and date saved to %file%
pause

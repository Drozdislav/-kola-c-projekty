@echo off
echo ==========================
echo   Welcome to Git Auto Push
echo   by Jakub Drozd
echo ==========================
echo.
echo Pushing latest changes...

@echo off
setlocal

:: Clean up the time string (remove leading space and colons)
set timestamp=%date% %time%
set timestamp=%timestamp: =0%
set timestamp=%timestamp::=-%

:: Save it to a text file
echo Current date and time: %timestamp% > current_datetime.txt

echo Written to current_datetime.txt: %timestamp%
endlocal

set timestamp=%date% %time%

cd "C:\Users\jakubson\Desktop\skola\IVT\Cprojekty\-kola-c-projekty"

REM Add all changes
git add .

REM Commit with a default message + timestamp

git commit -m "Auto-commit on %timestamp%"

REM Push to the main branch
git push

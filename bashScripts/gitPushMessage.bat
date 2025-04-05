@echo off
echo ==========================
echo   Welcome to Git Auto Push
echo   Message Version
echo   by Jakub Drozd
echo ==========================
echo.
echo Pushing latest changes...

cd "C:\Users\jakubson\Desktop\skola\IVT\Cprojekty\-kola-c-projekty"

REM Add all changes
git add .

REM Ask for commit message
set /p name=What should the message of the commit be? 

REM Commit with the user's message + timestamp
set timestamp=%date% %time%
git commit -m "%name% - %timestamp%"

REM Push to the main branch
git push

pause

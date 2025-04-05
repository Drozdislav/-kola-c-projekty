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

REM Commit with a default message + timestamp
set timestamp=%date% %time%
read name
echo What should the message of the commit be?
git commit -m "name"

REM Push to the main branch
git push

pause

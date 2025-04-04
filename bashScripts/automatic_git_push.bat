@echo off
echo ==========================
echo   Welcome to Git Auto Push
echo   by Jakub Drozd
echo ==========================
echo.
echo Pushing latest changes...

cd "C:\Users\jakubson\Desktop\skola\IVT\Cprojekty\-kola-c-projekty"

REM Add all changes
git add .

REM Commit with a default message + timestamp
set timestamp=%date% %time%
git commit -m "Auto-commit on %timestamp%"

REM Push to the main branch
git push

pause

param (
    [string] $Project, 
    [int] $Run=0
)


if (!$Project) 
{
    Write-Host "[ERROR] Project undefined" -ForegroundColor Red
    break
}


cd $Project

$FILES = Get-Content .\build.ini

g++ $FILES -o "build.exe" 
if ($RUN -eq 1) 
{
    .\build.exe
}

cd ..
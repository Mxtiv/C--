# Self-test of the whole C++ toolbox (NOT needed at the exam). Run: 9_SELF_TESTS\sprawdz_wszystko.bat
#  1. compiles every official task, practice program, building-block file and the start template with g++
#  2. compiles every official task with MSVC (Visual Studio's compiler, default settings) if installed
#  3. runs every official task with scripted keyboard input and checks the output
#  4. builds the two Visual Studio test solutions (MSBuild) and runs their unit tests (vstest)
$ErrorActionPreference = 'Continue'   # native tools write to stderr; PS 5.1 would stop on it
$repo = Split-Path -Parent $PSScriptRoot
$out = Join-Path $env:TEMP 'cpp_toolbox_selftest'
New-Item -ItemType Directory -Force $out | Out-Null
$OutputEncoding = [Text.UTF8Encoding]::new($false)          # text piped INTO the programs = UTF-8
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
$script:ok = 0
$script:bad = 0

function Wynik([bool]$warunek, [string]$opis) {
    if ($warunek) { $script:ok++ } else { $script:bad++; Write-Host "  FAIL $opis" -ForegroundColor Red }
}

# ---------- compilers ----------
$gpp = (Get-Command g++ -ErrorAction SilentlyContinue).Source
if (-not $gpp -and (Test-Path 'C:\msys64\ucrt64\bin\g++.exe')) { $gpp = 'C:\msys64\ucrt64\bin\g++.exe'; $env:PATH = "C:\msys64\ucrt64\bin;$env:PATH" }
if (-not $gpp) { throw 'g++ not found (install MSYS2 ucrt64 or add g++ to PATH)' }
$vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
$vs = if (Test-Path $vswhere) { & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath } else { $null }
Write-Host "g++:  $gpp"
Write-Host "MSVC: $(if ($vs) { $vs } else { 'not found - MSVC checks skipped' })"

function Kompiluj-Gpp([string[]]$pliki, [string]$exe) {
    $log = & $gpp -std=c++17 -Wall -o $exe @pliki 2>&1
    return @{ ok = ($LASTEXITCODE -eq 0); log = ($log | Out-String) }
}

function Kompiluj-Msvc([string[]]$pliki, [string]$exe) {
    $bat = Join-Path $out 'msvc.bat'
    $lista = ($pliki | ForEach-Object { "`"$_`"" }) -join ' '
    "@call `"$vs\VC\Auxiliary\Build\vcvars64.bat`" >nul`r`n@cl /nologo /std:c++17 /EHsc /W3 /Fo`"$out\\`" /Fe`"$exe`" $lista" | Set-Content $bat -Encoding ascii
    $log = & cmd /c $bat 2>&1
    return @{ ok = ($LASTEXITCODE -eq 0); log = ($log | Out-String) }
}

function Uruchom([string]$exe, [string]$wejscie, [string]$folder) {
    # input via a file + cmd redirection: PowerShell 5.1 piping would prepend a BOM to the input
    $plikWejscia = Join-Path $out 'wejscie.txt'
    [IO.File]::WriteAllText($plikWejscia, $wejscie + "`n", [Text.UTF8Encoding]::new($false))
    Push-Location $folder
    try { $wyjscie = (& cmd /c "`"$exe`" < `"$plikWejscia`" 2>&1") | Out-String } finally { Pop-Location }
    return $wyjscie
}

# ---------- 1 + 2: compile ----------
Write-Host "`n== compile =="
$zadania = Get-ChildItem (Join-Path $repo '1_READY_PROGRAMS') -Directory | Where-Object { $_.Name -match '^\d{4}_\d\d_\d\d_' } | Sort-Object Name
$exe = @{}
foreach ($z in $zadania) {
    $sln = Get-ChildItem $z.FullName -Filter *.sln
    if ($sln) {
        $app = Join-Path $z.FullName ([IO.Path]::GetFileNameWithoutExtension($sln[0].Name))
        $pliki = @(Get-ChildItem $app -Filter *.cpp | ForEach-Object { $_.FullName })
    } else {
        $pliki = @(Join-Path $z.FullName 'main.cpp')
    }
    $e = Join-Path $out "$($z.Name).exe"
    $r = Kompiluj-Gpp $pliki $e
    Wynik $r.ok "g++ $($z.Name)`n$($r.log)"
    $exe[$z.Name] = $e
    if ($vs) {
        $r = Kompiluj-Msvc $pliki (Join-Path $out "$($z.Name)_msvc.exe")
        Wynik $r.ok "MSVC $($z.Name)`n$($r.log)"
    }
}
foreach ($p in Get-ChildItem (Join-Path $repo '1_READY_PROGRAMS') -Filter 'practice_*.cpp') {
    $r = Kompiluj-Gpp @($p.FullName) (Join-Path $out ($p.BaseName + '.exe'))
    Wynik $r.ok "g++ $($p.Name)`n$($r.log)"
}
foreach ($b in Get-ChildItem (Join-Path $repo '2_BUILDING_BLOCKS') -Filter '*.cpp') {
    $r = Kompiluj-Gpp @($b.FullName) (Join-Path $out ('blok_' + $b.BaseName + '.exe'))
    Wynik $r.ok "g++ $($b.Name)`n$($r.log)"
}
Write-Host "  compiled: $script:ok ok, $script:bad failed"

# ---------- 3: run the official tasks ----------
Write-Host "`n== run official tasks with test input =="
function Sprawdz([string]$zadanie, [string]$wejscie, [string[]]$oczekiwane, [string[]]$zabronione = @()) {
    $folder = Join-Path $repo "1_READY_PROGRAMS\$zadanie"
    $w = Uruchom $exe[$zadanie] $wejscie $folder
    foreach ($o in $oczekiwane) { Wynik $w.Contains($o) "$zadanie should print '$o'`n--- output:`n$w" }
    foreach ($o in $zabronione) { Wynik (-not $w.Contains($o)) "$zadanie must NOT print '$o'" }
    return $w
}
$n = "`n"
Sprawdz '2021_06_01_sortowanie_przez_wybieranie' "5 3 9 1 7 2 8 4 6 0" @('malejaco: 9 8 7 6 5 4 3 2 1 0') | Out-Null
$w = Sprawdz '2022_06_01_wyszukiwanie_z_wartownikiem' "50" @('Zawartosc tablicy: ')
Wynik ($w -match 'nie ma w tablicy|pod indeksem \d+') 'sentinel: found or not-found message'
Wynik ($w -match 'Zawartosc tablicy: (\d+, ){49}\d+\r?\n') 'sentinel: 50 numbers separated by commas'
Sprawdz '2022_06_02_klasa_osoba_pole_statyczne' "7${n}Anna" @('osob to 0', 'Brak danych', 'Czesc Jan, mam na imie Anna', 'osob to 3') | Out-Null
Sprawdz '2023_01_01_nwd_euklides' "-4${n}48${n}18" @('NWD(48, 18) = 6') | Out-Null
Sprawdz '2023_01_02_klasa_notatka' "" @('2;1;Zakupy;', '2;2;Egzamin') | Out-Null
Sprawdz '2023_06_01_sito_eratostenesa' "" @('2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97') @(' 4 ', ' 9 ', ' 91 ') | Out-Null
Sprawdz '2023_06_02_sortowanie_babelkowe' "" @('Test sortowania: OK') | Out-Null
Sprawdz '2023_06_03_klasa_film' "" @('wypozyczen = 0', 'Zielona mila', 'przed inkrementacja: 0', 'po inkrementacji: 1') | Out-Null
Sprawdz '2024_01_01_pesel' "55030101193" @('Mezczyzna', 'jest zgodna') | Out-Null
Sprawdz '2024_01_01_pesel' "55030101194" @('niezgodna') | Out-Null
Sprawdz '2024_01_02_klasa_narzedzia_string' "Abba;;;to zespol  aaee oo" @('samoglosek: 11', 'Aba;to zespol ae o') | Out-Null
Sprawdz '2024_01_02_klasa_narzedzia_string' "Przyklad  tekstu" @('Przyklad tekstu') | Out-Null
$w = Sprawdz '2024_06_01_gra_w_kosci' "2${n}11${n}3${n}t${n}n" @('Kostka 3:', 'punktow:') @('Kostka 4:')
Wynik (([regex]::Matches($w, 'Ile kostek')).Count -eq 3) 'dice: asks again for 2 and 11, accepts 3'
Wynik (([regex]::Matches($w, 'Kostka 1:')).Count -eq 2) 'dice: "t" rolls again'
Sprawdz '2024_06_02_albumy_z_pliku' "" @('Gorillaz', '"The Now Now"', '1506404300', 'Wczytano albumow: 14') @('-') | Out-Null
Sprawdz '2025_01_01_klasa_tablica_operacje' "5" @('24: ', 'Liczba wartosci nieparzystych:', 'Srednia wartosci:') @('25: ') | Out-Null
$w = Sprawdz '2025_01_02_urzadzenia_dziedziczenie' "5" @('Program zostal ustawiony', 'Odkurzacz wyladowal sie', 'Odkurzacz wylaczono')
Wynik (([regex]::Matches($w, 'Odkurzacz wlaczono')).Count -eq 1) 'vacuum: on() three times -> one message'
Sprawdz '2025_01_02_urzadzenia_dziedziczenie' "13" @('niepoprawny numer programu') | Out-Null
$w = Sprawdz '2025_06_01_loteria' "3" @('Zestaw 3:', '49: ')
$zestawy = $w -split "`n" | Where-Object { $_ -match '^Zestaw \d+:' }
foreach ($z in $zestawy) { $l = @(($z -replace '^Zestaw \d+: ', '').Trim() -split '\s+' | ForEach-Object { [int]$_ }); Wynik ($l.Count -eq 6 -and ($l | Select-Object -Unique).Count -eq 6 -and -not ($l | Where-Object { $_ -lt 1 -or $_ -gt 49 })) "lottery set: $z" }
Sprawdz '2025_06_02_szyfr_cezara' "ala ma kota${n}3" @('dod pd nrwd') | Out-Null
Sprawdz '2025_06_02_szyfr_cezara' "xyz${n}-29" @('uvw') | Out-Null
Sprawdz '2026_01_01_klasa_kosc' "7" @('Wyrzucono: 0 (zero)', 'kosc0.png', 'Liczba utworzonych kosci: 2') | Out-Null
Sprawdz '2026_01_02_quiz_klasa_abstrakcyjna' "Pytanie${n}zad1.jpg${n}A1${n}B1${n}C1${n}B${n}b" @('Odpowiedz prawidlowa') | Out-Null
Sprawdz '2026_01_02_quiz_klasa_abstrakcyjna' "Pytanie${n}zad1.jpg${n}A1${n}B1${n}C1${n}B${n}C" @('Odpowiedz nieprawidlowa') | Out-Null
$w = Sprawdz '2026_06_01_generator_hasel' "" @('Haslo 5: ')
foreach ($linia in ($w -split "`r?`n" | Where-Object { $_ -match '^Haslo \d: ' })) {
    $h = $linia -replace '^Haslo \d: ', ''
    $dobre = $h.Length -eq 12 -and ([regex]::Matches($h, '[a-z]')).Count -eq 3 -and ([regex]::Matches($h, '[A-Z]')).Count -eq 3 -and
          ([regex]::Matches($h, '[ąęłńóśżźĄĘŁŃÓŚŻŹ]')).Count -eq 2 -and ([regex]::Matches($h, '\d')).Count -eq 2 -and ([regex]::Matches($h, '[!@#$%^&*()_+]')).Count -eq 2
    Wynik $dobre "password 3+3+2+2+2: '$h'"
}
Sprawdz '2026_06_02_klasa_notatka_data' "Zakupy" @('Notatka WAZNA! Egzamin', 'Notatka Zakupy', (Get-Date -Format 'dd.MM.yyyy')) | Out-Null

# the abstract class really cannot be instantiated (part III test1 of 26.01-02)
$quiz = Get-Content (Join-Path $repo '1_READY_PROGRAMS\2026_01_02_quiz_klasa_abstrakcyjna\main.cpp') -Raw -Encoding utf8
$proba = Join-Path $out 'quiz_abstract.cpp'
[IO.File]::WriteAllText($proba, $quiz.Replace('    // Pytanie pytanie(', '    Pytanie pytanie('))
$r = Kompiluj-Gpp @($proba) (Join-Path $out 'quiz_abstract.exe')
Wynik ((-not $r.ok) -and $r.log -match 'abstract') 'creating a Pytanie object must be a compile error'

# ---------- 4: Visual Studio solutions + unit tests ----------
if ($vs) {
    Write-Host "`n== Visual Studio solutions + unit tests =="
    $msbuild = Join-Path $vs 'MSBuild\Current\Bin\MSBuild.exe'
    $vstest = Join-Path $vs 'Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe'
    foreach ($sln in Get-ChildItem (Join-Path $repo '1_READY_PROGRAMS') -Recurse -Filter *.sln) {
        & $msbuild $sln.FullName -p:Configuration=Debug -p:Platform=x64 -v:quiet -nologo | Out-Null
        Wynik ($LASTEXITCODE -eq 0) "MSBuild $($sln.Name)"
        $dll = Get-ChildItem (Join-Path $sln.DirectoryName 'x64\Debug') -Filter '*Testy.dll' | Select-Object -First 1
        if ($dll) {
            $t = (& $vstest $dll.FullName 2>&1) | Out-String
            Wynik ($t -match 'Test Run Successful|zakończony powodzeniem') "unit tests $($dll.Name)`n$t"
            if ($t -match '(?:Passed|pomyślnie): +(\d+)') { Write-Host "  $($dll.Name): $($Matches[1]) tests passed" }
        } else { Wynik $false "no test dll for $($sln.Name)" }
        Remove-Item -Recurse -Force (Join-Path $sln.DirectoryName 'x64') -ErrorAction SilentlyContinue
        Get-ChildItem $sln.DirectoryName -Recurse -Directory -Filter x64 | Remove-Item -Recurse -Force -ErrorAction SilentlyContinue
    }
}

Write-Host ''
Write-Host "$script:ok passed, $script:bad failed" -ForegroundColor $(if ($script:bad -eq 0) { 'Green' } else { 'Red' })
exit $(if ($script:bad -eq 0) { 0 } else { 1 })

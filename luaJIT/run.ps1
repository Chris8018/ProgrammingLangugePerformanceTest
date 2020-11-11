# Run Performance test for LuaJIT

# Conversion Function: millisecond to second
function MilliSecToSec {
    param ([double]$MilliSec)
    # Write-Host $MilliSec
    $MilliSec / 1000
}

$iteratorTime = 1


# Test 1
Write-Host "Perform Test 1"

$timeVals1 = 0
for ($i = 0; $i -lt $iteratorTime; $i++) {
    $stopWatch = [System.Diagnostics.Stopwatch]::StartNew()
    luajit.exe -O3 .\test1.lua
    $stopWatch.Stop()
    $timeVals1 += $stopWatch.Elapsed.TotalMilliseconds
}

$time1 = MilliSecToSec ($timeVals1 / $iteratorTime)

Write-Host "Test 1 result: $($time1)s"

# Test 2
Write-Host "Perform Test 2"

$timeVals2 = 0
for ($i = 0; $i -lt $iteratorTime; $i++) {
    $stopWatch = [System.Diagnostics.Stopwatch]::StartNew()
    luajit.exe -O3 .\test2.lua
    $stopWatch.Stop()
    $timeVals2 += $stopWatch.Elapsed.TotalMilliseconds
}

$time2 = MilliSecToSec ($timeVals2 / $iteratorTime)

Write-Host "Test 2 result: $($time2)s"

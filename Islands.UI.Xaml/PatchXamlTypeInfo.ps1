param(
    [Parameter(Mandatory = $true)]
    [string]$Path
)

$text = Get-Content -Raw -LiteralPath $Path
$activationInclude = '#include "XamlTypeInfoActivationIncludes.h"'
$activationIncludePattern = [regex]::Escape($activationInclude)
$undefGetCurrentTime = @'
#ifdef GetCurrentTime
#undef GetCurrentTime
#endif
'@
$undefGetCurrentTimePattern = [regex]::Escape($undefGetCurrentTime)

$text = $text -replace "\r?\n$activationIncludePattern\r?\n", "`r`n"

$anchor = '#include "XamlTypeInfo.xaml.g.h"'
if ($text -match [regex]::Escape($anchor)) {
    $text = $text -replace "($([regex]::Escape($anchor)))", "$activationInclude`r`n`$1"
} else {
    $text = $text -replace '(#include\s+"pch\.h"\s*\r?\n)', "`$1$activationInclude`r`n"
}

Set-Content -LiteralPath $Path -Value $text -NoNewline -Encoding UTF8

$generatedDirectory = Split-Path -Parent $Path
$xamlTypeInfoHeaderPath = Join-Path $generatedDirectory 'XamlTypeInfo.xaml.g.h'
if (Test-Path -LiteralPath $xamlTypeInfoHeaderPath) {
    $headerText = Get-Content -Raw -LiteralPath $xamlTypeInfoHeaderPath

    $headerText = $headerText -replace "\r?\n$undefGetCurrentTimePattern\r?\n", "`r`n"
    $headerText = $headerText -replace '(#include\s+<synchapi\.h>\s*\r?\n)', "`$1`r`n$undefGetCurrentTime`r`n"

    Set-Content -LiteralPath $xamlTypeInfoHeaderPath -Value $headerText -NoNewline -Encoding UTF8
}

$xamlTypeInfoImplPath = Join-Path $generatedDirectory 'XamlTypeInfo.Impl.g.cpp'
if (Test-Path -LiteralPath $xamlTypeInfoImplPath) {
    $implText = Get-Content -Raw -LiteralPath $xamlTypeInfoImplPath

    $implText = $implText -replace "\r?\n$undefGetCurrentTimePattern\r?\n", "`r`n"
    $implText = $implText -replace '(#include\s+<unknwn\.h>\s*\r?\n)', "`$1`r`n$undefGetCurrentTime`r`n"

    Set-Content -LiteralPath $xamlTypeInfoImplPath -Value $implText -NoNewline -Encoding UTF8
}

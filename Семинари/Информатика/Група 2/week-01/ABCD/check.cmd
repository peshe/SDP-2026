@echo off
setlocal enabledelayedexpansion

for /L %%i in (1,1,%2) do (
	%1 < tests\ABCD.%%i.in > tmp.out
	if !errorlevel! NEQ 0 (
		echo Failure !errorlevel!
		color 4
	)
	fc tmp.out tests\ABCD.%%i.sol
	pause
	color
)
del tmp.out

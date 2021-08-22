:: https://wishmesh.com/2009/07/batch-script-to-test-if-folder-directory-is-empty/
:: parameters that will be taken in
:: 1) id of the project (%1)
:: 2) name of the project (%2)
@echo off

:: projects are named in "id_name" style
SET  filename="%1"_%2
SET projectRoot=ProjectSpecificFiles

:delete
cd %projectRoot%\
	rmdir /Q /S %filename%
cd ..

:check
if exist %projectRoot%\ (
	for /F %%i in ('dir /b %projectRoot%') do (
	   goto :eof
	)
	rmdir /Q /S %projectRoot%
)

echo "Project successfully deleted"
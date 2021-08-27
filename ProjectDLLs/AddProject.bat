:: parameters that will be taken
:: 1) id of the project (%1)
:: 2) name of the project (%2)
:: 3) type of project (%3)

@echo off 

:: projects will be named "id_name" to prevent collisions while still being descriptive
SET  filename="%1"_%2
SET projectRoot=ProjectSpecificFiles

:: Check if the project is already in storage 
:: if the folder isnt in storage we can assume that no other files related to it will exist(nothing to collide with)
:: validate that all files and folders are accounted for, if any steps fail goto create, otherwise end  
:add
if not exist %projectRoot%\ (
	mkdir %projectRoot%\
	goto main_file_structure
) 
if not exist %projectRoot%\%filename%\ (
	goto main_file_structure
)

goto :check

:: go through the creation process and at the end check again
:main_file_structure 
:: create directories
cd %projectRoot%\
mkdir %filename%\
mkdir %filename%\sources\
mkdir %filename%\headers\
mkdir %filename%\tests\
cd ..

:: copy in project boilerplate code based on type
xcopy "ProjectSourceBoilerplate.cpp" %projectRoot%\%filename%\sources\
xcopy "ProjectHeaderBoilerplate.h" %projectRoot%\%filename%\headers\


:check 
if not exist %projectRoot%\ (
	echo "%project%\ folder not created properly"
	goto :eof
) 
if not exist %projectRoot%\%filename%\ (
	echo "%projectRoot%\%filename%\ folder not created properly"
	goto :eof
)
if not exist %projectRoot%\%filename%\sources\ (
	echo "%projectRoot%\%filename%\sources\ folder not created properly"
	goto :eof
) 
if not exist %projectRoot%\%filename%\headers\ (
	echo "%projectRoot%\%filename%\headers\ folder not created properly"
	goto :eof
)
if not exist %projectRoot%\%filename%\tests\ (
	echo "%projectRoot%\%filename%\tests\ folder not created properly"
	goto :eof
)

:end
echo "All files created and validated"
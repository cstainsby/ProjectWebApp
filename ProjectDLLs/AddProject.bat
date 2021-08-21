:: parameters that will be taken
:: 1) id of the project
:: 2) name of the project

@echo off 

:: projects will be named "id_name" to prevent collisions while still being descriptive
SET filename = %1_%2
SET projectRoot = ProjectSpecificFiles

:: Check if the project is already in storage 
:: if the folder isnt in storage we can assume that no other files related to it will exist(nothing to collide with)
IF EXIST %projectRoot%/%filename%/ (
	echo "Error, folder already exists"
) ELSE (
	echo "Creating new folder"

	:: setup folder structure for project
	mkdir %projectRoot%\%filename%
	mkdir %projectRoot%\%filename%\%source%
	mkdir %projectRoot%\%filename%\%header%
	mkdir %projectRoot%\%filename%\%test%
)
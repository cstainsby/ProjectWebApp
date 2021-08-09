CREATE TABLE [dbo].[Simulation]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [simName] NVARCHAR(50) NULL, 
    [simDesc] NVARCHAR(MAX) NULL, 
    [gitUrl] NVARCHAR(50) NULL,

)

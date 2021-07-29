CREATE TABLE [dbo].[Simulation]
(
	[SimId] INT NOT NULL PRIMARY KEY IDENTITY, 
    [simName] NVARCHAR(50) NULL, 
    [simDesc] NVARCHAR(MAX) NULL, 
    [gitUrl] NVARCHAR(50) NULL,

)

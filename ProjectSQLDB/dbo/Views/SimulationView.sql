CREATE VIEW [dbo].[SimulationView]
	AS 
	SELECT [s].[Id], [s].[simName], [s].[simDesc], [s].[gitUrl]
	FROM dbo.Simulation s


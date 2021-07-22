CREATE VIEW [dbo].[SimulationView]
	AS 
	SELECT [s].[SimId], [s].[simName], [s].[simDesc], [s].[gitUrl]
	FROM dbo.Simulation s


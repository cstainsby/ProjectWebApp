-- =====================================================================================
-- Author: Cole Stainsby
-- Create Date: 7/21/2021
-- Description: Get all Simulations in the simulation db with given simName
-- =====================================================================================

CREATE PROCEDURE [dbo].[spSimulation_FliterBySimName]
	@simName nvarchar(50)
AS
begin
	SELECT [Id], [simName], [simDesc], [gitUrl]
	FROM dbo.Simulation
	WHERE simName = @simName;
end

RETURN 0

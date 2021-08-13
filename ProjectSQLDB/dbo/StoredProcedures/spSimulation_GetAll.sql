-- =====================================================================================
-- Author: Cole Stainsby
-- Create Date: 7/22/2021
-- Description: Get all Simulations in the simulation db
-- =====================================================================================

CREATE PROCEDURE [dbo].[spSimulation_GetAll]
AS
begin
	SELECT [Id], [simName], [simDesc], [gitUrl]
	from dbo.Simulation;
end

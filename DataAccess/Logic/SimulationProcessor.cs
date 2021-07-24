using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using DataAccess.Data;

namespace DataAccess.Logic
{
    public static class SimulationProcessor
    {
        public static int CreateSimulation(int Id, string simName, string simDesc, string gitURL)
        {
            string sql = @"insert into dbo.Simulation (Id, simName, simDesc, gitURL)
                           values (@Id, @simName, @simDesc, @gitURL);";

            SimulationModel data = new SimulationModel
            {
                Id = Id,
                simName = simName,
                simDesc = simDesc,
                gitURL = gitURL
            };

            return SQLDataAccess.SaveData(sql, data);
        }

        public static List<SimulationModel> LoadSimulations()
        {
            string sql = "Id, simName, simDesc, gitURL from dbo.Simulation;";

            return SQLDataAccess.LoadData<SimulationModel>(sql);
        }
    }
}

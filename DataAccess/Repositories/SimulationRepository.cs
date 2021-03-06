using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using static DataAccess.DataProcessing.Processor; // statically include to use static functions without instantiating object
using Microsoft.Extensions.Configuration;
using System.Data;
using Dapper;

namespace DataAccess.Repositories
{
    internal class SimulationRepository : Repository<SimulationProjectModel>, ISimulationRepository
    {
        // possibly add a copy helper
        public SimulationRepository(IDbTransaction _transaction) : base(_transaction)
        {
            _type = "Simulation";
        }

        // retrieve all items of type SimulationModel within the db 
        public async Task<IEnumerable<SimulationProjectModel>> GetAllAsync()
        {
            string sql = @"SELECT Id, simName, simDesc, gitURL FROM dbo." + _type;

            return await _connection.QueryAsync<SimulationProjectModel>
                (sql,
                transaction: _transaction);
        }

        // create a new item of type SimulationModel within db given Id
        public async Task<int> AddAsync(int Id, string simName, string simDesc, string gitURL, int dimensions)
        {
            SimulationProjectModel entity = processSimulation(
                Id,
                simName,
                simDesc,
                gitURL,
                dimensions
            );

            if (entity == null)
            {
                throw new ArgumentNullException("entity");
            }

            string sql = @"INSERT INTO dbo." + _type + " (simName, simDesc, gitURL) VALUES(@simName, @simDesc, @gitURL);";

            sql = sql.Replace("@simName", $"'{entity.simName}'");
            sql = sql.Replace("@simDesc", $"'{entity.simDesc}'");
            sql = sql.Replace("@gitURL", $"'{entity.gitURL}'");

            int rowsAffected = await _connection.ExecuteAsync
                (sql,
                new { Id = entity.Id, simName = entity.simName, gitURL = entity.gitURL, simDesc = entity.simDesc},
                transaction: _transaction);

            return rowsAffected;
        }
    }
}

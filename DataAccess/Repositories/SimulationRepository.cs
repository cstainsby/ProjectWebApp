using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using Microsoft.Extensions.Configuration;
using System.Data;
using Dapper;

namespace DataAccess.Repositories
{
    internal class SimulationRepository : Repository<SimulationModel>, ISimulationRepository
    {
        // possibly add a copy helper
        public SimulationRepository(IDbTransaction _transaction) : base(_transaction)
        {
            _type = "Simulation";
        }

        // retrieve all items of type SimulationModel within the db 
        public async Task<IEnumerable<SimulationModel>> GetAllAsync()
        {
            string sql = @"SELECT Id, simName, simDesc, gitURL FROM dbo." + _type;

            return await _connection.QueryAsync<SimulationModel>
                (sql,
                transaction: _transaction);
        }

        // create a new item of type SimulationModel within db given Id
        public async Task<int> AddAsync(SimulationModel entity)
        {
            if (entity == null)
            {
                throw new ArgumentNullException("entity");
            }

            string sql = @"INSERT INTO dbo." + _type + "(Id, simName, simDesc, gitURL) VALUES(@Id, @simName, @simDesc, @gitURL);";
            
            return await _connection.ExecuteAsync
                (sql,
                new { Id = entity.Id, simName = entity.simName, gitURL = entity.gitURL, simDesc = entity.simDesc},
                transaction: _transaction);
        }
    }
}

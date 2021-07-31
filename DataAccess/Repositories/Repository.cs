using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.Extensions.Configuration;
using DataAccess.Models;
using DataAccess.Data;
using Dapper;

namespace DataAccess.Repositories
{
    public class Repository
    {
        private readonly IConfiguration configuration;   // configuration object to access db's with
        private string dboContext;                       // designates which dbo to interface with

        public Repository(IConfiguration configuration, string dboContext)
        {
            this.configuration = configuration;
            this.dboContext = dboContext;
        }

        public async Task<SimulationModel> GetById(int Id)
        {
            string sql = "SELECT * FROM dbo," + dboContext + "WHERE Id = @Id";

            SimulationModel searchObj = new SimulationModel { Id = Id };

            return await SQLDataAccess.LoadData<SimulationModel>(configuration.GetConnectionString("ProjectDB"), sql, searchObj);
        }

        // retrieve all items of type T within the db 
        public async Task<IEnumerable<SimulationModel>> GetAllAsync()
        {
            string sql = "SELECT * FROM dbo." + dboContext;

            return await SQLDataAccess.LoadData<SimulationModel>(configuration.GetConnectionString("ProjectDB"), sql);
        }

        // create a new item of type T within db given Id
        public async Task<int> CreateAsync(SimulationModel obj)
        {
            string sql = @"INSERT INTO dbo." + dboContext + "(Id, simName, simDesc, gitURL) VALUES (@Id, @simName, @simDesc, @gitURL);";

            return await SQLDataAccess.EditData<SimulationModel>(configuration.GetConnectionString("ProjectDB"), sql, obj);
        }

        // delete an item of type T within db given Id
        public async Task<int> DeleteAsync(int Id)
        {
            string sql = "DELETE FROM dbo." + dboContext + "WHERE Id = @Id";

            SimulationModel delObj = new SimulationModel { Id = Id };

            return await SQLDataAccess.EditData<SimulationModel>(configuration.GetConnectionString("ProjectDB"), sql, delObj);
        }
    }
}

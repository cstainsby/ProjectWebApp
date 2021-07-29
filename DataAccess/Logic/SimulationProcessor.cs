using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using DataAccess.Data;
using Microsoft.Extensions.Configuration;

namespace DataAccess.Logic
{
    public class SimulationProcessor : IProcessor<SimulationModel>
    {
        private readonly IConfiguration _configuration;

        public SimulationProcessor(IConfiguration configuration)
        {
            _configuration = configuration;
        }

        public async Task<SimulationModel> GetById(int Id)
        {
            string sql = "SELECT * FROM dbo.Simulation WHERE Id = @Id";

            SimulationModel searchObj = new SimulationModel { Id = Id };

            return await SQLDataAccess.LoadData<SimulationModel>(_configuration.GetConnectionString("ProjectDB"), sql, searchObj);
        }

        // retrieve all items of type T within the db 
        public async Task<IEnumerable<SimulationModel>> GetAllAsync()
        {
            string sql = "SELECT * FROM dbo.Simulation";
            var SimEnumerable = await SQLDataAccess.LoadData<SimulationModel>(_configuration.GetConnectionString("ProjectDB"), sql);
            IList<>

            foreach(var item in SimEnumerable)
            {

            }
            return 
        }

        // create a new item of type T within db given Id
        public async Task<int> CreateAsync(SimulationModel obj)
        {
            string sql = @"INSERT INTO dbo.Simulation (Id, simName, simDesc, gitURL) VALUES (@Id, @simName, @simDesc, @gitURL);";

            return await SQLDataAccess.EditData<SimulationModel>(_configuration.GetConnectionString("ProjectDB"), sql, obj);
        }

        // delete an item of type T within db given Id
        public async Task<int> DeleteAsync(int Id)
        {
            string sql = "DELETE FROM dbo.Simulation WHERE Id = @Id";

            SimulationModel delObj = new SimulationModel { Id = Id };

            return await SQLDataAccess.EditData<SimulationModel>(_configuration.GetConnectionString("ProjectDB"), sql, delObj);
        }

        // update an items contents within db given Id
        public async Task<int> UpdateAsync(SimulationModel obj)
        {
            string sql = "UPDATE dbo.Simulation SET simName = @simName, simDesc = @simDesc, gitURL = @gitURL WHERE Id = @Id";

            return await SQLDataAccess.EditData<SimulationModel>(_configuration.GetConnectionString("ProjectDB"), sql, obj);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using DataAccess.Data;
using Microsoft.Extensions.Configuration;

namespace DataAccess.Repositories
{
    public class SimulationRepository : Repository<SimulationModel>, ISimulationRepository
    {
        public SimulationRepository(IConfiguration configuration, string dboContext) : base(configuration, dboContext)
        {
        }

    }
}

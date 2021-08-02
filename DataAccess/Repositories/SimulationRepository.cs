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
        public SimulationRepository(string cnnString, string dboContext) : base(cnnString, dboContext)
        {

        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using Microsoft.Extensions.Configuration;
using System.Data;

namespace DataAccess.Repositories
{
    internal class SimulationRepository : Repository<SimulationModel>, ISimulationRepository
    {
        public SimulationRepository(IDbTransaction _transaction) : base(_transaction)
        {
            _type = "Simulation";
        }
    }
}

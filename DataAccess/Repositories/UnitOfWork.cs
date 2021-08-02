using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DataAccess.Repositories
{
    public class UnitOfWork : IUnitOfWork
    {
        private readonly IConfiguration configuration;

        public UnitOfWork(IConfiguration configuration)
        {
            this.configuration = configuration;
            Simulations = new SimulationRepository(configuration.GetConnectionString("ProjectDB"), "Simulation");
        }

        public ISimulationRepository Simulations { get; private set; }

    }
}

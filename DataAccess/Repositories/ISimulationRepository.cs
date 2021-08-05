using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Threading.Tasks;
using DataAccess.Models;

/*
 * define this interface with generic T holding exclusivley objects
 * This will be implemented by all other processors
 */

namespace DataAccess.Repositories
{
    public interface ISimulationRepository : IRepository<SimulationModel>
    {
        Task<int> AddAsync(SimulationModel entity);
    }
}

using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectWebApp.Models;
using DataAccess.Repositories;   // import unitOfWork repo
using Microsoft.Extensions.Configuration;

namespace ProjectWebApp.Controllers
{
    public class SimulationController : NavController
    {
        public SimulationController(UnitOfWork unitOfWork) : base(unitOfWork)
        {
        }
    }
}

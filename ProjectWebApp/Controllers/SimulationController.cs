using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectWebApp.Models;
using DataAccess;         // import the data access project 
using DataAccess.Repositories;   // and its logic classes
using DataAccess.Models;
using Microsoft.Extensions.Configuration;

namespace ProjectWebApp.Controllers
{
    public class SimulationController : Controller
    {
        private ISimulationRepository simulationRepository;

        public SimulationController()
        {
            // build a configuration to access connection strings
            IConfiguration configuration = new ConfigurationBuilder()
                .AddJsonFile("appsettings.json")
                .Build();

            // using the unit of work object and the connection string store the repo within the Controller
            var unitWork = new UnitOfWork(configuration.GetConnectionString("ProjectDB"));
            simulationRepository = unitWork.SimulationRepo;
        }

        public async Task<IActionResult> Index()
        {
            ViewData["Simulation Data"] = await simulationRepository.GetAllAsync();

            return View();
        }



        // get form
        public IActionResult Create()
        {
            return View();
        }

        // when sending data from the form use this method
        [HttpPost]
        public async Task<IActionResult> Create(Simulation model)
        {
            // prevent spoofing check
            if (ModelState.IsValid)
            {
                SimulationModel data = new SimulationModel
                {
                    Id = model.Id,
                    simName = model.simName,
                    simDesc = model.simDesc,
                    gitURL = model.gitURL
                };

                int result = await simulationRepository.AddAsync(data);
                if(result > 0)
                {
                    return RedirectToAction("Index", "Simulation");
                }
            }

            return StatusCode(500, new { Message = "Error Adding Item" });
        }
    }
}

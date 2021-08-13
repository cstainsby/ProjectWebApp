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
        private UnitOfWork unitOfWork;

        public SimulationController()
        {
            // build a configuration to access connection strings
            IConfiguration cnn = new ConfigurationBuilder()
                .AddJsonFile("appsettings.json")
                .Build();

            unitOfWork = new UnitOfWork(cnn.GetConnectionString("ProjectDB"));
        }

        public async Task<IActionResult> Index()
        {
            ISimulationRepository simRepo = unitOfWork.SimulationRepo;

            ViewData["Simulation Data"] = await simRepo.GetAllAsync();

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
                
                ISimulationRepository simRepo = unitOfWork.SimulationRepo;

                SimulationModel data = new SimulationModel
                {
                    Id = model.Id,
                    simName = model.simName,
                    simDesc = model.simDesc,
                    gitURL = model.gitURL
                };

                int result = await simRepo.AddAsync(data);

                unitOfWork.Save();

                if (result > 0)
                {
                    return RedirectToAction("Index", "Simulation");
                }
            }

            return StatusCode(500, new { Message = "Error Adding Item" });
        }
    }
}

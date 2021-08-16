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

                int result = await simRepo.AddAsync(
                    model.Id, 
                    model.simName,
                    model.simDesc,
                    model.gitURL,
                    model.dimensions
                    );

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
